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

int rui[30][MAX];
vector<int> P[30];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N,Q;cin>>N>>Q;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<30;i++){
            for(int j=0;j<=N;j++) rui[i][j]=0;
            P[i].clear();
        }
        for(int i=0;i<30;i++){
            for(int j=0;j<N;j++){
                rui[i][j+1]=rui[i][j];
                if(A[j]&(1<<i)){
                    rui[i][j+1]++;
                    P[i].push_back(j);
                }
            }
        }
        while(Q--){
            int l,r;cin>>l>>r;
            l--;
            int L=N,R=-1;
            vector<pair<int,int>> S;
            for(int t=0;t<30;t++){
                if(rui[t][r]-rui[t][l]<=1) continue;
                int a=*lower_bound(all(P[t]),l);
                int b=*upper_bound(all(P[t]),a);
                auto it=lower_bound(all(P[t]),r);
                it--;
                int d=*it;
                it--;
                int c=*it;
                if((rui[t][r]-rui[t][l])%2==0){
                    chmin(L,a);
                    chmax(R,d);
                }else{
                    chmin(L,b);
                    chmax(R,c);
                    S.push_back(mp(a,d));
                }
            }
            
            if(L==N){
                cout<<l+1<<" "<<l+1<<"\n";
                continue;
            }
            
            vector<pair<int,int>> T;
            for(auto a:S){
                if(L<=a.fi||a.se<=R){
                    
                }else{
                    T.push_back(a);
                }
            }
            S=T;
            
            if(si(S)==0){
                cout<<L+1<<" "<<R+1<<"\n";
                continue;
            }
            
            sort(all(S));
            
            int mi=INF;
            int ansL=INF,ansR=INF;
            
            for(int i=0;i<=si(S);i++){
                int LL=L;
                for(int j=i;j<si(S);j++) chmin(LL,S[j].fi);
                int RR=R;
                for(int j=0;j<i;j++) chmax(RR,S[j].se);
                if(chmin(mi,RR-LL)){
                    ansL=LL;
                    ansR=RR;
                }
            }
            
            cout<<ansL+1<<" "<<ansR+1<<"\n";
        }
    }
}