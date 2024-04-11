#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1211111;
const int Mod = (int)1e9 + 7;

int lowbit(int x)
{
	return x & (-x);
}
struct BIT
{
	long long b[N];
	BIT() { }
	void initialize()
	{
		memset(b, 0, sizeof(b));
	}
	void change(int pos, long long c)
	{
		pos += 4;
		for(int i = pos; i < N; i += lowbit(i))
		{
			b[i] += c;
			b[i] %= Mod;
		}
	}
	long long query(int pos)
	{
		pos += 4;
		long long ret = 0;
		for(int i = pos; i > 0; i -= lowbit(i))
			ret += b[i];
		return ret % Mod;
	}
}bit;

int a[N];

long long tmp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	long long l;
	cin >> n >> l >> k;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	/*
	bit.initialize();
	for(int i = 0; i < n; i ++)
		bit.change(i, 1);
	*/
	for(int i = 0; i < n; i ++)
		tmp[i] = 1;
	for(int t = 1; t < k; t ++)
	{
		vector <pair <int, int> > vec;
		for(int i = 0; i < n; i ++)
			vec.push_back(make_pair(a[i], t * n + i));
		sort(vec.begin(), vec.end());

		long long sum = 0;
		for(int i = 0; i < n; i ++)
		{
			if(i == 0 || vec[i].first != vec[i - 1].first)
			{
				sum += /*bit.query(a[vec[i].second])*/ tmp[vec[i].second - n];
				for(int j = i + 1; j < n && vec[j].first == vec[j - 1].first; j ++)
				{
					//cout << vec[j].second << '\n';
					sum += /*bit.query(vec[j].second - n)*/ tmp[vec[j].second - n];
				}
				//cout << '!' << '\n';
				sum %= Mod;
			}
			//bit.change(vec[i].second, sum);
			//cout << vec[i].second << '\n';
			tmp[vec[i].second] = sum;
		}
	}

	long long ans = 0;
	long long cnt_a = l / n;
	long long rem_a = l % n;

	for(int t = 0; t < k; t ++)
		for(int i = 0; i < n; i ++)
		{
			//cout << tmp[t * n + i] << '\n';
			//cout << bit.query(t * n + i) << '\n';
			long long cnt = cnt_a;
			if(i < rem_a)
				cnt ++;

			if(cnt >= t + 1)
				ans += (cnt - t) % Mod * /*bit.query(t * n + i)*/ tmp[t * n + i] % Mod;
			ans %= Mod;
		}

	cout << ans % Mod << '\n';
}