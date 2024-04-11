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

int k, a, b, f, s;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> k >> a >> b;

	f = a/k;
	s = b/k;

	if(f+s>0 && (a%k==0 || s>0) && (b%k==0 || f>0))
		cout << f+s;
	else
		cout << -1;
}