#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+99;

int n,m,q,res,a[N],par[N],mark[N],h[N],cnt[N],w[N];
vector<int> g[N];
vector<int> ans[N];

void dfs(int x){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			h[g[x][i]]=h[x]+1;
			par[g[x][i]]=x;
			dfs(g[x][i]);
		}
	}
}
void dfs2(int x){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			dfs2(g[x][i]);
			cnt[x]^=cnt[g[x][i]];
		}
	}
	if(cnt[x]) res++;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	cin>>q;
	f(i,0,q){
		int u,v;
		cin>>u>>v;
		vector<int> v1,v2;
		while(u!=v){
			if(h[u]>=h[v]){
				cnt[u]^=1;
				v1.pb(u);
				u=par[u];
			}
			else{
				cnt[v]^=1;
				v2.pb(v);
				v=par[v];
			}
		}
		v1.pb(u);
		f_(j,v2.size()-1,0){
			v1.pb(v2[j]);
		}
		ans[i]=v1;
	}
	int mv=0;
	f(i,1,n+1)
		if(cnt[i]&1)
			mv=1;
	if(mv==0){
		cout<<"YES"<<endl;
		f(i,0,q){
			cout<<ans[i].size()<<endl;
			f(j,0,ans[i].size()) cout<<ans[i][j]<<" "; cout<<endl;
		}
		return 0;
	}
	cout<<"NO"<<endl;
	fill(mark,mark+N,0);
	f(i,1,n+1)
		if(cnt[i]){
			w[i]^=1;
			w[par[i]]^=1;
		}
	f(i,2,n+1){
		res+=w[i];
	}
	cout<<(res+1)/2;
}