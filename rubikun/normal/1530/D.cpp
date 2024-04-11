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
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> X[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];A[i]--;
            X[A[i]].push_back(i);
        }
        
        int K=0;
        
        vector<int> ans(N,-1),used(N);
        for(int i=0;i<N;i++){
            if(si(X[i])){
                used[i]=true;
                K++;
            }
        }
        
        for(int i=0;i<N;i++){
            sort(all(X[i]),[&](int a,int b){
                return used[a]>used[b];
            });
        }
        
        for(int i=0;i<N;i++){
            if(si(X[i])){
                ans[X[i].back()]=i;
                X[i].pop_back();
            }
        }
        
        vector<int> remfrom;
        set<int> remto;
        for(int i=0;i<N;i++){
            if(ans[i]==-1) remfrom.push_back(i);
            if(!used[i]) remto.insert(i);
        }
        
        if(si(remfrom)==1){
            ans[remfrom[0]]=*remto.begin();
        }else if(si(remfrom)>=2){
            for(int i=0;i<si(remfrom)-2;i++){
                auto it=remto.upper_bound(remfrom[i]);
                if(it!=remto.end()){
                    ans[remfrom[i]]=*it;
                    remto.erase(it);
                }else{
                    it--;
                    if(*it==remfrom[i]) it--;
                    ans[remfrom[i]]=*it;
                    remto.erase(it);
                }
            }
            
            int a=remfrom[si(remfrom)-2],b=remfrom[si(remfrom)-1];
            auto it=remto.begin();
            int c=*it;
            it++;
            int d=*it;
            
            if(a!=c&&b!=d){
                ans[a]=c;
                ans[b]=d;
            }else{
                ans[a]=d;
                ans[b]=c;
            }
        }
        
        cout<<K<<"\n";
        
        for(int i=0;i<N;i++){
            cout<<ans[i]+1<<" ";
            X[i].clear();
        }
        cout<<"\n";
    }
}