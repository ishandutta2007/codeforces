#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 200007

int S, K;

string s, k;

int nast[N][26];

int last[26];

bitset<N> del;

int p[N];

bool bs(int a)
{
	del.reset();

	for(int i = 1; i <= a; ++i)
	{
		del[p[i]] = 1;
	}

	int pos = 0;

	for(int i = 1; i <= K; ++i)
	{
		pos = nast[pos][k[i]-'a'];

		while(del[pos])
			pos = nast[pos][k[i]-'a'];
		
		if(!pos)
			return 0;
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> s >> k;

	S = s.size();
	K = k.size();

	s = '#'+s;
	k = '#'+k;

	for(int i = S; i >= 0; --i)
	{
		for(int j = 0; j < 26; ++j)
		{
			nast[i][j] = last[j];
		}
		
		if(i>0)
			last[s[i]-'a'] = i;
	}

	for(int i = 1; i <= S; ++i)
	{
		cin >> p[i];
	}

	int l = 0, r = S, m = -1;

	while(l<r)
	{
		m = (l+r)/2;

		if(l==m)
			++m;

		if(bs(m))
			l = m;
		else
			r = m-1;
	}

	cout << l;
}