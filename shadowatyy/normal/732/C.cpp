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
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

ll B, D, S, res = 4*INF, resc, b, d, s, Max;

int p(int a)
{
	if(a==0)
		return 0;

	if(a==1)
		return 0;

	if(a==2)
		return 1;

	if(a==3)
		return 0;

	if(a==4)
		return 2;

	if(a==5)
		return 1;

	if(a==6)
		return 1;

	if(a==7)
		return 0;
}

int o(int a)
{
	if(a==0)
		return 0;

	if(a==1)
		return 2;

	if(a==2)
		return 1;

	if(a==3)
		return 1;

	if(a==4)
		return 0;

	if(a==5)
		return 1;

	if(a==6)
		return 0;

	if(a==7)
		return 0;
}

ll poj(int a)
{
	ll bMin = inf, bMax = -inf;

	for(ll i = 0; i < 3; ++i)
	{
		if(a&(1<<i))
		{
			bMin = min(bMin, i);
			bMax = max(bMax, i);
		}
	}

	return bMax-bMin+1-__builtin_popcount(a);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> B >> D >> S;

	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			resc = p(i) + o(j);

			b = B;
			s = S;
			d = D;

			if((i&(4)))
				--b;

			if((j&(4)))
				--b;

			if((i&(2)))
				--d;

			if((j&(2)))
				--d;

			if((i&(1)))
				--s;

			if((j&(1)))
				--s;

			if(b>=0 && d>=0 && s>=0)
			{
				Max = b;
				Max = max(Max, d);
				Max = max(Max, s);

				resc += Max-d;
				resc += Max-s;
				resc += Max-b;

				res = min(res, resc);
			}

		}
	}

	if(B<=1 && D<=1 && S<=1)
	{
		int l = 0;

		if(B)
			l += 4;

		if(D)
			l += 2;

		if(S)
			l += 1;

		res = min(res, poj(l));
	}

	cout << res;

}