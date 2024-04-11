#include<bits/stdc++.h>
using namespace std;
set<tuple<int, int, int, int, int> > m[2];
int ar[212345];
int main()
{
	long long ans = 0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &ar[i]);
	for(int i = 0; i < n; i++)
	{
		int x = i & 1;
		/*printf("turn %d, ans = %d\n", i, ans);
		for(set<tuple<int, int, int, int, int> >::iterator j = m[x].begin(); j != m[x].end(); j++)
		{
			int a = get<0> (*j);
			int b = get<1> (*j);
			int c = get<2> (*j);
			int d = get<3> (*j);
			int e = get<4> (*j);
			printf("%d %d %d %d %d\n", a, b, c, d, e);
		}*/

		m[x ^ 1].clear();
		for(set<tuple<int, int, int, int, int> >::iterator j = m[x].begin(); j != m[x].end(); j++)
		{
			int a = get<0> (*j);
			int b = get<1> (*j);
			int c = get<2> (*j);
			int d = get<3> (*j);
			int e = get<4> (*j);			
			if(a < ar[i] && b > ar[i])
			{
				ans += e;
				tuple<int, int, int, int, int> z = make_tuple(ar[i], b, a, ar[i], 0);
				tuple<int, int, int, int, int> z2 = make_tuple(ar[i], b, a, ar[i], e);
				if(m[x ^ 1].empty())
				{
					m[x ^ 1].insert(z2);
					continue;
				}
				set<tuple<int, int, int, int, int> >::iterator v = m[x ^ 1].lower_bound(z);
				int a2 = get<0> (*v);
				int b2 = get<1> (*v);
				int c2 = get<2> (*v);
				int d2 = get<3> (*v);
				int e2 = get<4> (*v);
				if(a2 == ar[i] && b2 == b && c2 == a && d2 == ar[i])
				{
					m[x ^ 1].erase(v);
					m[x ^ 1].insert(make_tuple(ar[i], b, a, ar[i], e + e2));
				}
				else m[x ^ 1].insert(z2);
				continue;
			}
			if(c < ar[i] && d > ar[i])
			{
				ans += e;
				tuple<int, int, int, int, int> z = make_tuple(ar[i], d, c, ar[i], 0);
				tuple<int, int, int, int, int> z2 = make_tuple(ar[i], d, c, ar[i], e);
				if(m[x ^ 1].empty())
				{
					m[x ^ 1].insert(z2);
					continue;
				}
				set<tuple<int, int, int, int, int> >::iterator v = m[x ^ 1].lower_bound(z);
				int a2 = get<0> (*v);
				int b2 = get<1> (*v);
				int c2 = get<2> (*v);
				int d2 = get<3> (*v);
				int e2 = get<4> (*v);
				if(a2 == ar[i] && b2 == d && c2 == c && d2 == ar[i])
				{
					m[x ^ 1].erase(v);
					m[x ^ 1].insert(make_tuple(ar[i], d, c, ar[i], e + e2));
				}
				else m[x ^ 1].insert(z2);
				continue;
			}
			if(a < ar[i])
			{
				ans += e;
				tuple<int, int, int, int, int> z = make_tuple(ar[i], b, -1, -1, 0);
				tuple<int, int, int, int, int> z2 = make_tuple(ar[i], b, -1, -1, e);
				if(m[x ^ 1].empty())
				{
					m[x ^ 1].insert(z2);
					continue;
				}
				set<tuple<int, int, int, int, int> >::iterator v = m[x ^ 1].lower_bound(z);
				int a2 = get<0> (*v);
				int b2 = get<1> (*v);
				int c2 = get<2> (*v);
				int d2 = get<3> (*v);
				int e2 = get<4> (*v);
				if(a2 == ar[i] && b2 == b && c2 == -1 && d2 == -1)
				{
					m[x ^ 1].erase(v);
					m[x ^ 1].insert(make_tuple(ar[i], b, -1, -1, e + e2));
				}
				else m[x ^ 1].insert(z2);
				continue;
			}
			if(a < ar[i])
			{
				ans += e;
				tuple<int, int, int, int, int> z = make_tuple(ar[i], b, -1, -1, 0);
				tuple<int, int, int, int, int> z2 = make_tuple(ar[i], b, -1, -1, e);
				if(m[x ^ 1].empty())
				{
					m[x ^ 1].insert(z2);
					continue;
				}
				set<tuple<int, int, int, int, int> >::iterator v = m[x ^ 1].lower_bound(z);
				int a2 = get<0> (*v);
				int b2 = get<1> (*v);
				int c2 = get<2> (*v);
				int d2 = get<3> (*v);
				int e2 = get<4> (*v);
				if(a2 == ar[i] && b2 == b && c2 == -1 && d2 == -1)
				{
					m[x ^ 1].erase(v);
					m[x ^ 1].insert(make_tuple(ar[i], b, -1, -1, e + e2));
				}
				else m[x ^ 1].insert(z2);
				continue;
			}	
			if(c > ar[i])
			{
				ans += e;
				tuple<int, int, int, int, int> z = make_tuple(c, ar[i], -1, -1, 0);
				tuple<int, int, int, int, int> z2 = make_tuple(c, ar[i], -1, -1, e);
				if(m[x ^ 1].empty())
				{
					m[x ^ 1].insert(z2);
					continue;
				}
				set<tuple<int, int, int, int, int> >::iterator v = m[x ^ 1].lower_bound(z);
				int a2 = get<0> (*v);
				int b2 = get<1> (*v);
				int c2 = get<2> (*v);
				int d2 = get<3> (*v);
				int e2 = get<4> (*v);
				if(a2 == c && b2 == ar[i] && c2 == -1 && d2 == -1)
				{
					m[x ^ 1].erase(v);
					m[x ^ 1].insert(make_tuple(c, ar[i], -1, -1, e + e2));
				}
				else m[x ^ 1].insert(z2);
				continue;
			}
			if(ar[i] < b)
			{
				ans += e;
				tuple<int, int, int, int, int> z = make_tuple(a, ar[i], -1, -1, 0);
				tuple<int, int, int, int, int> z2 = make_tuple(a, ar[i], -1, -1, e);
				if(m[x ^ 1].empty())
				{
					m[x ^ 1].insert(z2);
					continue;
				}
				set<tuple<int, int, int, int, int> >::iterator v = m[x ^ 1].lower_bound(z);
				int a2 = get<0> (*v);
				int b2 = get<1> (*v);
				int c2 = get<2> (*v);
				int d2 = get<3> (*v);
				int e2 = get<4> (*v);
				if(a2 == a && b2 == ar[i] && c2 == -1 && d2 == -1)
				{
					m[x ^ 1].erase(v);
					m[x ^ 1].insert(make_tuple(a, ar[i], -1, -1, e + e2));
				}
				else m[x ^ 1].insert(z2);
				continue;
			}					
		}
		ans++;
		m[x ^ 1].insert(make_tuple(ar[i], n + 1, 0, ar[i], 1));
	}
	printf("%lld\n", ans);
	return 0;
}