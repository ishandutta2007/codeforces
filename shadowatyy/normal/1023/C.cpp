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

int n, k;

string s;

VI ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> s;

	int chce = k/2;

	for(int i = 0; i < n; ++i)
	{
		if(chce>0 && s[i]=='(')
		{
			ans.pb(i);
			--chce;
		}
	}

	chce = k/2;

	for(int i = n-1; i >= 0; --i)
	{
		if(chce>0 && s[i]==')')
		{
			ans.pb(i);
			--chce;
		}
	}

	sort(ALL(ans));

	for(auto it:ans)
		cout << s[it];
}