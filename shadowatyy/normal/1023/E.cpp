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

bool ask(int a, int b, int c, int d)
{
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	fflush(stdout);
	string ans;
	cin >> ans;
	return (ans=="YES");
}

VPII path, path_rev;

void dfs(int x, int y, int d)
{
	path.eb(x, y);

	if(!d)
		return;

	if(ask(x+1, y, n, n))
		dfs(x+1, y, d-1);
	else
		dfs(x, y+1, d-1);
}

void rev(int x, int y, int d)
{
	path_rev.eb(x, y);

	if(!d)
		return;

	if(ask(1, 1, x, y-1))
		rev(x, y-1, d-1);
	else
		rev(x-1, y, d-1);
}

int32_t main()
{
	cin >> n;
	dfs(1, 1, n-2);
	rev(n, n, n-1);
	reverse(ALL(path_rev));
	path.insert(path.end(), ALL(path_rev));

	cout << "! ";

	for(int i = 0; i < 2*n-2; ++i)
	{
		if(path[i+1].st!=path[i].st)
			cout << "D";
		else
			cout << "R";
	}

	fflush(stdout);
}