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

const int maxn = (1<<18);
int p[maxn];
int sz[maxn];
int cnt[maxn];
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=-1;
}
int root(int x){
   if(p[x] < 0){
       return x;
   }
   else{
       return p[x] = root(p[x]);
   }
}
int merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return 0;
    if(p[p1] > p[p2])swap(p1,p2);
    int res = 1;
    if(p[p1] == -1) res += cnt[p1]-1;
    if(p[p2] == -1) res += cnt[p2]-1;
    p[p1] += p[p2];
    p[p2] = p1;
    return res;
}


int solve(){
 		int n;cin>>n;
 		clear();
 		int ans = 0;
 		for(int i = 1; i <= n ; i++){
 			int a;cin >> a;
 			cnt[a]++;
 			ans -= a;
 		}
 		cnt[0]++;
 		int m = (1<<18);
 		m--;
 		for(int i = m ; i >=0 ;i--){
 			for(int s = i;s; s = (s-1)&i){
 				int u = s;
 				int v = s^i;
 				if(cnt[u] and cnt[v]){
 					ans += i*merge(u,v);
 				}
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