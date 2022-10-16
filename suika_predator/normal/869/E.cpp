#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<map>
#include<ctime>

using namespace std;
#define mp make_pair
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
const int MAXN=2555;
int n,m,q;
long long arr[MAXN][MAXN];
map<ppp,int> save;
inline int ran()
{
	return rand()*RAND_MAX+rand();
}
inline int lowbit(int x)
{
	return x&-x;
}
inline void change(int x,int y,int val)
{
	for(int i=x;i<=2510;i+=lowbit(i))
	{
		for(int j=y;j<=2510;j+=lowbit(j))
		{
			arr[i][j]+=val;
		}
	}
}
inline long long query(int x,int y)
{
	long long ret=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		for(int j=y;j>0;j-=lowbit(j))
		{
			ret+=arr[i][j];
		}
	}
	return ret;
}
int main()
{
	srand(time(0));
	scanf("%d%d%d",&n,&m,&q);
	int t,x,y,xx,yy;
	while(q--)
	{
		scanf("%d%d%d%d%d",&t,&x,&y,&xx,&yy);
		if(t==1)
		{
			int tmp=ran();
			save[mp(mp(x,y),mp(xx,yy))] =tmp;
			change(xx,yy,tmp);
			change(x-1,yy,-tmp);
			change(xx,y-1,-tmp);
			change(x-1,y-1,tmp);
		}
		else if(t==2)
		{
			int tmp=save[mp(mp(x,y),mp(xx,yy))];
			change(xx,yy,-tmp);
			change(x-1,yy,tmp);
			change(xx,y-1,tmp);
			change(x-1,y-1,-tmp);
		}
		else
		{
			long long a=query(xx-1,yy-1),b=query(x-1,y-1);
			if(a==b)printf("Yes\n");
			else printf("No\n");
		}
		/*for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				cout<<query(i,j)<<' ';
			}
			cout<<endl;
		}*/
	}
	return 0;
}