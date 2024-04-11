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
int solve(){
 int n,m,q;cin>>n>>m>>q;
 vector<int>b(m+1);
 int sum=0;
 rep(i,1,n+1){
    int t;cin>>t;
    if(i%2==0)t*=-1;
    sum+=t;
 }
 rep(i,1,m+1){
 	cin>>b[i];
 	if(i%2)b[i]*=-1;
 }
 set<int>st;
 int s=0;
 for(int i=1;i<=n;i++)s+=b[i];	
 st.insert(s);	
 for(int i=2;i+n-1<=m;i++){
    s-=b[i-1];
    s+=b[i+n-1];
    if(i%2){
    	st.insert(s);
    }
    else{
    	st.insert(-s);
    }
 }
 vector<int>v;
 for(auto i:st)v.pb(i);
 auto query = [&](int x){
      int val1=1e18;
      int idx=lower_bound(all(v),-x)-v.begin();
      if(idx<sz(st))val1=abs(v[idx]+x);
      if(idx-1>=0)mins(val1,abs(v[idx-1]+x));
      return val1;
 };
 int a=sum;
 cout<<query(a)<<endl;
 rep3(q){
 	int l,r,x;cin>>l>>r>>x;
 	if(l%2==r%2){
      int val=x;
      if(l%2==0)val*=-1;
      sum+=val;
 	}
 	int a=sum;
 	cout<<query(a)<<endl;
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