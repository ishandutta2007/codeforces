#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int gi()
{
	char c=getchar(); int x=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return x;
}
const int N=1e5+5,M=1e6+5;
struct edge {
	int id,u,v,w;
} tmp[M],e[M];
int f[N],n,m;
bool operator < (edge x, edge y) {
	if(x.w==y.w) return x.id<y.id;
	return x.w<y.w;
}
int findset(int x) {
	if(f[x]==x) return x;
	return f[x]=findset(f[x]);
}
bool check(int x)
{
	memcpy(e,tmp,sizeof(tmp));
	e[1].w=x;
	sort(e+1,e+1+m);
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1,j=1;j<n;++i)
	{
		int fu=findset(e[i].u),fv=findset(e[i].v);
		if(fu==fv)
		{
			if(e[i].id==1) return false;
			continue;
		}
		++j,f[fu]=fv;
		if(e[i].id==1) return true;
	}
	return false;
}
int main()
{
	n=gi(),m=gi();
	for(int i=1;i<=m;++i)
	{
		int u=gi(),v=gi(),w=gi();
		tmp[i]=(edge){i,u,v,w};
	}
	int l=0,r=1e9;
	while(l<=r)
	{
		int mid=l+r>>1;
		check(mid)?l=mid+1:r=mid-1;
	}
	printf("%d",min(1000000000,l-1));
}