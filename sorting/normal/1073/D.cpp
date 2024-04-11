#include<bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;

long long a[N], fenwick[N], fenwick2[N], prefix[N];
pair<long long, long long> p[N];
long long n;
long long sum[N];

void update2(long long ind, long long val)
{
	for(; ind <= n; ind+= (ind&(-ind)) )
		fenwick2[ind] += val;
}

long long query2(long long ind)
{
	long long res = 0;

	for(; ind >= 1; ind -= (ind&(-ind)) )
		res += fenwick2[ind];

	return res;
}

long long range_query2(long long l, long long r)
{
	if(l == 1)
		return query2(r);

	return query2(r) - query2(l-1);
}

void update(long long ind, long long val)
{
	for(; ind <= n; ind+= (ind&(-ind)) )
		fenwick[ind] += val;
}

long long query(long long ind)
{
	long long res = 0;

	for(; ind >= 1; ind -= (ind&(-ind)) )
		res += fenwick[ind];

	return res;
}

long long range_query(long long l, long long r)
{
	if(l == 1)
		return query(r);

	return query(r) - query(l-1);
}

int main ()
{
	long long t, res = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> t;

	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i].first = a[i];
		p[i].second = i;
	}

	sort(p+1, p+1+n);

	for(long long i = 1; i <= n; i++)
		prefix[i] = p[i].first + prefix[i-1];

	for(long long i = 1; i <= n; i++)
	{
		update(i, a[i]);
		update2(i, 1ll);
	}

	/*for(long long i = n; i >= 1; i--)
	{
		sum[i] = query(p[i].second);
		update(p[i].second, -p[i].first);
	}*/

	long long start = 1;
	
	for(long long i = n; i >= 1; i--)
	{
		res += (t/prefix[i])*i;
		t %= prefix[i];

		long long curr = 0;

		if(start <= p[i].second)
		{
			curr = range_query(start, p[i].second);

			//cout << curr << endl;

			if(curr <= t)
			{
				t -= curr;
				res += range_query2(start, p[i].second);
				start = (p[i].second%n)+1;
			}
		}
		else
		{
			curr = range_query(start,n) + range_query(1, p[i].second);

			if(curr <= t)
			{
				t -= curr;
				res += range_query2(start,n) + range_query2(1, p[i].second);
				start = (p[i].second%n)+1;
			}
		}

		update(p[i].second, -p[i].first);
		update2(p[i].second, -1);

		//cout << res << endl;
	}

	cout << res << "\n";

	return 0;
}