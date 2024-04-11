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
const int mod=998244353,MAX=10005;
const ll INF=1LL<<62;

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll p1,p2,t1,t2;
    cin>>p1>>t1;
    cin>>p2>>t2;
    ll h,s;cin>>h>>s;
    
    for(int j=0;j<MAX;j++) dp[j]=INF;
    
    dp[0]=0;
    
    vector<pair<ll,ll>> que;
    que.push_back(mp(t1,min(h,p1-s)));
    que.push_back(mp(t2,min(h,p2-s)));
    
    for(ll a=1;;a++){
        ll T=t1*a;
        ll can=T/t2;
        for(ll b=can;b<=can+1;b++){
            if(b==0) continue;
            T=max(t1*a,t2*b);
            ll D=p1*a+p2*b-s*(a+b-1);
            chmin(D,h);
            que.push_back(mp(T,D));
        }
        
        if(a*(p1-s)>=h) break;
    }
    
    for(auto [t,d]:que){
        //cout<<t<<" "<<d<<endl;
        for(int i=d;i<=2*h;i++){
            chmin(dp[i],dp[i-d]+t);
        }
    }
    
    ll ans=INF;
    
    for(int i=h;i<=2*h;i++) chmin(ans,dp[i]);
    
    cout<<ans<<endl;
    
}