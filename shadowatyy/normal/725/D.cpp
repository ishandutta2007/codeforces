#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 300007

ll n, T, W, c;

ll t[N];

ll w[N];

struct compt
{
	bool operator()(const int &a, const int &b)
	{
		return t[a]>t[b];
	}
};

struct compd
{
	bool operator()(const int &a, const int &b)
	{
		return w[a]-t[a]<w[b]-t[b];
	}
};

multiset<int, compt> przedt;
multiset<int, compt> pot;
multiset<int, compd> przedd;
multiset<int, compd> pod;

int res[N];

int result = inf, Index;

int main()
{
	scanf("%lld", &n);

	--n;

	scanf("%lld%lld", &T, &W);

	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld%lld", t+i, w+i);

		if(t[i]>T)
		{
			przedt.insert(i);
			przedd.insert(i);
		}
		else
		{
			pot.insert(i);
			pod.insert(i);
		}
	}

	res[++c] = przedt.size()+1;

	while(!przedd.empty() && w[*przedd.begin()]-t[*przedd.begin()]+1<=T)
	{
		Index = *przedd.begin();
		przedd.erase(przedd.equal_range(Index).st);
		przedt.erase(przedt.equal_range(Index).st);

		T -= w[Index]-t[Index]+1;

		while(!pot.empty() && t[*pot.begin()]>T)
		{
			Index = *pot.begin();
			pot.erase(pot.equal_range(Index).st);
			pod.erase(pod.equal_range(Index).st);
			przedt.insert(Index);
			przedd.insert(Index);
		}

		res[++c] = przedt.size()+1;
	}

	for(int i = 1; i <= c; ++i)
	{
		result = min(result, res[i]);
	}

	printf("%d", result);

}