#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101111;
typedef long long intl;

intl a[N];
intl suf[N];

intl aa[N];
pair <intl, int> p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	intl A;
	intl c_f, c_m, m;
	cin >> n >> A;
	cin >> c_f >> c_m >> m;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		p[i].first = a[i];
		p[i].second = i;
	}
	sort(p, p + n);
	for(int i = 0; i < n; i ++)
		a[i] = p[i].first;
	intl last_sum = 0;
	for(int i = n - 1; i >= 0; i --)
	{
		last_sum += a[i];
		suf[i] = suf[i - 1] + a[i];
	}

	a[n] = 0;
	intl ans = -1;
	int al, ar, am;
	int last = n;
	intl max_sum = 0;
	for(int i = n; i >= 0; i --)
	{
		if(i != n)
			max_sum += A - a[i];
		intl ta = m - max_sum;
		if(ta < 0)
			break;
		while(last > i)
		{
			last --;
			last_sum -= a[last];
		}
		while(last > 0)
		{
			intl next_sum = last_sum;
			//cout << last << ' ' << next_sum + ta << '\n';
			if((next_sum + ta) / last < a[last - 1])
			{
				last --;
				last_sum -= a[last];
			}
			else
			{
				if((n - i) * c_f + min((next_sum + ta) / last, A) * c_m > ans)
				{
					ans = (n - i) * c_f + min((next_sum + ta) / last, A) * c_m;
					al = last;
					ar = i;
					am = min((next_sum + ta) / last, A);
				}
				break;
			}
		}
		//cout << last << '\n';
		//cout << ans << ' ' << al << ' ' << ar << ' ' << am << '\n';
		if(i == 0)
		{
			ans = n * c_f + A * c_m;
			al = 0;
			ar = 0;
		}
	}
	for(int i = 0; i < al; i ++)
		aa[p[i].second] = am;
	for(int i = al; i < ar; i ++)
		aa[p[i].second] = a[i];
	for(int i = ar; i < n; i ++)
		aa[p[i].second] = A;

	cout << ans << '\n';
	for(int i = 0; i < n; i ++)
		cout << aa[i] << ' ';
	cout << '\n';
	return 0;
}