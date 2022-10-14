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
vector<int>v;
int a,r,m,n;
int f(int x,int n){
     int n1=0;
	 int n2=0;
	 for(int i=1;i<=n;i++)n1+=max(0LL,x-v[i]);
	 for(int i=1;i<=n;i++)n2+=max(0LL,v[i]-x);
	 return a*n1+r*n2-(a+r)*(min(n1,n2))+min(a+r,m)*min(n1,n2);
}
int ternary_search(int l, int r){
    while (l<=r) {
    	int ans=hell;
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = f(m1,n); 
        int f2 = f(m2,n);
        if (f1 > f2){
            l = m1+1;
            ans=f2;
        }
        else{
            r = m2-1;
            ans=f1;
        }
    }
    return f(l,n);                
}
bool ch(int x,int n){
	 int n1=0;
	 int n2=0;
	 for(int i=1;i<=n;i++)n1+=max(0LL,x-v[i]);
	 for(int i=1;i<=n;i++)n2+=max(0LL,v[i]-x);
	 return n1<=n2;	
}
int solve(){
 cin>>n>>a>>r>>m;
 v.resize(n+1);
 int mi=hell,mx=0;
 rep(i,1,n+1)cin>>v[i],mins(mi,v[i]),maxs(mx,v[i]);
 int ans=0;
 int s=0;
 if(mi==mx){
 	cout<<0<<endl;return 0;
 }
 for(int i=1;i<=n;i++){
    ans+=r*(v[i]-mi);
 }
 for(int i=1;i<=n;i++){
 	s+=a*(mx-v[i]);
 }
 mins(ans,s);
 int l=mi;
 int u=mx;
 int change=0;
 while(l<=u){
 	int m=(l+u)/2;
 	if(ch(m,n))change=m,l=m+1;
 	else u=m-1;
 }
 ans=mins(ans,ternary_search(mi,mx));
 //ans=mins(ans,ternary_search(change,mx));
 cout<<ans<<endl;
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