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
using namespace std;

string s[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

string t;	

int ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	for(int i = 0; i < t.size(); ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			if(t.substr(i, s[j].size())==s[j])
				++ans;
		}
	}

	if(ans==1)
		cout << "YES";
	else
		cout << "NO";
}