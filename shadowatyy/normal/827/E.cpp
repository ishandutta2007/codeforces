#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
#define LD long double
#define siz(c) (int)(c).size()
using namespace std;

const int N = 5e5+7;

int n, t;

string s;

bool ans[N];

namespace fft {
  typedef double dbl;
  typedef complex<dbl> num;
  #define x real()
  #define y imag()

  int base = 1;
  vector<num> roots = {{0, 0}, {1, 0}};
  vector<int> rev = {0, 1};
 
  const dbl PI = acosl(-1.0);
 
  void ensure_base(int nbase) {
    if (nbase <= base) {
      return;
    }
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      dbl angle = 2 * PI / (1 << (base + 1));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        dbl angle_i = angle * (2 * i + 1 - (1 << base));
        roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
      }
      base++;
    }

    /*cerr << "xd" << endl;
    base = nbase;

    for(int i = 0; i < 1<<base; ++i)
    {
      dbl angle = 2 * PI * i / (1<<base); 
      roots[i] = num(cos(angle), sin(angle));
    }*/
  }
 
  void fft(vector<num> &a, int n = -1) {
    if (n == -1) {
      n = a.size();
    }
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int len = 1; len < n; len <<= 1) {
      for (int i = 0; i < n; i += 2 * len) {
        for (int j = i, k = i + len; j < i + len; j++, k++) {
          num z = a[k] * roots[k - i];
          a[k] = a[j] - z;
          a[j] = a[j] + z;
        }
      }
    }
  }
 
  vector<num> fa, fb;
 
  vector<long long> multiply(vector<int> &a, vector<int> &b) {
    int need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) fa.size()) {
      fa.resize(sz);
    }
    for (int i = 0; i < sz; i++) {
      int _x = (i < (int) a.size() ? a[i] : 0);
      int _y = (i < (int) b.size() ? b[i] : 0);
      fa[i] = num(_x, _y);
    }
    fft(fa, sz);
    num r(0, -0.25 / sz);
    for (int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
      if (i != j) {
        fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
      }
      fa[i] = z;
    }
    fft(fa, sz);
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
      res[i] = fa[i].x + 0.5;
    }
    return res;
  }
  // fft::multiply uses dbl, outputs vector<long long> of rounded values
  // fft::multiply_mod might work for res.size() up to 2^21
  // typedef long double dbl;          =>        up to 2^25 (but takes a lot of memory)
};

void solve()
{
	cin >> n >> s;

	VI A(n), B(n);

	for(int i = 0; i < n; ++i)
	{
		if(s[i]=='V')
			A[i] = 1;
		else if(s[i]=='K')
			B[n-1-i] = 1;
	}

	vector<ll> C = fft::multiply(A, B);

	for(int i = 0; i < siz(C); ++i)
	{
		if(C[i])
			ans[abs(n-1-i)] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 2*i; j <= n; j += i)
		{
			ans[i] |= ans[j];
		}
	}

	int res = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(!ans[i])
			++res;
	}

	cout << res << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(!ans[i])
			cout << i << " ";

		ans[i] = 0;
	}

	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
		solve();
}