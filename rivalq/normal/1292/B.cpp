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
const int maxn=1e18;

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 int x0,y0,ax,bx,ay,by;cin>>x0>>y0>>ax>>ay>>bx>>by;
 int xs,ys,t;cin>>xs>>ys>>t;
 vector<pii>points;
 points.eb(x0,y0);
 while(1){
 	if((maxn-bx)/ax>=points.back().x && (maxn-by)/ay>=points.back().y){
 	    int nx=ax*points.back().x+bx;
 	    int ny=ay*points.back().y+by;
 	    points.eb(nx,ny);
 	}    
 	else break;
 }
 int ans=0;
 for(int i=0;i<sz(points);i++){
 	for(int j=i;j<sz(points);j++){
 		int left=abs(points[i].x-xs)+abs(points[i].y-ys);
 		int right=abs(points[j].x-xs)+abs(points[j].y-ys);
 		int total=points[j].x-points[i].x+points[j].y-points[i].y;
 		if(total+right<=t || total+left<=t)maxs(ans,j-i+1);
 	}
 }
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