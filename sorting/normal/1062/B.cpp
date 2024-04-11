#include<bits/stdc++.h>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	long long x = n;
	long long sum = 0, maxi = 0, res = 1;
	long long cnt_p = 0;

	for(long long i = 2; i*i <= x; i++)
	{
		if(x % i == 0)
		{
			long long cnt = 0;

			while(x % i == 0)
			{
				cnt++;
				x /= i;
			}

			sum += cnt;
			maxi = max(maxi, cnt);
			res *= i;
			cnt_p++;
		}
	}

	if(x != 1)
	{
		sum ++;
		maxi = max(maxi, 1ll);
		res *= x;
		cnt_p++;
	}

	long long i, res2 = 0;

	long long st = 1;

	for( i = 0; st < maxi; i++, st *= 2)
		continue;

	//cout << i << endl;

	if( (1ll<<i)*cnt_p != sum)
		res2++;

	res2 += i;

	cout << res << " " << res2 << "\n";

	return 0;
}