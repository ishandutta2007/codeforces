#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,x,y,z,val,ans;
int f[1005][2][35][35][35];

int trans(int x){return x>m?m+1:1;}
void add(int &a,int b){a+=b;if(a>=1000000009)a-=1000000009;}
void update(int a,int b,int c,int d)
{
	if(a>m)a=m+1;if(b>m)b=m+1;if(c>m)c=m+1;if(d>m)d=m+1;
	if(d<c)swap(c,d);if(c<b)swap(b,c);if(b<a)swap(a,b);
	if(a==1)add(f[i+1][0][b][c][d],val);
	else add(f[i+1][1][a][b][c],val);
}

int main()
{
	scanf("%d%d",&n,&m);
	f[0][0][1][1][1]=1;
	for(i=0;i<n;++i)
	for(x=1;x<=m+1;++x)
	for(y=x;y<=m+1;++y)
	for(z=y;z<=m+1;++z)
	{
		if(f[i][0][x][y][z])
		{
			val=f[i][0][x][y][z];
			update(1,x+1,y+1,z+1);
			update(2,trans(x),y+1,z+1);
			update(2,x+1,trans(y),z+1);
			update(2,x+1,y+1,trans(z));
		}
		if(f[i][1][x][y][z])
		{
			val=f[i][1][x][y][z];
			update(trans(x),y+1,z+1,m+1);
			update(x+1,trans(y),z+1,m+1);
			update(x+1,y+1,trans(z),m+1);
			update(x+1,y+1,z+1,m+1);
		}
	}
	ans=0;
	for(i=0;i<=1;++i)
	for(x=1;x<=m+1;++x)
	for(y=1;y<=m+1;++y)
	for(z=1;z<=m+1;++z)
	if(i==0||x<=m||y<=m||z<=m)
	add(ans,f[n][i][x][y][z]);
	printf("%d\n",ans);
}