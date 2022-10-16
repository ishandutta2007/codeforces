#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int n,m,l;
char mp[233][233],dir[2333];
int dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1},
	a[4]={0,1,2,3};
int sx,sy,tx,ty;
inline bool inb(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]!='#';
}
inline bool chk()
{
	int xx=sx,yy=sy;
	for(int i=0;i<l;i++)
	{
		if(inb(xx+dx[a[dir[i]-'0']],yy+dy[a[dir[i]-'0']]))
		{
			xx+=dx[a[dir[i]-'0']];
			yy+=dy[a[dir[i]-'0']];
		}
		else return false;
		if(xx==tx&&yy==ty)return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf(" %c",&mp[i][j]);
			if(mp[i][j]=='S')sx=i,sy=j;
			if(mp[i][j]=='E')tx=i,ty=j;
		}
	}
	//cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<endl;
	scanf("%s",dir);
	l=strlen(dir);
	int cnt=0;
	do
	{
		cnt+=chk();
	}while(next_permutation(a,a+4));
	printf("%d\n",cnt);
	return 0;
}