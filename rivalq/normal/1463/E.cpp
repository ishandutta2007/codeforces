#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
//#define int            long long
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

const int N = 3e5+5;

set<int>g[N];
int out[N];
int p[N];
int sz[N];
int t[N];
vector<int>pre[N];
vector<int>aux;
int vis[N];

void clear(){
    rep(i,0,N)p[i]=i,sz[i]=1;
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
   	assert(p1==x || p2==y);
   	if(out[p1])swap(p1,p2);
   	p[p2]=p1;
}

void dfs2(int u){
	vis[u]=1;
	for(auto i:g[u]){
		if(vis[i]==1){
			cout<<"0\n";exit(0);
		}
		else if(vis[i]==0)dfs2(i);
	}
	vis[u]=2;
	aux.pb(u);
}

void dfs(int u){
	for(auto i:g[u]){
		t[i]=t[u]+1;
		dfs(i);
	}
}

int solve(){
 	int n,k;cin>>n>>k;
 	vector<int>p(n+1);
 	rep(i,1,n+1){
 		cin>>p[i];
 	}
 	clear();
 	rep(i,0,k){
 		int a,b;cin>>a>>b;
 		out[a]++;
 		g[b].insert(a);
 		if(root(a)==root(b)){
 			cout<<"0\n";exit(0);
 		}
 		merge(a,b);
 	}
 	vector<int>roots;
 	rep(i,1,n+1){
 		if(root(i)==i){
 			assert(out[i]==0);
 			dfs(i);
 			roots.pb(i);
 		}
 		pre[root(i)].pb(i);
 	}
 	rep(i,1,n+1){
 		g[i].clear();
 	}

 	rep(i,1,n+1){
 		if(p[i]){
 			if(root(i)==root(p[i])){
 				if(t[p[i]]<t[i]){
 					cout<<"0\n";exit(0);
 				}
 			}
 			else{
 				g[root(p[i])].insert(root(i));
 			}
 		}
 	}
 	for(auto i:roots){
 		if(!vis[i]){
 			dfs2(i);

 		}
 	}
 	while(!aux.empty()){
 		int r=aux.back();aux.pop_back();
 		sort(pre[r].begin(),pre[r].end(),[&](int x,int y){
 			return t[x]>t[y];
 		});
 		for(auto i:pre[r])cout<<i<<" ";
 	}cout<<endl;
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