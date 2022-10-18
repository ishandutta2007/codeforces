#include<bits/stdc++.h>
using namespace std;
struct P{
	int tg,mx;
};
P st[512345];
void update (int k)
{
	st[k].mx = min(st[k<<1].mx,st[k<<1|1].mx);
}
void push(int k)
{
	if (st[k].tg)
	{
		st[k<<1].mx += st[k].tg;
		st[k<<1].tg += st[k].tg;
		st[k<<1|1].mx += st[k].tg;
		st[k<<1|1].tg += st[k].tg;
	}
	st[k].tg = 0;
}
void modify(int L,int R,int k,int x,int y,int z)
{
	if (x<=L&&y>=R)
	{
		st[k].mx += z;
		st[k].tg += z;
		return ;
	}
	int mid = L + R >> 1;
	push(k);
	if (x<=mid) modify(L,mid,k<<1,x,y,z);
	if (y> mid) modify(mid+1,R,k<<1|1,x,y,z);
	update (k);
}
int query(int L,int R,int k,int x,int y)
{
	if (x<=L&&y>=R) return st[k].mx;
	int mid = L + R >> 1;
	int ans = 1000000;
	push(k);
	if (x<=mid) ans = min(ans,query(L,mid,k<<1,x,y));
	if (y> mid) ans = min(ans,query(mid+1,R,k<<1|1,x,y));
	return ans;
} 
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int now = 0;
	for(int i = 0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		modify(1,n,1,x,x,1);
		int z = query(1,n,1,1,n);
		if(z==now) printf("0");
		else printf("1");
		now = max(now,z);
	}
	printf("\n");
	return 0;
}