#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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
int dp[100005][400];
int a[100005];
int zeno(int i,int k,int n){
    if(i>n)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    dp[i][k]=1+zeno(i+a[i]+k,k,n);
    return dp[i][k];
}
int solve(){
 int n;cin>>n;
 rep(i,1,n+1){
 	cin>>a[i];
 }
 mem1(dp);
 int bl=sqrt(n);
 int q;cin>>q;
 rep3(q){
 	int p,k;cin>>p>>k;
 	if(k>bl){
 		int moves=0;
 		while(p<=n){
 			p=p+a[p]+k;
 			moves++;
 		}
 		cout<<moves<<endl;
 	}
 	else cout<<zeno(p,k,n)<<endl;
 }
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