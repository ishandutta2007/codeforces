#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define maxn 100005
#define ll long long
#define ld double
using namespace std;
int n, w;
struct fs
{
	ll a, b;
	void otp(){cout<<a<<" "<<b<<endl;}
	bool operator < (const fs &x)const
	{
		return a * x.b < b * x.a;
	}
}p[maxn];
map <fs, int>cal;
int st[2][maxn], top[2];
int x[maxn], v[maxn];

int id[2][maxn];

int d[maxn];
int lb(int x)
{
	return x & (-x);
}
void ch(int pl, int num)
{
	while(pl < maxn)
		d[pl] += num, pl += lb(pl);
}
int q(int pl)
{
	int ans = 0;
	while(pl)
		ans += d[pl], pl -= lb(pl);
	return ans;
}
struct th2
{
	int a, b;
	bool operator < (const th2 &x)const
	{
		if(a != x.a) return a < x.a;
		return b < x.b;
	}
}p2[maxn];
int main()
{
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &v[i]);
	for(int i = 1; i <= n; i++)
		if(x[i] < 0) st[0][top[0]++] = i, x[i] = -x[i];
		else st[1][top[1]++] = i, v[i] = -v[i];
	ll ans = top[0] * (ll)top[1];
	// cal div2
	for(int i = 0; i < 2; i++)
	{
		if(!top[i]) continue;
		for(int j = 0; j < top[i]; j++)
			p[j].a = x[st[i][j]], p[j].b = v[st[i][j]] - w;
		sort(p, p + top[i]);
		for(int j = 0; j < top[i ^ 1]; j++)
		{
			fs n1;
			n1.a = x[st[i ^ 1][j]], n1.b = v[st[i ^ 1][j]] + w;
			if(p[0] < n1)
			{
				int l = 0, r = top[i] - 1;
				while(l < r)
				{
					int mid = (l + r) >> 1;
					if(p[mid + 1] < n1) l = mid + 1;
					else r = mid;
				}
			//	cout<<"MNS"<<st[i ^ 1][j]<<": "<<l<<endl;
			//	n1.otp();
			//	p[0].otp();
				ans -= l + 1;
			}
		}
	}
//	cout<<ans<<endl;
//	system("pause");
	// cal div1
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cal.clear();
			for(int k = 0; k < top[i]; k++)
			{
				p[k].a = x[st[i][k]], p[k].b = v[st[i][k]] + w;
				if(j) p[k].b -= 2 * w;
			}
			sort(p, p + top[i]);
			int cnt = 1;
			for(int k = 0; k < top[i]; k++)
			{
				if(k == 0 || p[k - 1] < p[k])
					cal[p[k]] = cnt, cnt++;
			}
			for(int k = 0; k < top[i]; k++)
			{
				p[k].a = x[st[i][k]], p[k].b = v[st[i][k]] + w;
				if(j) p[k].b -= 2 * w;
				id[j][k] = cal[p[k]];
			}
			// 
		}
		ans += top[i] * (ll)(top[i] - 1) / 2;
		memset(d, 0, sizeof(d));
		for(int k = 0; k < top[i]; k++)
			p2[k].a = id[0][k], p2[k].b = id[1][k];
		sort(p2, p2 + top[i]);
		for(int j = 0; j < top[i]; )
		{
			int pl = j + 1;
			while(pl < top[i] && p2[pl].a == p2[j].a) pl++;
			for(int k = j; k < pl; k++)
				ans -= q(p2[k].b - 1);
			for(int k = j; k < pl; k++)
				ch(p2[k].b, 1);
			j = pl;
		}
	}
	printf("%I64d\n", ans);
	return 0;

}