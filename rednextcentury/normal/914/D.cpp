#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 500005
ll a[N], sg[N * 4], n, m, x, y, l, r, t;
ll gcd(ll f, ll s)
{
	if (min(f, s) == 0)
		return max(f, s);
	return gcd(min(f, s), max(f, s) % min(f, s));
}
void build(int low, int high, int pos)
{
	if (low == high)
	{
		sg[pos] = a[low];
		return;
	}
	int mid = (low + high) / 2;
	build(low, mid, pos * 2 + 1);
	build(mid + 1, high, pos * 2 + 2);
	sg[pos] = gcd(sg[pos * 2 + 1], sg[pos * 2 + 2]);
}
void update(int low, int high, int pos, int qpos, ll va)
{
	if (qpos<low || qpos>high)
		return;
	if (low == high)
	{
		sg[pos] = va;
		return;
	}
	int mid = (low + high) / 2;
	if (qpos <= mid)
		update(low, mid, pos * 2 + 1, qpos, va);
	else
		update(mid + 1, high, pos * 2 + 2, qpos, va);

	sg[pos] = gcd(sg[pos * 2 + 1], sg[pos * 2 + 2]);
}
ll query(int low, int high, int pos, int qlow, int qhigh, ll va)
{
	if (low > qhigh || qlow > high)
		return 0;
	int mid = (low + high) >> 1;
	if (qlow <= low&&high <= qhigh)
	{
		//cout << sg[pos] << " " << low << " " << high << " " << endl;
		if (sg[pos] % va == 0)
			return 0;
		else if (low == high)
			return 1;
		else if (sg[pos * 2 + 1] % va && sg[pos * 2 + 2] % va)
		    return 2;
		else if (sg[pos * 2 + 1] % va == 0)
			return query(mid+1, high, pos * 2 + 2, qlow, qhigh, va);
		else if (sg[pos * 2 + 2] % va == 0)
			return query(low, mid, pos * 2 + 1, qlow, qhigh, va);
		else
			return high-low+1;
	}
	ll le = query(low, mid, pos * 2 + 1, qlow, qhigh, va),
		ri = query(mid + 1, high, pos * 2 + 2, qlow, qhigh, va);
	return le + ri;
}
int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	build(0, n - 1, 0);
	//cout << "built";
	scanf("%lld", &m);
	while (m--)
	{
		scanf("%lld", &t);
		if (t == 1)
		{
			scanf("%lld%lld%lld", &l, &r, &x);
			t = query(0, n - 1, 0, l - 1, r - 1, x);
			//cout << "got it";
			if (t > 1)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
		{
			scanf("%lld%lld", &x, &y);
			update(0, n - 1, 0, x - 1, y);
		}
	}
	return 0;
}