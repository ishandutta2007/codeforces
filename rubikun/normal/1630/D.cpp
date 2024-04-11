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
const int mod=998244353,MAX=1000005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

vector<ll> S[MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<ll> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        ll g=0;
        for(int i=0;i<M;i++){
            int x;cin>>x;
            g=gcd(g,x);
        }
        
        for(int i=0;i<g;i++){
            S[i].clear();
        }
        for(int i=0;i<N;i++){
            S[i%g].push_back(A[i]);
        }
        for(int i=0;i<g;i++){
            sort(all(S[i]));
        }
        
        ll ans=-(1LL<<60);
        
        for(int f=0;f<2;f++){
            ll res=0;
            for(int i=0;i<g;i++){
                ll mi=1LL<<60,sum=0;
                for(int j=0;j<=si(S[i]);j++){
                    if((j&1)==f) chmin(mi,sum);
                    if(j==si(S[i])) break;
                    sum+=S[i][j];
                }
                res+=sum-mi-mi;
            }
            chmax(ans,res);
        }
        
        cout<<ans<<"\n";
    }
}