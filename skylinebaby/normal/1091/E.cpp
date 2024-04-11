#include<bits/stdc++.h>
using namespace std;
#define int long long
struct P{
	int tg, mx;
};
P st[2123456];
int a[512345];
int b[512345];
int c[512345];
long long d[512345];
long long BIT[1012345];
long long BIT2[1012345];
int need[512345];
int lowbit(int x)
{
	return x&(-x);
}
void add(int i,int z)
{
	while(i>0)
	{
		if (i>=1000001)
		{
			break;
		}
		BIT[i]+=z;
		i+=lowbit (i);
	}
}
int get(int i)
{
	long long total=0;
	while (i>0)
	{
		total+=BIT[i];
		i-=lowbit(i);
	}
	return total;
}
void add2(int i,int z)
{
	while(i>0)
	{
		if (i>=1000001)
		{
			break;
		}
		BIT2[i]+=z;
		i+=lowbit (i);
	}
}
int get2(int i)
{
	long long total=0;
	while (i>0)
	{
		total+=BIT2[i];
		i-=lowbit(i);
	}
	return total;
}
void update (int k)
{
	st[k].mx = min(st[k<<1].mx,st[k<<1|1].mx);
}
void build (int L,int R,int k)
{
	st[k].tg = 0;
	if (L==R)
	{
		st[k].mx = a[L];
		return ;
	}
	int mid = L + R >> 1;
	build(L,mid,k<<1);
	build(mid+1,R,k<<1|1);
	update(k);
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
void deb(int n)
{
	for(int i = 1;i<=n;i++) printf("%d %d\n",i,query(1,n,1,i,i));
}
main()
{
	int n;
	scanf("%lld",&n);
	int t = 0;
	int k = 0;
	for(int i = 1;i<=n;i++)
	{
		scanf("%lld",&b[i-k]);
		t = (t+b[i-k])%2;
		if(!b[i-k]) k++;
		else c[b[i-k]]++;
	}
	n = n - k;
	if(n==0)
	{
		printf("0\n");
		return 0;
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	//for(int i = 1;i<=n;i++) printf("%d %d\n",b[i],c[i]);
	
	for(int i = 1;i<=n;i++)
	{
		add(i,c[i]);
		add2(i,i*c[i]);
	}
	//for(int i = 1;i<=n;i++) printf("%lld %lld\n",get(i),get2(i));
	d[1] = (long long)b[1];
	for(int i = 2;i<=n;i++) d[i] = d[i-1] + b[i]; 
	a[1] = n - 1 - c[0] - b[1];
	add(b[1],-1);
	add2(b[1],-b[1]);
	for(int i = 2;i<=n;i++)
	{
		add(b[i],-1);
		add2(b[i],-b[i]);
		long long x = get(i-1);
		long long y = get2(i-1);
		//printf("%lld %lld\n",x,y);
		a[i] = i*(i-1) + i*(n-i-x) + y - d[i];
	}
	//for(int i = 1;i<=n;i++) printf("%d\n",a[i]);
	build(1,n,1);
	for(int i = 0;i<=n;i++) need[i] = -1;
	int pos = 0;
	if(!(t%2)&&query(1,n,1,1,n)>=0) need[pos++] = 0;
	for(int i = 1;i<=n;i++)
	{
		modify(1,n,1,i+c[b[i]]-1,n,1);
		//deb(n);
		if(i+c[b[i]]-1>b[i]) modify(1,n,1,b[i],i+c[b[i]]-2,-1);
		//deb(n);
		c[b[i]]-=2;
		if(!((i-t)%2)&&query(1,n,1,1,n)>=0) need[pos++] = i;		
	}
	if(need[0]==-1) 
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 0;i<pos;i++)
	{
		printf("%lld ",need[i]);
	}
	printf("\n");
	return 0;
}