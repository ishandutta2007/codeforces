#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
using namespace std;
int n,m;
char sta[55][55];
char dest[55][55];
char final[55][55];
#define mp make_pair
deque<pair<int,int>> tmp,tmp2;
void turn(int x,int y)
{
	//cout<<"TURN "<<x<<' '<<y<<endl;
	if(sta[x][y]=='R')
	{
		turn(x,y-1);
		return;
	}
	if(sta[x][y]=='D')
	{
		turn(x-1,y);
		return;
	}
	if(sta[x][y]=='U')
	{
		if(sta[x][y+1]=='D')turn(x-1,y+1);
		if(sta[x+1][y+1]=='U')turn(x+1,y+1);
		if(sta[x][y+1]=='L')turn(x,y+1);
		tmp.push_back(mp(x,y));
		sta[x][y]=sta[x+1][y]='L';
		sta[x][y+1]=sta[x+1][y+1]='R';
		return;
	}
	if(sta[x][y]=='L')
	{
		if(sta[x+1][y]=='R')turn(x+1,y-1);
		if(sta[x+1][y+1]=='L')turn(x+1,y+1);
		if(sta[x+1][y]=='U')turn(x+1,y);
		tmp.push_back(mp(x,y));
		sta[x][y]=sta[x][y+1]='U';
		sta[x+1][y]=sta[x+1][y+1]='D';
		return;
	}
}
void turn2(int x,int y)
{
	//cout<<"TURN2 "<<x<<' '<<y<<endl;
	if(dest[x][y]=='R')
	{
		turn2(x,y-1);
		return;
	}
	if(dest[x][y]=='D')
	{
		turn2(x-1,y);
		return;
	}
	if(dest[x][y]=='U')
	{
		if(dest[x][y+1]=='D')turn2(x-1,y+1);
		if(dest[x+1][y+1]=='U')turn2(x+1,y+1);
		if(dest[x][y+1]=='L')turn2(x,y+1);
		tmp2.push_front(mp(x,y));
		dest[x][y]=dest[x+1][y]='L';
		dest[x][y+1]=dest[x+1][y+1]='R';
		return;
	}
	if(dest[x][y]=='L')
	{
		if(dest[x+1][y]=='R')turn2(x+1,y-1);
		if(dest[x+1][y+1]=='L')turn2(x+1,y+1);
		if(dest[x+1][y]=='U')turn2(x+1,y);
		tmp2.push_front(mp(x,y));
		dest[x][y]=dest[x][y+1]='U';
		dest[x+1][y]=dest[x+1][y+1]='D';
		return;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n%2==0)
	{
		for(int i=1;i<=n;i+=2)
		{
			for(int j=1;j<=m;j++)
			{
				final[i][j]='U';
				final[i+1][j]='D';
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j+=2)
			{
				final[i][j]='L';
				final[i][j+1]='R';
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",sta[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",dest[i]+1);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if((sta[i][j]=='L'||sta[i][j]=='U')&&sta[i][j]!=final[i][j])turn(i,j);
			if((dest[i][j]=='L'||dest[i][j]=='U')&&dest[i][j]!=final[i][j])turn2(i,j);
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<sta[i][j];
		}
		cout<<endl;
	}*/
	int siz=tmp.size()+tmp2.size();
	printf("%d\n",siz);
	while(!tmp.empty())
	{
		printf("%d %d\n",tmp.front().first,tmp.front().second);
		tmp.pop_front();
	}
	while(!tmp2.empty())
	{
		printf("%d %d\n",tmp2.front().first,tmp2.front().second);
		tmp2.pop_front();
	}
	return 0;
}