#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99,S=100,M=7,inf=2e9+99;

int n,m,ans=inf,a[N][M],b[N][M],e[N];
vector<int> bad;
bitset<N> def,adj,mv[N*M/S];
map<int,vector<int>> mark;
vector<int> vec1,vec2,v[N*M];

bool cmp(int i,int j){
	return b[i][m]<b[j][m];
}
void read(){
	vector<int> p;
	cin>>n>>m;
	f(i,0,n){
		p.pb(i);
		f(j,0,m+1) cin>>b[i][j];
	}
	sort(all(p),cmp);
	f(i,0,n){
		f(j,0,m+1){
			a[i][j]=b[p[i]][j];
		}
	}
}
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read();
	f(i,0,n){
		int bd=0;
		f(j,0,m){
			mark[a[i][j]].pb(i);
		}
		f(j,0,m){
			//cout<<a[i][j]<<" ";
			f(k,0,j){
				if(a[i][j]==a[i][k]){
					bd=1;
				}
			}
		}
		//cout<<endl;
		if(bd==1){
			def[i]=1;
		}
	}
	for(auto e : mark){
		vector<int> vec=e.S;
		if(vec.size()<S){
			for(auto x : vec) v[vec1.size()].pb(x);
			vec1.pb(e.F);
		}
		else{
			for(auto x : vec) mv[vec2.size()][x]=1;
			vec2.pb(e.F);
		}
	}
	f(i,0,n){
		if(def[i]) continue ;
		adj=def;
		adj[i]=1;
		f(j,0,m){
			int x=a[i][j];
			if(mark[x].size()<S){
				int pos=lower_bound(all(vec1),x)-vec1.begin();
				for(auto u : v[pos]){
					adj[u]=1;
				}
			}
			else{
				int pos=lower_bound(all(vec2),x)-vec2.begin();
				adj|=mv[pos];
			}
		}
		//cout<<i<<" : ";
		//f(j,0,n) cout<<adj[j]<<" "; cout<<endl;
		adj.flip();
		int pos=adj._Find_first();
		if(pos<n){
			minm(ans,a[i][m]+a[pos][m]);
		}
	}
	cout<<(ans==inf ? -1 : ans);
}