#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

#define N 150007

int n, ok, res;

int a[N];
int zly[N];

PII A, B;

bool sprawdz(int i)
{
	if(i%2==1)
		return a[i]<a[i+1];
	else
		return a[i]>a[i+1];
}

VI q;

set<PII> juz;

bool check(int i, int j)
{
	if(i<1 || i>n || j<1 || j>n || i>=j || juz.find({i, j})!=juz.end())
	{
		juz.insert({i, j});
		return 0;
	}

	int ile = 0;

	q.clear();

	if(i>1)
		q.pb(i-1);

	if(i<n)
		q.pb(i);

	if(j>1)
		q.pb(j-1);

	if(j<n)
		q.pb(j);

	sort(ALL(q));
	q.erase(unique(ALL(q)), q.end());

	for(auto it:q)
		ile -= sprawdz(it);

	swap(a[i], a[j]);

	q.clear();

	if(i>1)
		q.pb(i-1);

	if(i<n)
		q.pb(i);

	if(j>1)
		q.pb(j-1);

	if(j<n)
		q.pb(j);

	sort(ALL(q));
	q.erase(unique(ALL(q)), q.end());

	for(auto it:q)
		ile += sprawdz(it);

	swap(a[i], a[j]);

	juz.insert({i, j});

	return ok+ile==n-1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i < n; ++i)
	{
		if(!sprawdz(i))
			zly[i] = (zly[i-1]?zly[i-1]:i);
		else
			++ok;
	}

	for(int i = 1; i < n; ++i)
	{
		if(zly[i] && !zly[i+1])
		{
			if(!A.st)
			{
				A.st = zly[i];
				A.nd = i;
			}	
			else if(!B.st)
			{
				B.st = zly[i];
				B.nd = i;
			}
			else
			{
				cout << 0;
				return 0;
			}
		}
	}


	if(!B.st)
	{
		if(A.nd-A.st+1>2)
		{
			if(A.nd-A.st+1>5)
			{
				cout << 0;
				return 0;
			}

			for(int i = A.st-1; i <= A.nd+1; ++i)
			{
				for(int j = i+1; j <= A.nd+1; ++j)
				{
					if(check(min(i, j), max(i, j)))
						++res;
				}
			}
		}
		else
		{
			for(int i = 1; i <= n; ++i)
			{
				for(int j = A.st-1; j <= A.nd+1; ++j)
				{
					if(check(min(i, j), max(i, j)))
						++res;
				}
			}
		}
	}
	else
	{
		if(A.nd-A.st+1>3 || B.nd-B.st+1>3)
		{
			cout << 0;
			return 0;
		}

		for(int i = A.st-1; i <= A.nd+1; ++i)
		{
			for(int j = B.st-1; j <= B.nd+1; ++j)
			{
				if(check(min(i, j), max(i, j)))
					++res;
			}
		}
	}

	cout << res;
}