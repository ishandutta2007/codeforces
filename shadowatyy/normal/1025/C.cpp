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

int n, ans;

string s;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();
	s = s+s;

	int curr = 1;
	ans = curr;

	for(int i = 1; i < s.size(); ++i)
	{
		if(s[i]!=s[i-1])
			++curr;
		else
			curr = 1;

		ans = max(ans, curr);
	}

	cout << min(n, ans) << endl;
}