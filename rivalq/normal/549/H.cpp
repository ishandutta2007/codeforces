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

#define double long double
const double eps=1e-9;

int solve(){
 		double a1,a2,a3,a4;cin>>a1>>a2>>a3>>a4;
 		double l=0,r=1e10;
 		double ans=1e10;
 		auto f=[&](double x){
 			double b11=a1+x;double b12=a1-x;
 			double b21=a2+x;double b22=a2-x;
 			double b31=a3+x;double b32=a3-x;
 			double b41=a4+x;double b42=a4-x;
 			double mx1=max({b11*b41,b11*b42,b12*b41,b12*b42});
 			double mn1=min({b11*b41,b11*b42,b12*b41,b12*b42});
 			double mx2=max({b21*b31,b21*b32,b22*b31,b22*b32});
 			double mn2=min({b21*b31,b21*b32,b22*b31,b22*b32});
 			return max(mn1,mn2)<=min(mx2,mx1);
 		};
 		while((r-l)>eps){
 			double m=(r+l)/2;
 			if(f(m)){
 				ans=m;
 				r=m;
 			}
 			else{
 				l=m;
 			}
 		}
 		cout<<fixed<<setprecision(10)<<ans<<endl;
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