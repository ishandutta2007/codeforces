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


int solve(){
 		int n;cin>>n;
 		vector<vector<int>>g(n+1);
 		rep(i,2,n+1){
 			int p;cin>>p;
 			g[p].push_back(i);
 			g[i].push_back(p);
 		}
 		vector<int>mx(n+1,0),mn(n+1,hell);
 		vector<int>a(n+1,1),d(n+1,1),vis(n+1,0),dp(n+1,-1e18);
 		vector<vector<int>>vec(n+1);
 		int mx_d=1;
 		rep(i,2,n+1){
 			cin>>a[i];
 		}
 		vector<int>q={1};
 		for(int i=0;i<sz(q);i++){
 			int v=q[i];
 			vis[v]=1;
 			mins(mn[d[v]],a[v]);
 			maxs(mx[d[v]],a[v]);
 			mx_d=d[v];
 			vec[d[v]].push_back(v);
 			for(auto j:g[v]){
 				if(!vis[j]){
 					d[j]=d[v]+1;
 					vis[j]=1;
 					q.push_back(j);
 				}
 			}
 		}
 		auto cmp=[&](pii p1,pii p2){
 			return a[p1.x]<a[p2.x];
 		};
 		for(int i=mx_d;i>=1;i--){
 			vector<pii>p,q;
 			for(auto j:vec[i]){
 				int res=0;
 				for(auto k:g[j]){
 					maxs(res,dp[k]);
 				}
 				p.push_back({j,res+a[j]});
 				q.push_back({j,res-a[j]});
 				dp[j] = res + max(mx[i]-a[j],a[j]-mn[i]);
 			}
 			sort(all(p),cmp);reverse(all(p));
 			sort(all(q),cmp);int res=-1e18;
 			for(auto j:p){
 				maxs(res,j.y);
 				maxs(dp[j.x],-a[j.x]+res);
 			}
 			res=-1e18;
 			for(auto j:q){
 				maxs(res,j.y);
 				maxs(dp[j.x],a[j.x]+res);
 			}
 		}
 		cout<<dp[1]<<endl;
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