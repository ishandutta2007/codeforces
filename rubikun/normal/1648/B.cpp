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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,C;cin>>N>>C;
        vector<int> deta(C+1);
        for(int i=0;i<N;i++){
            int x;cin>>x;
            deta[x]=true;
        }
        for(int i=1;i<=C;i++) deta[i]+=deta[i-1];
        
        bool ok=true;
        
        for(ll i=1;i<=C;i++){
            for(ll j=1;i*j<=C;j++){
                ll l=i*j,r=i*(j+1)-1;
                chmin(r,C);
                if(deta[i]-deta[i-1]&&deta[r]-deta[l-1]){
                    ok&=(deta[j]-deta[j-1]);
                }
            }
        }
        
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}