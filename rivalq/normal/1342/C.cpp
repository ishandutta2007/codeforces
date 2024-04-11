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
int p[40001];
int func(int a,int b,int r){
    int l=a*b/gcd(a,b);
    if(l>=r){
    	int cnt=p[r];
    	return cnt;
    }
    int k=r-r%l;
    int val=((k-l)/l)*b;
    for(int i=1;i<b;i++)if(i<=r)val++;
    for(int i=k;i<k+b;i++)if(i<=r)val++;
    return r-val;
}
int solve(){
 int a,b,q;cin>>a>>b>>q;
 if(a>b)swap(a,b);
 mem0(p);
 for(int i=1;i<=a*b;i++){
 	if((i%a)%b!=(i%b)%a)p[i]++;
 	p[i]+=p[i-1];
 }
 if(a==b){
 	rep3(q){
 		int t1,t2;cin>>t1>>t2;
 		cout<<0<<" ";
 	}
 }
 else{
 	 rep3(q){
 	 	int l,r;cin>>l>>r;
 	 	int ans=func(a,b,r);
 	 	ans-=func(a,b,l);
 	 	if(l%a!=(l%b)%a)ans++;
 	 	cout<<ans<<" ";
 	 }
 }
 cout<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}