#include<bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
const int mod=1e9+7;
using ll=long long;
using std::cin;
using std::cout;
int n, k;
int s0, s1;
int x[100], y[100], w[100];
int a[100][100];
int fa[110];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
std::vector<int> v0, v1;

inline std::vector<int>mul(std::vector<int>v0,std::vector<int>v1){
	std::vector<int>res(v0.size()+v1.size()-1);
	for(int i=0;i<(int)v0.size();++i)
	for(int j=0;j<(int)v1.size();++j)
		res[i+j]=(res[i+j]+(ll)v0[i]*v1[j])%mod;
	return res;
}
namespace gf {
	int edge[100][100],T[100][100];
	int mem[2][1<<25],*f=mem[0],*g=mem[1];
	inline int popc(int x) { return __builtin_popcount(x); }
	inline std::vector<int>count(int n,int m){
		if(n<m) {
			std::swap(edge,T),std::swap(n,m);
			for(int i=0;i<n;++i)for(int j=0;j<m;++j)edge[i][j]=T[j][i];
		}
		memset(f,0,4<<m);
		*f=1;
		int S=0;
		for(int i=0;i<n;++i){
			memcpy(g,f,4<<m);
			for(int j=0;j<m;++j) if(edge[i][j]) {
				S|=1<<j;
				for(int s=S^1<<j,k=s;;k=k-1&s){
					g[k|1<<j]=(g[k|1<<j]+(ll)f[k]*edge[i][j])%mod;
					if(!k)break;
				}
			}
			std::swap(f,g);
		}
		std::vector<ll>res(m+1);
		for(int i=0;i<1<<m;++i) res[popc(i)]+=f[i];
		for(ll&i:res)i%=mod;
		return std::vector<int>(res.begin(),res.end());
	}
}
int fac[100100];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	*fac=1;
	for(int i=1;i<=n;++i)fac[i]=(ll)fac[i-1]*i%mod;
	for(int i = 0;i < k;++i) {
		cin >> x[i] >> y[i] >> w[i];
		if(--w[i]==-1)w[i]+=mod;
		v0.pb(x[i]), v1.pb(y[i]);
	}
	sort(all(v0)),v0.erase(unique(all(v0)),v0.end()),s0=v0.size();
	sort(all(v1)),v1.erase(unique(all(v1)),v1.end()),s1=v1.size();
	// if(s0<s1)swap(v0,v1),std::swap(x,y),std::swap(s0,s1);
	for(int i=0;i<s0+s1;++i)fa[i]=i;
	for(int i = 0;i < k;++i) {
		x[i]=lower_bound(all(v0),x[i])-v0.begin();
		y[i]=lower_bound(all(v1),y[i])-v1.begin();
		a[x[i]][y[i]]=w[i];
		fa[find(x[i])]=find(y[i]+s0);
	}
	std::vector<int>ans(1,1);
	for(int x=0;x<s0+s1;++x)if(fa[x]==x){
		std::vector<int> v0, v1;
		for(int i=0;i<s0;++i)if(find(i)==x)v0.pb(i);
		for(int i=0;i<s1;++i)if(find(i+s0)==x)v1.pb(i);
		memset(gf::edge,0,sizeof(gf::edge));
		for(int i=0;i<(int)v0.size();++i)
		for(int j=0;j<(int)v1.size();++j) gf::edge[i][j]=a[v0[i]][v1[j]];
		ans=mul(ans,gf::count(v0.size(),v1.size()));
	}
	int res=0;
	for(int i=0;i<ans.size();++i)res=(res+(ll)ans[i]*fac[n-i])%mod;
	cout<<res<<'\n';
}