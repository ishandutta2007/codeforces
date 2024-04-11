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

const int N = 1e5+5;

vector<int>ans[2];

vector<int>g[N];

int d[N],par[N],vis[N];
int k,need;

void dfs(int u,int p,bool f){
	for(auto i:g[u]){
		if(i!=p){
			dfs(i,u,f^1);
		}
	}
	ans[f].pb(u);
}


void dfs2(int u,int p){
	vis[u]=1;
	par[u]=p;
	d[u]=d[p]+1;
	int mx_dep=-1,j=-1;
	for(auto i:g[u]){
		if(i==p)continue;
		if(vis[i] && d[i]<d[u]){
			if(d[i]>mx_dep){
				mx_dep=d[i],j=i;
			}
		}
	}
	if(mx_dep>0){
			vector<int>t;
			int x=u;
			int len=d[u]-d[j]+1;
			while(true){
				t.pb(x);
				if(x==j)break;
				x=par[x];
			}
			if(len<=k){
				cout<<2<<endl;
				cout<<sz(t)<<endl;
				for(auto i:t)cout<<i<<" ";cout<<endl;
			}
			else{
				cout<<1<<endl;
				for(int i=0;need--;i+=2){
					cout<<t[i]<<" ";
				}cout<<endl;
			}
			exit(0);
	}
	for(auto i:g[u]){
		if(!vis[i])dfs2(i,u);
	}
}

int solve(){
 		int n,m;cin>>n>>m>>k;
 		need=(k+1)/2;
 		rep(i,0,m){
 			int u,v;cin>>u>>v;
 			g[u].pb(v);
 			g[v].pb(u);
 		}
 		if(m==n-1){
 			dfs(1,1,0);
 			cout<<1<<endl;
 			if(sz(ans[0])<need)swap(ans[0],ans[1]);
 			for(int i=0;i<need;i++)cout<<ans[0][i]<<" ";cout<<endl;
 			return 0;	
 		}
 		dfs2(1,1);
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