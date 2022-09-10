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

const int N = 1e5+7;

int n, m;

string s;

bitset<N> b[26];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();

	for(int i = 0; i < n; ++i)
	{
		b[s[i]-'a'][i] = 1;
	}

	cin >> m;

	while(m--)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int i;
			char c;
			cin >> i >> c;
			--i;
			b[s[i]-'a'][i] = 0;
			s[i] = c;
			b[s[i]-'a'][i] = 1;
		}
		else
		{
			int l, r;
			string q;
			cin >> l >> r >> q;
			--l;
			--r;

			if(q.size()>r-l+1)
				cout << 0 << endl;
			else
			{
				bitset<N> ans;
				ans.set();

				for(int i = 0; i < q.size(); ++i)
				{
					ans &= b[q[i]-'a']>>i;
				}

				cout << (ans>>l).count() - (ans>>(r-q.size()+2)).count() << endl;
			}
		}
	}
}