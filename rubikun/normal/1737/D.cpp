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
const int mod=998244353,MAX=505;
const ll INF=1LL<<60;

ll dis[MAX][MAX];
ll cn[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dis[i][j]=INF;
                cn[i][j]=INF;
            }
            dis[i][i]=0;
            cn[i][i]=0;
        }
        ll ans=INF;
        vector<vector<ll>> E(M);
        for(int i=0;i<M;i++){
            int a,b;ll c;
            cin>>a>>b>>c;
            a--;b--;
            chmin(dis[a][b],c);
            chmin(dis[b][a],c);
            chmin(cn[a][b],1LL);
            chmin(cn[b][a],1LL);
            E[i]={a,b,c};
        }
        
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    chmin(dis[i][j],dis[i][k]+dis[k][j]);
                    chmin(cn[i][j],cn[i][k]+cn[k][j]);
                }
            }
        }
        
        chmin(ans,dis[0][N-1]);
        
        for(int t=0;t<M;t++){
            int a=E[t][0],b=E[t][1];
            ll c=E[t][2];
            chmin(ans,c*(cn[0][a]+cn[N-1][b]+1));
            chmin(ans,c*(cn[0][b]+cn[N-1][a]+1));
            for(int k=0;k<N;k++){
                chmin(ans,c*(cn[k][a]+(k!=b)+cn[k][0]+cn[k][N-1]+1));
                chmin(ans,c*(cn[k][b]+(k!=a)+cn[k][0]+cn[k][N-1]+1));
            }
            //cout<<a<<" "<<b<<" "<<c<<endl;
        }
        
        //for(int i=0;i<N;i++) cout<<cn[0][i]<<" "<<cn[1][i]<<endl;
        
        cout<<ans<<"\n";
    }
}