#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[100010];
pair<int,pair<int,int> > p[2][100010];
int now[100010][3];
int a0,a1,w,h;
void pr(int i)
{
	if(now[i][0]==1)
		printf("%d %d\n",now[i][1],h);
	else
		printf("%d %d\n",w,now[i][1]);	
}	
int main()
{
	int n;
	cin>>n>>w>>h;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&now[i][0],&now[i][1],&now[i][2]);
		if(now[i][0]==1)
		{
			a0++;
			p[0][a0]=make_pair(now[i][1]-now[i][2],make_pair(now[i][1],i));
			//cout<<i<<' '<<a0<<' '<<p[0][a0].first<<endl;
		}
		else
		{
			a1++;
			p[1][a1]=make_pair(now[i][1]-now[i][2],make_pair(now[i][1],i));
		}
	}
	sort(p[0]+1,p[0]+a0+1);
	sort(p[1]+1,p[1]+a1+1);	
	int b0=0,b1=0;
	while(b0<a0&&b1<a1)
	{
		if(p[0][b0+1].first<p[1][b1+1].first)
		{
			b0++;
			continue;
		}
		else
			if(p[0][b0+1].first>p[1][b1+1].first)
			{
				b1++;
				continue;
			}
		//cout<<b0<<' '<<b1<<' '<<a0<<' '<<a1<<endl;
		int c0=b0+1,c1=b1+1;
		while(c0<a0&&p[0][c0+1].first==p[0][b0+1].first)
			c0++;
		while(c1<a1&&p[1][c1+1].first==p[1][b1+1].first)
			c1++;
		int no=b1+1,x=0;
		//cout<<c0<<' '<<c1<<endl;
		for(int i=c0;i>b0;i--)
		{
			//cout<<p[0][i].second.second<<' '<<p[x^1][no].second.second<<endl;
			num[p[0][i].second.second]=p[x^1][no].second.second;
			if(x==0)
				no++;
			else
				no--;
			if(x==0&&no>c1)
			{
				x=1;
				no=c0;
			}
		}
		for(int i=b1+1;i<=c1;i++)
		{
			num[p[1][i].second.second]=p[x^1][no].second.second;
			if(x==0)
				no++;
			else
				no--;
			if(x==0&&no>c1)
			{
				x=1;
				no=c0;
			}
		}
		b0=c0;
		b1=c1;
	}
	for(int i=1;i<=n;i++)
		if(num[i]==0)
			pr(i);
		else
			pr(num[i]);	
}