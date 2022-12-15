#include <bits/stdc++.h>

using namespace std;

const long long N = 3e5;

struct fast_complex
{
	long double a, b;

	fast_complex(long double _a = 0.0, long double _b = 0.0)
	{
		a = _a;
		b = _b;
	}

	long double real()
	{
		return a;
	}

	friend fast_complex operator+(fast_complex lvalue, fast_complex rvalue)
	{
		fast_complex ret;

		ret.a = lvalue.a + rvalue.a;
		ret.b = lvalue.b + rvalue.b;

		return ret;
	}

	friend fast_complex operator-(fast_complex lvalue, fast_complex rvalue)
	{
		fast_complex ret;

		ret.a = lvalue.a - rvalue.a;
		ret.b = lvalue.b - rvalue.b;

		return ret;
	}

	friend fast_complex operator*(fast_complex lvalue, fast_complex rvalue)
	{
		fast_complex ret;

		ret.a = lvalue.a * rvalue.a - lvalue.b * rvalue.b;
		ret.b = lvalue.a * rvalue.b + lvalue.b * rvalue.a;

		return ret;
	}

	friend fast_complex operator/(fast_complex lvalue, double rvalue)
	{
		fast_complex ret;

		ret.a = lvalue.a / rvalue;
		ret.b = lvalue.b / rvalue;

		return ret;
	}
};

using cd = fast_complex;
//using cd = complex<long double>;
const long double PI = acos(-1);

void fft(vector<cd> &a, bool invert)
{
	int n = a.size();

	for(int i = 1, j = 0; i < n; i++)
	{
		int bit = n / 2;

		for(; bit & j; bit /= 2)
			j ^= bit;
		j ^= bit;

		if(i < j)
			swap(a[i], a[j]);
	}

	for(int len = 2; len <= n; len *= 2)
	{
		long double ang = 2 * PI / len * (invert ? -1 : 1);
		cd wlen(cos(ang), sin(ang));

		for(int i = 0; i < n; i += len)
		{
			cd w(1);

			for(int j = 0; j < len / 2; j++)
			{
				cd u = a[i+j], v = a[i+j+ len/2] * w;

				a[i+j] = u + v;
				a[i+j + len/2] = u - v;

				w =  w * wlen; 
			}
		}
	}

	if(invert)
		for(auto &x: a)
			x = x / n;
}

vector<long long> multiply(vector<long long> const &a, vector<long long> const &b)
{
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;

	while(n < a.size() + b.size())
		n *= 2;

	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);

	for(int i = 0; i < n; i++)
		fa[i] = fa[i] * fb[i];

	fft(fa, true);

	vector<long long> res(n);
	for(int i = 0; i < n; i++)
		res[i] = round(fa[i].real());

	return res;
}

vector<long long> vs[6], vt[6], res[6][6];
long long cnt[N];

vector<long long> adj[6];
bool used[6];

void dfs(int u)
{
	used[u] = true;

	for(int to: adj[u])
		if(!used[to])
			dfs(to);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t;

	cin >> s >> t;

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == 'a' + i)
				vs[i].push_back(1);
			else
				vs[i].push_back(0);
		}

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < t.size(); j++)
		{
			if(t[j] == 'a' + i)
				vt[i].push_back(1);
			else
				vt[i].push_back(0);
		}

	for(int i = 0; i < 6; i++)
	{
		reverse(vt[i].begin(), vt[i].end());

		for(int j = 0; j < 6; j++)
		{
			if(i == j)
				continue;
			res[i][j] = multiply(vt[i], vs[j]);
		}
	}

	for(int i = t.size() - 1; i < s.size(); i++)
	{
		for(int j = 0; j < 6; j++)
		{
			adj[j].clear();
			used[j] = false;
		}

		for(int j = 0; j < 6; j++)
			for(int k = j + 1; k < 6; k++)
				if(res[j][k][i] || res[k][j][i])
				{
					adj[j].push_back(k);
					adj[k].push_back(j);
				}

		int cnt = 0;

		for(int i = 0; i < 6; i++)
			if(!used[i])
			{
				cnt++;
				dfs(i);
			}

		cout << 6 - cnt << " ";
	}

	cout << "\n";

	return 0;
}