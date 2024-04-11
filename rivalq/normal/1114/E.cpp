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
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());


int solve(){
 int n;cin>>n;
 int l=0;
 int u=1e9;
 int ans;
 int tot=60;
 while(l<=u){
 	int m=(l+u)/2;
 	cout<<"> "<<m<<endl<<flush;
 	tot--;
 	int r;cin>>r;
 	if(r)l=m+1;
 	else ans=m,u=m-1;
 }
 vector<int>v;
 v.pb(ans);
 int k=min(n,tot);
 set<int>st;
 while(k--){
 	int idx=rng32()%n+1;
 	while(st.count(idx)){
         idx=rng32()%n+1;
 	}
 	st.insert(idx);
 	cout<<"? "<<idx<<endl<<flush;
 	int r;cin>>r;
 	v.pb(r);
 }
 int d=0;
 for(int i=0;i<sz(v);i++){
 	for(int j=i+1;j<sz(v);j++)d=gcd(d,abs(v[i]-v[j]));
 }
 int a=ans-(n-1)*d;
 cout<<"! "<<a<<" "<<d<<endl<<flush;
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