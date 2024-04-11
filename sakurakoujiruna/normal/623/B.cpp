#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1011111;
typedef long long intl;

vector <int> fac[N];
vector <int> cfac[N];

set <int> gcds;
map <int, int> cnt;
void factor(int n, vector <int> &vec, bool save = false)
{
	for(int d = 2; d * d <= n; d ++)
		if(n % d == 0)
		{
			//vec.push_back(d);
			while(n % d == 0)
				n /= d;
			
			if(save)
				gcds.insert(d);
			
		}
	if(n != 1)
	{
		//vec.push_back(n);
		
		if(save)
			gcds.insert(n);
		
	}
}

int num[N];
int type[N];
intl dpl[N];
intl dpr[N];

const int M = 1e5;
bool is_prime[M];

int main()
{
	//ios :: sync_with_stdio(false);
	int n;
	intl a, b;
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		//cin >> x;
		scanf("%d", &x);
		num[i] = x;
		if(i == 1 || i == n)
		{
			factor(x, fac[i], true);
			factor(x - 1, cfac[i], true);
			factor(x + 1, cfac[i], true);
		}
		else
		{
			/*
			factor(x, fac[i]);
			factor(x - 1, cfac[i]);
			factor(x + 1, cfac[i]);
			*/
		}
		//sort(fac[i].begin(), fac[i].end(), greater<int>());
		//sort(cfac[i].begin(), cfac[i].end(), greater<int>());
	}

	intl ans = 0x1f3f3f3f3f3f3f3fLL;
	//cout << gcds.size() << '\n';
	
	for(auto it = gcds.begin(); it != gcds.end(); it ++)
	{
		int d = *it;
		/*
		if(d != 2 && (n - cnt[d]) * min(a, b) >= ans)
			continue;
		*/
		int left = 0;
		int lc = 0;
		int rc = 0;
		while(left < n)
		{
			/*
			while(fac[left + 1].size() && *fac[left + 1].rbegin() < d)
				fac[left + 1].pop_back();
			while(cfac[left + 1].size() && *cfac[left + 1].rbegin() < d)
				cfac[left + 1].pop_back();
				*/
			if(/*fac[left + 1].size() && *fac[left + 1].rbegin() == d*/num[left + 1] % d == 0)
			{
				type[left + 1] = 1;
				left ++;
			}
			else if(/*cfac[left + 1].size() && *cfac[left + 1].rbegin() == d*/ (num[left + 1] + 1) % d == 0 || (num[left + 1] - 1) % d == 0)
			{
				type[left + 1] = 2;
				left ++;
				lc ++;
			}
			else
				break;
		}
		//cout << d << ' ' << left << '\n';
		if(left == n)
		{
			//cout << 0 << '\n';
			//return 0;
			ans = min(ans, lc * b);
			int old_lc = lc;

			dpl[0] = 0;
			int cnt = 0;
			int all_cnt = lc;
			for(int i = 1; i < n; i ++)
			{
				if(type[i] == 2)
				{
					cnt ++;
					lc --;
				}

				dpl[i] = dpl[i - 1] + a;
				dpl[i] = min(dpl[i], cnt * b);
				ans = min(ans, dpl[i] + lc * b);
			}

			reverse(type + 1, type + n + 1);
			dpl[0] = 0;
			cnt = 0;
			all_cnt = old_lc;
			lc = old_lc;
			for(int i = 1; i < n; i ++)
			{
				if(type[i] == 2)
				{
					cnt ++;
					lc --;
				}

				dpl[i] = dpl[i - 1] + a;
				dpl[i] = min(dpl[i], cnt * b);
				ans = min(ans, dpl[i] + lc * b);
			}
			/*
			dpr[0] = 0;
			cnt = 0;
			for(int i = n; i >= 1; i --)
			{
				if(type[i] == 2)
					cnt ++;
				dpr[i] = dpr[i + 1] + a;
				dpr[i] = min(dpr[i], cnt * b);
			}
			for(int i = 1; i <= n + 1; i ++)
				ans = min(ans, dpl[i - 1] + dpr[i]);
				*/
			continue;
		}
		int right = n + 1;
		while(right > 1)
		{
			/*
			while(fac[right - 1].size() && *fac[right - 1].rbegin() < d)
				fac[right - 1].pop_back();
			while(cfac[right - 1].size() && *cfac[right - 1].rbegin() < d)
				cfac[right - 1].pop_back();
				*/
			if(/*fac[right - 1].size() && *fac[right - 1].rbegin() == d*/ num[right - 1] % d == 0)
			{
				type[right - 1] = 1;
				right --;
			}
			else if(/*cfac[right - 1].size() && *cfac[right - 1].rbegin() == d*/ (num[right - 1] - 1) % d == 0 || (num[right - 1] + 1) % d == 0)
			{
				type[right - 1] = 2;
				right --;
				rc ++;
			}
			else
				break;
		}
		//cout << d << ' ' << left << ' ' << right << '\n';
		intl mid = (right - left - 1) * a;
		if(mid > ans)
			continue;
		intl lv = 0x1f3f3f3f3f3f3f3fLL;
		intl rv = 0x1f3f3f3f3f3f3f3fLL;
		intl lz = 0x0f3f3f3f3f3f3f3fLL;
		intl rz = 0x0f3f3f3f3f3f3f3fLL;
		for(int i = left; i >= 1; i --)
		{
			lv = min(lv, a * (left - i) + b * lc);
			if(type[i] == 2)
				lc --;
		}
		for(int i = right; i <= n; i ++)
		{
			rv = min(rv, a * (i - right) + b * rc);
			if(type[i] == 2)
				rc --;
		}
		lz = left * a;
		rz = (n - right + 1) * a;

		ans = min(ans, mid + lv + rv);
		ans = min(ans, mid + lz + rv);
		ans = min(ans, mid + lv + rz);
		//cout << d << ' ' << ans << '\n';
	}
	
	cout << ans << '\n';
	return 0;
}