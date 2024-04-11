// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int maxn=2000005;
int p[maxn];
int sz[maxn];
int cyc[maxn];
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1,cyc[i]=0;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
bool merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2){
    		if(cyc[p1]==0){
    			cyc[p1]=1;
    			return 1;
    		}
    		else{
    			return 0;
    		}
    }
    if(sz[p1] < sz[p2])swap(p1,p2);
    if(cyc[p1] and cyc[p2]){
    		return 0;
    }
    p[p2] = p1;
    sz[p1] += sz[p2];
    cyc[p1] |= cyc[p2];	
    return 1;
}

int solve(){
 		int n; cin >> n;
 		clear();
 		int m; cin >> m;
 		vector<pair<int,pii>>edges;
 		rep(i,0,m){
 			int a,b,w;cin >> a >> b >> w;
 			edges.push_back({-w,{a,b}});
 		}
 		sort(edges.begin(),edges.end());
 		int ans = 0;
 		for(auto i:edges){
 			if(merge(i.y.x,i.y.y)){
 				ans -= i.x;
 			}
 		}
 		cout << ans << endl;
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