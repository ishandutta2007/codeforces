#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=200005;
int ne[N],num,fi[N],x,y,zz[N],n,m,in[N],dfn[N],flag[N];
void jb(int x,int y)
{
	ne[++num]=fi[x];
	fi[x]=num;
	zz[num]=y;
}
void dfs(int x)
{
	flag[x]=1;
	for (int i=fi[x];i;i=ne[i])
	 {
	 	if (flag[zz[i]])continue;
	 	dfn[zz[i]]--;
	 	if (dfn[zz[i]]<=0)dfs(zz[i]);
	 }
}
int pd()
{
	for (int i=1;i<=n;i++)
	 if (dfn[i]<=0&&!flag[i])dfs(i);
	for (int i=1;i<=n;i++)
	 if (!flag[i])return 0;
	return 1;  
}
int main()
{
	scanf("%d%d",&n,&m);
	while (m--)
	 {
	 	scanf("%d%d",&x,&y);
		jb(x,y);in[y]++;
	 }
	for (int i=1;i<=n;i++)
	 {
	 	for (int j=1;j<=n;j++)dfn[j]=in[j];
	 	for (int j=1;j<=n;j++)flag[j]=0;
	 	dfn[i]--;
	 	if (pd())
	 	 {
	 	 	puts("YES");
	 	 	return 0;
	 	 }
	 } 
	puts("NO"); 
}