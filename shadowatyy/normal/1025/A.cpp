#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

int n;

string s;

int cnt[26];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	if(n==1)
	{
		cout << "YES" << endl;
		return 0;
	}

	for(int i = 0; i < n; ++i)
	{
		if(++cnt[s[i]-'a']==2)
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}