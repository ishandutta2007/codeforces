#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

vector<int> pos[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        for(int i=0;i<N;i++){
            pos[i].clear();
        }
        vector<int> A(N),use;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        use=A;
        sort(all(use));
        use.erase(unique(all(use)),use.end());
        
        for(int i=0;i<N;i++){
            A[i]=lower_bound(all(use),A[i])-use.begin();
            pos[A[i]].push_back(i);
        }
        
        vector<pair<int,int>> B(M);
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;a--;b--;
            B[i]=mp(a,b);
        }
        sort(all(B),[](auto a,auto b){
            if(a.fi==b.fi) return a.se>b.se;
            return a.fi<b.fi;
        });
        
        vector<pair<int,int>> C;
        for(auto x:B){
            if(C.empty()) C.push_back(x);
            else if(C.back().fi<x.fi&&C.back().se<x.se) C.push_back(x);
        }
        
        B=C;
        M=si(B);
        
        //for(auto a:B) cout<<a.fi<<" "<<a.se<<endl;
        
        int ans=INF;
        
        int K=si(use);
        vector<int> la(K,-1);
        
        int L=-1,R=-1;
        
        for(int i=0;i<N;i++){
            if(la[A[i]]==-1){
                la[A[i]]=i;
                continue;
            }
            auto it=lower_bound(all(B),mp(la[A[i]],INF));
            if(it==B.begin()){
                la[A[i]]=i;
                continue;
            }
            it--;
            //cout<<i<<" "<<la[A[i]]<<" "<<(*it).fi<<" "<<(*it).se<<endl;
            if(i<=(*it).se){
                L=i;
                break;
            }
            la[A[i]]=i;
        }
        
        for(int i=0;i<K;i++) la[i]=INF;
        
        for(int i=N-1;i>=0;i--){
            if(la[A[i]]==INF){
                la[A[i]]=i;
                continue;
            }
            auto it=lower_bound(all(B),mp(i,INF));
            if(it==B.begin()){
                la[A[i]]=i;
                continue;
            }
            it--;
            if(la[A[i]]<=(*it).se){
                R=i;
                break;
            }
            la[A[i]]=i;
        }
        
        //for(int a:A) cout<<a<<" ";
        //cout<<endl;
        //cout<<L<<" "<<R<<endl;
        
        if(L==-1){
            cout<<0<<"\n";
            continue;
        }
        
        for(int i=0;i<=L;i++){
            chmin(ans,R-i+1);
            
            auto it=lower_bound(all(B),mp(i,INF));
            if(it==B.begin()) continue;
            it--;
            int x=A[i],r=(*it).se;
            auto it2=lower_bound(all(pos[x]),r+1);
            it2--;
            chmax(R,(*it2));
            
        }
        
        chmax(ans,0);
        
        cout<<ans<<"\n";
    }
}