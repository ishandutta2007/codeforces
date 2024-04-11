#include<bits/stdc++.h>

const long long N = 1e6 + 7;

long long p[N], b[N], where[N];
std::pair<long long, long long> border[N];
std::set<long long> st;

bool to_remove[N];

long long fenwick[N];
long long n;

void update(long long pos, long long val)
{
	for(; pos <= n; pos += pos & (-pos))
		fenwick[pos] += val;

	return ;
}

long long query(long long pos)
{
	long long res = 0;

	for(; pos >= 1; pos -= pos & (-pos))
		res += fenwick[pos];

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
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long k;

	std::cin >> n >> k;

	for(long long i = 1; i <= n; i++)
	{
		std::cin >> p[i];
		where[p[i]] = i;
		to_remove[i] = true;
	}
	for(long long i = 1; i <= k; i++)
	{
		std::cin >> b[i];
		to_remove[ where[b[i]] ] = false;
	}

	for(long long i = 1; i <= n; i++)
		update(i, 1);

	long long res = 0;

	st.insert(0);
	st.insert(n+1);

	for(long long i = 1; i <= n; i++)
		if(to_remove[ where[i] ])
		{
			std::set<long long>::iterator it2 = st.lower_bound(where[i]);
			std::set<long long>::iterator it1 = it2;

			it1--;

			//std::cout << *it1 << " it1\n";

			res += range_query(*it1 + 1, *it2 - 1);
			update(where[i], -1);

			//std::cout << res << std::endl;
		}
		else
			st.insert(where[i]);

	std::cout << res << "\n";

	return 0;
}