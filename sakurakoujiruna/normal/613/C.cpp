#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

const int N = 101111;
int a[N];
char str[N];

bool pal_check(int g, int n)
{
	int odd_cnt = 0;
	for(int i = 0; i < n; i ++)
	{
		if((a[i] / g) & 1)
			odd_cnt ++;
	}
	if(odd_cnt > 1)
		return false;
	return true;
}

bool check(int g, int n)
{
	if(g & 1)
		return pal_check(g, n);
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int all_gcd = a[0];
	for(int i = 1; i < n; i ++)
		all_gcd = gcd(all_gcd, a[i]);

	if(!pal_check(1, n))
	{
		cout << 0 << '\n';
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < a[i]; j ++)
				cout << (char)(i + 'a');
		cout << '\n';
		return 0;
	}

	int ans = 1;
	for(int i = 2; i <= all_gcd; i ++)
		if(all_gcd % i == 0 && check(i, n))
			ans = max(ans, i);

	if(ans > 1 && (ans & 1) == 0)
	{
		cout << ans << '\n';
		int len = sum / ans;
		int p = 0;
		for(int i = 0; i < n; i ++)
		{
			/*
			if((a[i] / ans) & 1)
				str[len / 2] = i + 'a';
			for(int j = 0; j < (a[i] / ans) / 2; j ++)
			{
				str[p] = str[len - p - 1] = i + 'a';
				p ++;
			}*/
			for(int j = 0; j < a[i] / ans; j ++)
				str[p ++] = i + 'a';
		}
		for(int i = 0; i < ans; i ++)
			if(i & 1)
				for(int j = 0; j < len; j ++)
					cout << str[j];
			else
				for(int j = len - 1; j >= 0; j --)
					cout << str[j];
		cout << '\n';
	}
	else if(ans & 1)
	{
		cout << ans << '\n';
		int p = 0;
		sum /= ans;
		for(int i = 0; i < n; i ++)
		{
			if((a[i] / ans) & 1)
				str[sum / 2] = i + 'a';
			for(int j = 0; j < (a[i] / ans) / 2; j ++)
			{
				str[p] = str[sum - p - 1] = i + 'a';
				p ++;
			}
		}
		for(int j = 0; j < ans; j ++)
		for(int i = 0; i < sum; i ++)
			cout << str[i];
		cout << '\n';
	}
	return 0;
}