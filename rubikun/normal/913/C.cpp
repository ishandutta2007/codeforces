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
const int mod=998244353,MAX=5005,INF=1<<28;
ll N,L;
ll c[MAX];
ll ans=1LL<<60;

void solve(int u,ll rem,ll sum){
    if(u==0){
        chmin(ans,sum+rem*c[0]);
        return;
    }
    ll x=rem/(1LL<<u);
    solve(u-1,rem-(1LL<<u)*x,sum+c[u]*x);
    chmin(ans,sum+(x+1)*c[u]);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>L;
    for(int i=0;i<N;i++) cin>>c[i];
    for(int i=1;i<N;i++) chmin(c[i],c[i-1]*2);
    solve(N-1,L,0);
    cout<<ans<<endl;
}