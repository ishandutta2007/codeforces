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
long double pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n;cin>>n;
 	vector<int>x(n+1),y(n+1);
 	vector<pair<long double,int>>v;
 	rep(i,1,n+1){
 		cin>>x[i]>>y[i];
 	}
        auto f=[&](int x,int y){
             return atan2l(y,x);
        };
        rep(i,1,n+1){
        	v.pb({f(x[i],y[i]),i});
        }
        sort(all(v));
        v.pb({2*pi+(*v.begin()).x,v.begin()->y});
        long double a=4;
        int k1=1,k2=2;
        for(int i=1;i<=n;i++){
        	if(a>v[i].x-v[i-1].x){
        		a=v[i].x-v[i-1].x;
        		k1=v[i].y;
        		k2=v[i-1].y;
        	}
        }
        cout<<k1<<" "<<k2<<endl;
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