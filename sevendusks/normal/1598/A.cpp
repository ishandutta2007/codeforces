/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=110;
int T,n,vi[2][N];
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,-1,1,1,-1};
char s[2][N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x,int y)
{
	vi[x][y]=1;
	for (int i=0;i<8;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if (tx<0||tx>=2||ty<1||ty>n||s[tx][ty]=='1'||vi[tx][ty]) continue;
		dfs(tx,ty);
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		scanf("%s%s",s[0]+1,s[1]+1);
		memset(vi,0,sizeof(vi));
		dfs(0,1);
		if (vi[1][n]) printf("Yes\n");
		else printf("No\n");
	}
}