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

const int N = 2e5+7;

int n, m;

string s, t;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> s >> t;

	int jest = -1;

	for(int i = 0; i < n; ++i)
	{
		if(s[i]=='*')
			jest = i;
	}

	if(jest==-1)
	{
		if(s==t)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else
	{
		string pref = s.substr(0, jest);
		string suf = s.substr(jest+1, inf);

		if(pref.size()+suf.size()<=t.size() && pref==t.substr(0, pref.size()) && suf==t.substr(t.size()-suf.size(), suf.size()))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}