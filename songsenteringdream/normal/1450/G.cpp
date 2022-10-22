#include<cstdio>
#include<algorithm>
using namespace std;
const int o=5010;
int n,m,a,b,L[o],R[o],l[1<<20],r[1<<20],mp[o],cnt,c[o],g[1<<20];char s[o],pm[o],ans[o];bool f[1<<20];
int main(){
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	for(int i=1;i<=n;++i) if(!mp[s[i]]) pm[mp[s[i]]=++m]=s[i];
	for(int i=1;i<=m;++i) L[i]=o;
	for(int i=1;i<=n;++i) R[mp[s[i]]]=i,++c[mp[s[i]]];
	for(int i=n;i;--i) L[mp[s[i]]]=i;
	for(int i=1,j;i<(1<<m);++i) for(l[i]=o,r[i]=j=0;j<m;++j)
		if((i>>j)&1) g[i]+=c[j+1],r[i]=max(r[i],R[j+1]),l[i]=min(l[i],L[j+1]);
	for(int i=f[0]=1;i<(1<<m);++i) for(int j=0;j<m;++j){
		if(f[i&((1<<(j+1))-1)]&&f[i^(i&((1<<(j+1))-1))]){f[i]=1;break;}
		if(((i>>j)&1)&&f[i^(1<<j)]) if((r[i]-l[i]+1ll)*a<=b*1ll*g[i]){f[i]=1;break;}
	}
	for(int i=0;i<m;++i) if(f[((1<<m)-1)^(1<<i)]) ans[++cnt]=pm[i+1];
	sort(ans+1,ans+cnt+1);
	printf("%d",cnt);
	for(int i=1;i<=cnt;++i) putchar(' '),putchar(ans[i]);
	return 0;
}