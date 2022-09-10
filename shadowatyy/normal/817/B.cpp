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
#define flush fflush(stdout)
using namespace std;

#define int long long
#define N 100007

int n, res;

int s[N];

map<int, int> ile;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		++ile[s[i]];
	}

	sort(s+1, s+n+1);

	if(s[1]==s[2] && s[2]==s[3])
		cout << ile[s[1]]*(ile[s[1]]-1)*(ile[s[1]]-2)/6;
	else if(s[1]==s[2])
		cout << ile[s[1]]*(ile[s[1]]-1)/2*ile[s[3]];
	else if(s[2]==s[3])
		cout << ile[s[1]]*ile[s[2]]*(ile[s[2]]-1)/2;
	else
		cout << ile[s[1]]*ile[s[2]]*ile[s[3]];
}