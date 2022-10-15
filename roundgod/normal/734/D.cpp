#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x0,y0;
int dis[8],type[8];
int main()
{
	scanf("%d%d%d",&n,&x0,&y0);
	getchar();
	memset(type,0,sizeof(type));
	for(int i=0;i<8;i++) dis[i]=2*INF+1;
	for(int i=0;i<n;i++)
	{
		char ch;
		int x,y;
		scanf("%c%d%d",&ch,&x,&y);
		getchar();
		x-=x0;y-=y0;
		int tp;
		if(ch=='B') tp=1; else if(ch=='R') tp=2; else tp=3;
		if(x==0)
		{
			int d=max(y,-y);
			if(y>0)
			{
				if(d<dis[0]) {dis[0]=d; type[0]=tp;}
			}
			else
			{
				if(d<dis[1]) {dis[1]=d; type[1]=tp;}
			}
		}
		else if(y==0)
		{
			int d=max(x,-x);
			if(x>0)
			{
				if(d<dis[2]) {dis[2]=d; type[2]=tp;}
			}
			else
			{
				if(d<dis[3]) {dis[3]=d; type[3]=tp;}
			}
		}
		else if(x==y)
		{
			int d=max(y,-y);
			if(y>0)
			{
				if(d<dis[4]) {dis[4]=d; type[4]=tp;}
			}
			else
			{
				if(d<dis[5]) {dis[5]=d; type[5]=tp;}
			}
		}
		else if(x+y==0)
		{
			int d=max(y,-y);
			if(y>0)
			{
				if(d<dis[6]) {dis[6]=d; type[6]=tp;}
			}
			else
			{
				if(d<dis[7]) {dis[7]=d; type[7]=tp;}
			}
		}
	}
	for(int i=0;i<4;i++)
		if(type[i]==2||type[i]==3) {puts("YES"); return 0;}
	for(int i=4;i<8;i++)
		if(type[i]==1||type[i]==3) {puts("YES"); return 0;}
	puts("NO");
	return 0;
}