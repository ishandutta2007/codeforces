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

int n;

string s1, s2, k, z;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> s1 >> s2;

	cin >> n;

	cout << s1 << " " << s2 << endl;

	for(int i = 1; i <= n; ++i)
	{
		cin >> k >> z;

		if(s1==k)
			s1 = z;
		else
			s2 = z;

		cout << s1 << " " << s2 << endl;
	}
}