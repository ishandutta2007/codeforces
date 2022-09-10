#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll

int la, ra, ta, lb, rb, tb, ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> la >> ra >> ta >> lb >> rb >> tb;

	if(la>lb)
	{
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}

	int g = __gcd(ta, tb);
	int r = lb-la;
	r %= g;
	int lenb = rb-lb;
	lb = la+r;
	rb = lb+lenb;
	ans = min(ra, rb)-max(la, lb);
	la += g;
	ra += g;
	ans = max(ans, min(ra, rb)-max(la, lb));

	cout << max(0LL, ans+1) << endl;
}