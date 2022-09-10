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
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

int n, ax, ay, bx, by, cx, cy;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

	if(bool(bx<ax)==bool(cx<ax) && bool(by<ay)==bool(cy<ay))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}