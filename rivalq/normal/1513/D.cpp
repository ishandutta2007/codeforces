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

const int maxn = 2e5+5;
int p[maxn];
int sz[maxn];
int cnt = 0;
void clear(int n){
    rep(i,0,n+1)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    cnt--;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}


int solve(){
 		int n,p; cin >> n >> p;
 		clear(n);
 		cnt = n;
 		vector<int>a(n+1);
 		vector<pii>vec;
 		rep(i,1,n+1){
 			cin >> a[i];
 			vec.push_back({a[i],i});
 		}
 		sort(all(vec));
 		int ans = 0;
 		for(auto [w,i]:vec){
 				if(w >= p){
 					break;
 				}
 				int l = i + 1;
 				while(l <= n and a[l]%w == 0 ){
 					if(root(i) == root(l)){
 						break;
 					}
 					ans += w;
 					merge(l,i);
 					l++;
 				}
 				l = i - 1;
 				while(l >= 1 and a[l]%w == 0){
 					if(root(i) == root(l)){
 						break;
 					}
 					ans += w;
 					merge(l,i);
 					l--;
 				}
 		}
 		cout << ans + (cnt-1)*p << endl;
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