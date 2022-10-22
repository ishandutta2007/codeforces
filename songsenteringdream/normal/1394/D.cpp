#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10;const long long inf=1e18;
int n,a[o],b[o];long long f[o][2];vector<int> e[o],v[o];
void dfs(int nw,int fa){
	int in=0,out=0;long long res=0;
	for(int i=e[nw].size()-1;i+1;--i) if(e[nw][i]^fa){
		dfs(e[nw][i],nw);
		if(a[e[nw][i]]>a[nw]) ++in,res+=f[e[nw][i]][0];
		else if(a[e[nw][i]]<a[nw]) ++out,res+=f[e[nw][i]][1];
		else ++in,res+=f[e[nw][i]][0],v[nw].push_back(f[e[nw][i]][1]-f[e[nw][i]][0]);
	}
	sort(v[nw].begin(),v[nw].end());
	for(int i=0,j=v[nw].size();1;res+=v[nw][i++]){
		f[nw][0]=min(f[nw][0],max(in-i,out+i+(nw>1))*1ll*b[nw]+res);
		f[nw][1]=min(f[nw][1],max(in-i+(nw>1),out+i)*1ll*b[nw]+res);
		if(i==j) break;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),f[i][0]=f[i][1]=inf;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;++i,e[u].push_back(v),e[v].push_back(u)) scanf("%d%d",&u,&v);
	dfs(1,0);
	printf("%lld",min(f[1][0],f[1][1]));
	return 0;
}