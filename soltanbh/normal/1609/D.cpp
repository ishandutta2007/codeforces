#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=3300;

int n,m,p,mx=1,e,a[N],par[N];

int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(u==v){
		e++;
		return ;
	}
	p++;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	maxm(mx,-par[u]);
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(par,par+N,-1);
	cin>>n>>m;
	f(i,1,m+1){
		int u,v;
		cin>>u>>v;
		merge(u,v);
		vector<int> V;
		f(i,1,n+1){
			if(par[i]<0){
				V.pb(-par[i]);
			}
		}
		sort(V.begin(),V.end());
		reverse(V.begin(),V.end());
		int ans=V[0]-1;
		int sz=V.size();
		f(i,1,min(sz,e+1)){
			ans+=V[i];
		}
		cout<<ans<<endl;
	}
}