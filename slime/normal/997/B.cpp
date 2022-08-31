#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 300005
#define ll long long
#define mod 1000000007 
using namespace std;
struct th
{
	ll l, r;
	bool operator < (const th &a)const
	{
		return l < a.l; 
	}
};
struct cal
{
	th n1[2000];
	int ncnt;
	cal()
	{
		ncnt = 0;
	}
	void push(th x)
	{
		if(x.l > x.r) return;
	//	cout<<"PUSH"<<x.l<<" "<<x.r<<endl;
		n1[ncnt++] = x;
	}
	ll calc()
	{
		ll ext = -100;
		if(!ncnt) return 0;
		sort(n1, n1 + ncnt);
		ll ans = 0;
		for(int i = 0; i < ncnt; i++)
		{	
//		/	cout<<i<<" "<<n1[i].r<<" "<<ext<<endl;
			if(n1[i].r <= ext) continue;
			ans += (n1[i].r - max(ext + 40, n1[i].l)) / 40 + 1;
		
			ext = n1[i].r;
		}
		return ans;
	}
}q[40];
int bg[4];
int sm[4] = {1, 5, 10, 50};
int n;
void push()
{
	int ns = 0, x[2] = {0, 0};
	int ntot = 0;
	ll sum = 0;
	for(int i = 0; i < 4; i++)
	{
		if(bg[i] == -1) x[ntot++] = i;
		else ns += bg[i], sum += bg[i] * sm[i];
	}
	if(ns > n) return ;
	ll dv = abs(sm[x[0]] - sm[x[1]]), mns = sum + (n - ns) * (ll)sm[x[0]], bgs = sum + (n - ns) * (ll)sm[x[1]];
//	cout<<ns<<" "<<n<<" "<<x[0]<<" "<<x[1]<<" "<<mns<<" "<<bgs<<endl;
	if(mns > bgs) swap(mns, bgs);
	for(ll i = mns; i != mns + 40 && i <= bgs; i += dv)
	{
		th n1;
		n1.l = i, n1.r = bgs;
		ll nr = bgs;
		if(nr % 40 != i % 40)
		{
			bool fl = 0;
			if(nr % 40 > i % 40) fl = 1;
			nr -= nr % 40;
			if(!fl) nr -= 40;
			nr += i % 40;
		}
		n1.r = nr;
		q[i % 40].push(n1);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i <= 5; i++)
		for(int j = 0; j <= 8; j++)
		{
			memset(bg, -1, sizeof(bg));
			bg[0] = i, bg[1] = j;
			push();
		}
	for(int i = 0; i <= 4; i++)
	{
		memset(bg, -1, sizeof(bg));
		bg[2] = i, bg[3] = 0;
		push();
	}
	for(int i = 0; i <= 5; i++)
	{
		memset(bg, -1, sizeof(bg));
		bg[0] = i, bg[3] = 0;
		push();
	}
	ll ans = 0;
	for(int i = 0; i < 40; i++)
		ans += q[i].calc();
	printf("%lld\n", ans);
	return 0;
}