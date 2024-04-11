#include <stdio.h>
#include <string.h>
#include <queue>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
char gc()
{
	char c=getchar();
	while(c!='.'&&(c<65||c>'Z')&&c!='s')c=getchar();
	return c=='s'?2:c!='.';
}
int a[3][1001];
inline int min(int a,int b)
{
	return a<b?b:a;
}
int mem[3][105];
inline int emp(int i,int c)
{
	return a[i][c+1]==0&&a[i][c+2]==0;
}
int dfs(int i,int c,int n)
{
	//printf("DFSing %d %d %d\n",i,c,n);
	if(a[i][c]||a[i][c+1])return 0;
	if(c>=n+1)return 1;
	if(mem[i][c]!=-1)return mem[i][c];
	mem[i][c]=0;
	if(emp(i,c)&&dfs(i,c+3,n))return mem[i][c]=1;
	if(i>0&&emp(i-1,c)&&a[i-1][c+1]==0&&dfs(i-1,c+3,n))return mem[i][c]=1;
	if(i<2&&emp(i+1,c)&&a[i+1][c+1]==0&&dfs(i+1,c+3,n))return mem[i][c]=1;
	return 0;
}
int main()
{
	int T=read();
	while(T--)
	{
		memset(mem,-1,sizeof(mem));
		memset(a,0,sizeof(a));
		int n=read(),sx,sy;int u=read();
		for(int i=0;i<3;i++)
			for(int j=0;j<n;j++)
			{
				a[i][j]=gc();
				if(a[i][j]==2)sx=i,sy=j,a[i][j]=0;
			}
		if(dfs(sx,sy,n))puts("YES");
		else puts("NO");
		
		//for(int i=0;i<3;i++,puts(""))
		//	for(int j=0;j<n;j++)printf("%c",mem[i][j]==-1?' ':mem[i][j]+48);
	}
}
/*
3
70 4
s..........BB.AAAA....................................................
..............................................................CCCC....
..........................................DD..........................
31 11
...........CCCCC.II...KKDDD....
......HHHH...........FFFF..AAAA
s..JJJ.....GGGGBB..EEE.........
22 3
s...........CC...AA...
.........BBB..........
......................
*/