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
long double f(long double x,long double h,long double c,long double t){
	    long double val= (x*h+(x-1)*c);
	    val=val/(2*x-1);
            return  abs(val-t);
}
int ternary_search(int l, int r,long double h,long double c,long double t) {
    int ans=l;            
    while (r-l>1) {
        int mid=(l+r)/2;

        double f1 = f(mid,h,c,t);      
        double f2 = f(mid+1,h,c,t);      
        if (f1 > f2){
            l = mid;
          }  
        else{
            r = mid;
            ans=l;
         }   
    }
    return 2*l+1;                   
}
int solve(){
 	int h,c,t;cin>>h>>c>>t;
 	if(h==t){
              cout<<1<<endl;return 0;
 	}
 	if((h+c)>=2*t){
 		cout<<2<<endl;return 0;
 	}
 	cout<<ternary_search(-1,1e9,h,c,t)<<endl;
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