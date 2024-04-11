#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

int n, ans;

string s;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();
	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		int o = 0, c = 0, z = 0, sum = 0;

		for(int j = i; j <= n; ++j)
		{
			if(s[j]=='(')
			{
				++o;
				++sum;
			}
			else if(s[j]==')')
			{
				++c;
				--sum;
			}
			else
			{
				++z;
				++sum;
			}

			while(2*z>sum)
			{
				++o;
				--z;
			}

			if(sum<0)
				break;

			if((j-i+1)%2==0 && o<=(j-i+1)/2 && c<=(j-i+1)/2)
				++ans;
		}
	}

	cout << ans;
}