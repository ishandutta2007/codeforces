#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

int x[3];
int y[3];

vector<PII> res;

void licz(int a, int b, int c)
{
	res.eb(x[a]+(x[c]-x[b]), y[a]+(y[c]-y[b]));
}		

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> x[1] >> y[1];
	cin >> x[2] >> y[2];
	cin >> x[3] >> y[3];

	licz(1, 2, 3);
	licz(1, 3, 2);
	licz(2, 1, 3);
	licz(2, 3, 1);
	licz(3, 1, 2);
	licz(3, 2, 1);

	sort(res.begin(), res.end());

	res.erase(unique(res.begin(), res.end()), res.end());

	cout << res.size() << endl;

	for(auto it:res)
		cout << it.st << " " << it.nd << endl;
}