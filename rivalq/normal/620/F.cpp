#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

int pre[1000005];
int ans[5005];
int a[50005];
int b[50005];
int dp[50005];
vector<pii> q;
int solve(){
 int n,m;cin>>n>>m;
 rep3(n)cin>>a[i+1];
 for(int i=1;i<=1000000;i++)pre[i]=pre[i-1]^i;
 rep(i,1,n+1)b[i]=pre[a[i]];
 q.resize(m);
 rep3(m)cin>>q[i];
 for(int i=1;i<=n;i++){
    int mx=0;
    for(int j=i;j<=n;j++){
       int val=b[j]^b[i];
       if(a[i]>a[j])val^=a[j];
       else val^=a[i];
       maxs(mx,val);
       dp[j]=mx;
    }
    for(int j=0;j<m;j++){
        if(q[j].x<=i && i<=q[j].y)maxs(ans[j],dp[q[j].y]);
    }
 }
 for(int i=0;i<m;i++)cout<<ans[i]<<"\n";
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}