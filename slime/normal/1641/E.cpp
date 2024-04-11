//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 1000005;

namespace modt
{

	inline int add(int a, int b)
	{
		a += b;
		return (a < mod) ? a : (a - mod);
	}
	inline int sub(int a, int b)
	{
		a -= b;
		return (a < 0) ? a + mod : a;
	}
	inline int mul(int a, int b)
	{
		return (ll)a * b % mod;
	}
	int power(int a, int b)
	{
		if (!b)
			return 1;
		int u = power(a, b >> 1);
		u = mul(u, u);
		if (b & 1)
			u = mul(u, a);
		return u;
	}
	vi rev, roots;
	int mx = -1;
	void init()
	{
		mx = 23;
		roots.resize(1 << mx);
		for (int j = 1; j <= mx; j++)
		{
			int mn = power(3, (mod - 1) >> j);
			for (int i = 0; i < (1 << (j - 1)); i++)
			{
				int npl = (1 << (j - 1)) | i;
				if (i == 0)
					roots[npl] = 1;
				else
					roots[npl] = mul(mn, roots[npl - 1]);
			}
		}
	}
	void calr(int m)
	{
		rev.resize(1 << m);
		if (mx == -1)
			init();
		rev[0] = 0;
		for (int j = 0; j < m; j++)
			for (int k = 0; k < (1 << j); k++)
				rev[k | (1 << j)] = rev[k] + (1 << (m - j - 1));
	}
	void dft(vi &a)
	{
		int n = a.size(), r = 0; //  a  2 
		while ((1 << r) < n)
			r++;
		calr(r);
		for (int i = 0; i < n; i++)
			if (rev[i] > i)
				swap(a[rev[i]], a[i]);
		for (int i = 1; i < n; i <<= 1)
		{
			for (int j = 0; j < n; j += (i << 1))
			{
				for (int k = 0; k < i; k++)
				{
					int mr = mul(a[i + j + k], roots[i + k]);
					a[i + j + k] = sub(a[j + k], mr);
					a[j + k] = add(a[j + k], mr);
				}
			}
		}
	}
	vi mult(vi a, vi b)
	{
		int l = a.size() + b.size() - 1;
		int r = 0;
		while ((1 << r) < l)
			r++;
		a.resize(1 << r), b.resize(1 << r);
		dft(a);
		dft(b);
		int bk = power(1 << r, mod - 2);
		for (int i = 0; i < (1 << r); i++)
			a[i] = mul(mul(a[i], b[i]), bk);
		reverse(a.begin() + 1, a.end());
		dft(a);
		a.resize(l);
		return a;
	}
}
vi operator*(vi a, vi b)
{
	if (a.size() > 20 && b.size() > 20)
		return modt::mult(a, b);
	vi res(a.size() + b.size() - 1);
	for (int i = 0; i < res.size(); i++)
	{
		int mn = min(i, (int)a.size() - 1);
		ll cur = 0;
		for (int j = max(0, i - (int)b.size() + 1); j <= mn; j++)
		{
			cur += 1ll * a[j] * b[i - j] % mod;
			if (cur > 7e18)
				cur %= mod;
		}
		cur %= mod;
		res[i] = cur;
	}
	return res;
}
int fn[maxn];
int fr[maxn], ed[maxn];
int n;
int fl[maxn];
ll a[maxn];
void work(int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    work(l, mid), work(mid + 1, r);
    vi cu(mid + 1 - l), g(r - mid);
    for (int i = l; i <= mid; i++)
        cu[i - l] = fr[i];
    for (int i = mid + 1; i <= r; i++)
        g[i - mid - 1] = ed[i];
    vi ff = cu * g;
    for (int i = 0; i < ff.size(); i++) {
        int id = i + l + mid + 1;
        fn[id] += ff[i];
        fn[id] %= mod;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = n + 1; i <= 2 * n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int p;
        scanf("%d", &p);
        fl[p + n] = 1;
    }
	fr[0] = 1;
    for (int i = 1; i <= 4 * n; i++)
        fr[i] = fr[i - 1] * (1 + fl[i]) % mod;
	ed[4 * n + 1] = 1;
    for (int i = 4 * n; i >= 1; i--)
        ed[i] = ed[i + 1] * (1 + fl[i]) % mod;
    work(0, 4 * n);
    ll ans = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
        ll ways = fn[2 * i] - i; ways %= mod;
		//cout << i << ' ' << ways << endl;
        ways = ways * a[i] % mod;
        ans = (ans + ways) % mod;
    }
    if (ans < 0) ans += mod;
	ll bk = ksm(2, m) - 1;
	bk = ksm(bk, mod - 2);
	ans = ans * bk % mod;
    cout << ans << endl;
    return (0-0); //<3
}