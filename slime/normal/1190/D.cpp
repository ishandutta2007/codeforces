#include <bits/stdc++.h>
#define maxn 200005
#define sq 355
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
struct pt
{
	int x, y;
	bool operator < (const pt & u)const
	{
		if(y != u.y) return y < u.y;
		return x < u.x;
	}
}p[maxn];
map<int, int> id; 
int u[maxn];
int ns[maxn];
int d[maxn];
int lb(int x)
{
	return x & -x;
}
void ins(int pl, int num)
{
	while(pl < maxn)
		d[pl] += num, 
		pl += lb(pl);
}
int cal(int pl)
{
	int ans = 0;
	while(pl)
		ans += d[pl],
		pl -= lb(pl);
	return ans;
}
int nr[maxn];
ll calc(int a)
{
	return 1ll * a * (a + 1) / 2;
}
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y), 
		u[i] = p[i].x;
	sort(p + 1, p + n + 1), 
	sort(u + 1, u + n + 1);
	int idcnt = 0;
	for(int i = 1; i <= n; i++)
		if(i == 1 || u[i] != u[i - 1])
			idcnt++, 
			id[u[i]] = idcnt;
	for(int i = 1; i <= n; i++)
		p[i].x = id[p[i].x], 
		ns[p[i].x]++;
	for(int i = 1; i <= idcnt; i++)
		if(ns[i]) ins(i, 1);
//	cout<<"AF"<<endl;
	ll ans = 0;
	for(int i = 1; i <= n; )
	{
		int j = i;
		while(j <= n && p[j].y == p[i].y) j++;
		for(int k = i; k < j; k++)
			nr[k] = cal(p[k].x - 1);
		nr[j] = cal(idcnt);
		ll tot = calc(nr[j]);
		for(int k = j; k > i; k--)
			nr[k] -= (nr[k - 1] + 1);
		for(int k = i; k <= j; k++)
			tot -= calc(nr[k]);
		ans += tot;
		for(int k = i; k < j; k++)
		{
			ns[p[k].x]--;
			if(!ns[p[k].x])	
				ins(p[k].x, -1);
		}
		i = j;
	}
	cout<<ans<<endl;
	return 0;
} 
/*
2 1 1 5

 
*/