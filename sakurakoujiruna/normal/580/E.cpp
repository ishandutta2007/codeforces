#include <iostream>
#include <cstring>
using namespace std;

const int N = 101111;
const long long Mod = (long long)1e9 + 9;
const long long qpow(long long a, int b)
{
	long long ret = 1;
	long long tmp = a;
	while(b > 0)
	{
		if(b & 1)
		{
			ret *= tmp;
			ret %= Mod;
		}
		tmp *= tmp;
		tmp %= Mod;
		b >>= 1;
	}
	return ret;
}

const long long Inv9 = qpow(9, Mod - 2);
long long pow10[N];

struct Segment_tree
{
	int l[N << 2];
	int r[N << 2];
	int flag[N << 2];
	long long hash[N << 2];
	Segment_tree() { }

	void push(int x)
	{
		if(flag[x] == -1)
			return;
		hash[x] = (pow10[r[x] - l[x]] - 1) * Inv9 % Mod * flag[x] % Mod;
		if(l[x] + 1 != r[x])
		{
			flag[2 * x] = flag[x];
			flag[2 * x + 1] = flag[x];
		}
		flag[x] = -1;
	}
	void init(int left, int right, string &str, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		flag[x] = -1;
		if(left + 1 == right)
			hash[x] = str[left - 1] - '0';
		else
		{
			int mid = (left + right) >> 1;
			init(left, mid, str, 2 * x);
			init(mid, right, str, 2 * x + 1);
			hash[x] = (pow10[right - mid] * hash[2 * x] + hash[2 * x + 1]) % Mod;
		}
	}
	void change(int left, int right, int c, int x = 1)
	{
		if(l[x] == left && r[x] == right)
		{
			flag[x] = c;
			push(x);
		}
		else
		{
			push(x);
			int mid = (l[x] + r[x]) >> 1;
			if(mid >= right)
			{
				change(left, right, c, 2 * x);
				push(2 * x + 1);
			}
			else if(mid <= left)
			{
				change(left, right, c, 2 * x + 1);
				push(2 * x);
			}
			else
			{
				change(left, mid, c, 2 * x);
				change(mid, right, c, 2 * x + 1);
			}
			hash[x] = (pow10[r[x] - mid] * hash[2 * x] + hash[2 * x + 1]) % Mod;
		}
	}
	long long query(int left, int right, int x = 1)
	{
		push(x);
		if(left == l[x] && right == r[x])
		{
			return hash[x];
		}
		int mid = (l[x] + r[x]) >> 1;
		if(mid >= right)
			return query(left, right, 2 * x);
		else if(mid <= left)
			return query(left, right, 2 * x + 1);
		else
			return (pow10[right - mid] * query(left, mid, 2 * x) + query(mid, right, 2 * x + 1)) % Mod;
	}
}st;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	string str;
	cin >> str;
	pow10[0] = 1;
	for(int i = 1; i < N; i ++)
		pow10[i] = pow10[i - 1] * 10 % Mod;
	st.init(1, n + 1, str);

	for(int i = 0; i < m + k; i ++)
	{
		int t, l, r, c;
		cin >> t >> l >> r >> c;
		if(t == 1)
			st.change(l, r + 1, c);
		else
		{
			if(c == r - l + 1)
				cout << "YES\n";
			else
			{
				long long h1 = st.query(l, r - c + 1);
				long long h2 = st.query(l + c, r + 1);
				if(h1 == h2)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}