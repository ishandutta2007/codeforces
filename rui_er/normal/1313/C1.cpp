//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1001;

ll n;
ll m[MAXN];
deque<ll> q;
vector<deque<ll> > v;
ll ans, pos, sum;

int main()
{
	scanf("%lld", &n); 
	for(ll i=1;i<=n;i++) scanf("%lld", &m[i]);
	for(ll i=1;i<=n;i++)
	{
		q.clear();
		q.push_front(m[i]);
		sum = m[i];
		for(ll j=i-1;j>=1;j--)
		{
			q.push_front(min(m[j], q.front()));
			sum += q.front();
		}
		for(ll j=i+1;j<=n;j++)
		{
			q.push_back(min(m[j], q.back()));
			sum += q.back();
		}
		v.push_back(q);
		if(sum > ans)
		{
			ans = sum;
			pos = i;
		}
	}
	deque<ll> d = v[pos-1];
	while(!d.empty())
	{
		printf("%lld ", d.front());
		d.pop_front();
	}
	return 0;
}