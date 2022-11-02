#include <bits/stdc++.h>
using namespace std;

const int N = 1000011;

bool c[N];
bool can[N];

bool check(int k)
{
	for(int i = 2; i * i <= k; i ++)
		if(k % i == 0)
		{
			int t = 1;
			while(k % i == 0)
			{
				t *= i;
				k /= i;
			}
			if(!can[t])
				return false;
		}
	if(k != 1 && !can[k])
		return false;
	return true;
}

int main()
{
	//ios :: sync_with_stdio(false);
	int n, k;
	//cin >> n >> k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i ++)
	{
		int x;
		//cin >> x;
		scanf("%d", &x);
		c[x] = true;
	}
	for(int i = 2; i < N; i ++)
		for(int j = i; j < N; j += i)
			can[i] |= c[j];

	if(check(k))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}