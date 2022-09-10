#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int MOD = 1009;
const int N = 2e5+7;

int n, m, k, d;

int cnt[N];

struct cx
{
	double re, im;

	inline cx operator+(const cx &b)
	{
		return (cx){re+b.re, im+b.im};
	}

	inline cx operator-(const cx &b)
	{
		return (cx){re-b.re, im-b.im};
	}

	inline cx operator*(const cx &b)
	{
		return (cx){re*b.re-im*b.im, im*b.re+re*b.im};
	}

	inline cx operator!()
	{
		return (cx){re, -im};
	}

	inline cx operator-()
	{
		return (cx){-re, -im};
	}
};

const int FFTN = 1<<18;

cx omega[FFTN];

void fft(vector<cx> &a, bool inv)
{
	int n = a.size();

	if(n==1)
		return;

	vector<cx> a0(n/2), a1(n/2);

	for(int i = 0, j = 0; i < n/2; ++i, j += 2)
	{
		a0[i] = a[j];
		a1[i] = a[j+1];
	}

	fft(a0, inv);
	fft(a1, inv);

	int skok = FFTN/n;

	for(int i = 0; i < n/2; ++i)
	{
		cx w = omega[skok*i];
		a[i] = a0[i]+(inv?!w:w)*a1[i];
		a[i+n/2] = a0[i]-(inv?!w:w)*a1[i];

		if(inv)
		{
			a[i].re /= 2;
			a[i].im /= 2;
			a[i+n/2].re /= 2;
			a[i+n/2].im /= 2;
		}
	}
}

VI mul(VI &a, VI &b)
{
	int r = 1;

	while(r<a.size()+b.size()-1)
		r *= 2;

	vector<cx> A(r), B(r);

	for(int i = 0; i < a.size(); ++i)
	{
		A[i] = {(double)a[i], 0};
	}

	for(int i = 0; i < b.size(); ++i)
	{
		B[i] = {(double)b[i], 0};
	}

	fft(A, 0);
	fft(B, 0);

	for(int i = 0; i < r; ++i)
	{
		A[i] = A[i]*B[i];
	}

	fft(A, 1);

	VI c(a.size()+b.size()-1);

	for(int i = 0; i < a.size()+b.size()-1; ++i)
	{
		c[i] = (ll)(A[i].re+0.5)%MOD;
	}

	return c;
}

set<PII> S;	

VI pol[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	omega[0] = {1, 0};
	
	double ang = 2*acosl(-1)/FFTN;

	for(int i = 1; i < FFTN; ++i)
	{	
		omega[i] = (cx){cos(i*ang), sin(i*ang)};
	}

	cin >> n >> m >> k;

	for(int i = 1; i <= n; ++i)
	{
		int c;
		cin >> c;
		++cnt[c];
	}

	for(int i = 1; i <= m; ++i)
	{
		pol[i] = VI(cnt[i]+1, 1);
		S.insert(mp(pol[i].size(), i));
	}	

	while(S.size()>1)
	{
		int u = S.begin()->nd;
		S.erase(S.begin());
		int v = S.begin()->nd;
		S.erase(S.begin());

		pol[v] = mul(pol[u], pol[v]);
		S.insert(mp(pol[v].size(), v));
	}

	cout << pol[S.begin()->nd][k] << endl;
}