#include <iostream>
using namespace std;

const int Mod = (int)1e9 + 7;
long long qpow(long long a, int b)
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

const int N = 1011111;

int main()
{
	ios :: sync_with_stdio(false);
	int p, k;
	cin >> p >> k;
	if(k == 0)
	{
		cout << qpow(p, p - 1) << '\n';
		return 0;
	}
	else if(k == 1)
	{
		cout << qpow(p, p) << '\n';
		return 0;
	}
	int cnt = 1;
	for(long long i = k; i != 1; i = i * k % p)
		cnt ++;
	cout << qpow(p, (p - 1) / cnt) << '\n';
	return 0;
}