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
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
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
 		int n,q; cin >> n >> q;
 		vector<int>last(21,n+1);
 		vector<int>a(n+1);
 		vector<vector<int>>dp(n+2,vector<int>(21,n+1));
 		rep(i,1,n+1){
 			cin >> a[i];
 		}
 		for(int i = n; i >= 1; i--){
 			for(int j = 0; j <= 20; j++){
 				for(int k = 0; k <= 20; k++){
 					if((1 << k)&a[i]){
 						mins(dp[i][j],dp[last[k]][j]);
 					}
 				}
 				if((1 << j)&a[i]){
 					dp[i][j] = i;
 				}
 			}
 			for(int j = 0; j <= 20; j++){
 				if((1 << j)&a[i]){
 					last[j] = i;
 				}
 			}
 		}
 		
 		rep(i,0,q){
 			int x,y; cin >> x >> y;
 			bool ok = 0;
 			for(int j = 0; j <= 20; j++){
 				if((1 << j)&a[y]){
 					if(dp[x][j] <= y)ok = 1;
 				}
 			}
 			cout << (ok?"Shi":"Fou") << endl;
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