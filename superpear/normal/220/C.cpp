#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=100005;
const int maxlongint=2147483647;

struct two
{
	int num,place;
	bool operator < (const two &b) const
	{
		return num>b.num;
	}
} cs;

priority_queue<two> Qleft,Qright;
int n,ct,move;
int a[maxn],hash[maxn],where[maxn];

two make_pear(int x,int y)
{
	two cs;
	cs.num=x;cs.place=y;
	return cs;
}

int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&ct);
		hash[ct]=i;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&ct);
		a[i]=hash[ct];
	}
	//for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
	for (int i=1;i<=n;i++)
	{
		if (i<=a[i])
		{
			where[a[i]]=1;
			Qleft.push(make_pear(a[i]-i,a[i]));
		}
		else
		{
			where[a[i]]=2;
			Qright.push(make_pear(i-a[i],a[i]));
		}
	}
	Qleft.push(make_pear(maxlongint/2,0));
	Qright.push(make_pear(maxlongint/2,0));
	move=0;
	for (int i=1;i<=n;i++)
	{
		while (where[Qleft.top().place]==2) Qleft.pop();
		while (where[Qright.top().place]==1) Qright.pop();
		printf("%d\n",min(Qleft.top().num+move,Qright.top().num-move));
		while (Qright.top().num==move)
		{
			cs=Qright.top();
			if (where[cs.place]==2)
			{
				where[cs.place]=1;
				cs.num=-move;
				Qleft.push(cs);
			}
			Qright.pop();
		}
		++move;
		where[a[i]]=2;
		cs.num=n-a[i]+move;
		cs.place=a[i];
		Qright.push(cs);
	}
	
	return 0;
}