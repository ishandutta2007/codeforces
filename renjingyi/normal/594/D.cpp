#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 2e5 + 5, maxv = 1e6 + 5;
const long long mod = 1e9 + 7;
namespace BIT
{
	#define lowbit(x) (x & -x)
	long long c[maxn];
	void mul(const int &p, const int &n, const long long &v)
	{
		//cout << "mul : " << p << " " << n << " " << v << endl;
		for(int i = p; i <= n; i += lowbit(i))
			(c[i] *= v) %= mod;
	}
	long long query(const int &p)
	{
		//cout << "query : " << p << endl;
		long long ans = 1;
		for(int i = p; i; i -= lowbit(i))
			(ans *= c[i]) %= mod;
		return ans;
	}
}
long long power(const long long &a, const long long &k)
{
	long long ans = 1, x = a % mod;
	for(long long i = k; i; i >>= 1, (x *= x) %= mod)
		if(i & 1)
			(ans *= x) %= mod;
	return ans;
}
struct quest
{
	int l, r, id;
	quest(const int &l = 0, const int &r = 0, const int &id = 0) : l(l), r(r), id(id) {}
	bool operator<(const quest &q)const
	{
		return r < q.r;
	}
}q[maxn];
int a[maxn];
int first[maxv], last[maxv];
long long inv[maxv], iinv[maxv];
long long ans[maxn], qq[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i <= n; i ++)
		BIT::c[i] = 1;
	int mx = 0;
	qq[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		qq[i] = qq[i - 1] * a[i] % mod;
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= mx; i ++)
	{
		first[i] = i;
		iinv[i] = i * power(i - 1, mod - 2) % mod;
		inv[i] = power(iinv[i], mod - 2);
	}
	for(int i = mx; i >= 2; i --)
		for(int j = i; j <= mx; j += i)
			first[j] = i;
	//for(int i = 1; i <= mx; i ++)
	//{
	//	cout << "now : " << i << " " << first[i] << " " << inv[i] << " " << iinv[i] << endl;
	//}
	int t;
	cin >> t;
	for(int i = 1; i <= t; i ++)
	{
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	sort(q + 1, q + t + 1);
	int pos = 1;
	for(int i = 1; i <= t; i ++)
	{
		for(; pos <= q[i].r; pos ++)
		{
			int x = a[pos];
			while(x > 1)
			{
				int now = first[x];
				//cout << "here : " << i << " " << pos << " " << x << " " << now << endl;
				x /= now;
				if(last[now] == pos)
					continue;
				if(last[now] > 0)
					BIT::mul(last[now], n, iinv[now]);
				BIT::mul(pos, n, inv[now]);
				last[now] = pos;
			}
		}
		ans[q[i].id] = qq[q[i].r] * power(qq[q[i].l - 1], mod - 2) % mod * BIT::query(q[i].r) % mod * power(BIT::query(q[i].l - 1), mod - 2) % mod;
	}
	for(int i = 1; i <= t; i ++)
		cout << ans[i] << endl;
	
	return 0;
}