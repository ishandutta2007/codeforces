#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 10100;
const int MAXM = 100100;

int N, M;
ll P;
ll a[MAXN];
ll b[MAXM];
ll B;

vector <ll> factors;
vector <int> fcount;

vector <int> lcount[MAXN];
vector <int> tlist;

ll gcf (ll x, ll y)
{
	if (y == 0) return x;
	return gcf (y, x % y);
}

ll mpow (ll x, ll y) //x ^ y
{
	ll ans = 1;
	ll cpow = x;
	ll cexp = 1;
	
	while (cexp <= y)
	{
		if (y & cexp)
			ans = (ans * cpow) % P;
		cpow = (cpow * cpow) % P;
		cexp *= 2;
	}
	return ans;
}

int main()
{
	cin >> N >> M >> P;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < M; i++)
		cin >> b[i];
	
	B = b[0];
	for (int i = 1; i < M; i++)
		B = gcf (B, b[i]);
	for (int i = 0; i < N; i++)
		a[i] = mpow (a[i], B);
	
	factors.clear();
	ll temp = P - 1;
	for (ll i = 2; i * i <= temp; i++)
	{
		if (temp % i == 0)
		{
			factors.push_back (i);
			fcount.push_back (0);
			while (temp % i == 0)
			{
				fcount[fcount.size()-1]++;
				temp /= i;
			}
			
		}
	}
	if (temp > 1)
	{
		factors.push_back (temp);
		fcount.push_back (1);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < factors.size(); j++)
		{
			ll tval = (P - 1);
			for (int k = 0; k < fcount[j]; k++)
			{
				tval /= factors[j];
				
				//cout << k << " " << tval << " " << factors[j] << "\n";
				//cout << mpow (a[i], tval) << "\n";
				
				if (mpow (a[i], tval) > 1)
				{
					lcount[i].push_back (k);
					break;
				}
				if (k == fcount[j] - 1)
					lcount[i].push_back (fcount[j]);
			}
		}
	}
	
	int tot = 1;
	for (int i = 0; i < factors.size(); i++)
		tot *= fcount[i] + 1;
	
	ll ans = 0;
	
	for (int i = 0; i < tot; i++)
	{
		int ttemp = i;
		ll nval = 1;
		
		tlist.clear();
		for (int j = 0; j < factors.size(); j++)
		{
			tlist.push_back (ttemp % (fcount[j] + 1));
			ttemp /= (fcount[j] + 1);
			
			if (tlist[j] < fcount[j])
			{
				nval *= factors[j] - 1;
				for (int k = fcount[j] - 1; k > tlist[j]; k--)
					nval *= factors[j];
			}
		}
		
		for (int j = 0; j < N; j++)
		{
			bool check = true;
			for (int k = 0; k < factors.size(); k++)
				if (lcount[j][k] > tlist[k])
				{
					check = false;
					break;
				}
			if (check)
			{
				ans += nval;
				break;
			}
		}
	}
	cout << ans << "\n";
	
	/*for (int i = 0; i < factors.size(); i++)
	{
		cout << factors[i] << " " << fcount[i] << " " << lo[i] << "\n";
	}
	cout << "\n";
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << "\n";*/
	
	/*ll ans = P - 1;
	for (int i = 0; i < factors.size(); i++)
		for (int j = 0; j < lo[i]; j++)
			ans /= factors[i];
	cout << ans << "\n";*/
	return 0;
}