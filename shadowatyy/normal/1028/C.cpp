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

#define y1 abbababab
const int N = 2e5+7;

int n;

int x1[N];
int x2[N];
int y1[N];
int y2[N];
int sx1[N];
int sx2[N];
int sy1[N];
int sy2[N];
int px1[N];
int px2[N];
int py1[N];
int py2[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}

	px1[1] = x1[1];
	px2[1] = x2[1];
	py1[1] = y1[1];
	py2[1] = y2[1];

	for(int i = 2; i <= n; ++i)
	{
		px1[i] = max(px1[i-1], x1[i]);
		px2[i] = min(px2[i-1], x2[i]);
		py1[i] = max(py1[i-1], y1[i]);
		py2[i] = min(py2[i-1], y2[i]);
	}

	sx1[n] = x1[n];
	sx2[n] = x2[n];
	sy1[n] = y1[n];
	sy2[n] = y2[n];

	for(int i = n-1; i >= 1; --i)
	{
		sx1[i] = max(sx1[i+1], x1[i]);
		sx2[i] = min(sx2[i+1], x2[i]);
		sy1[i] = max(sy1[i+1], y1[i]);
		sy2[i] = min(sy2[i+1], y2[i]);
	}

	if(px1[n-1]<=px2[n-1] && py1[n-1]<=py2[n-1])
	{
		cout << px1[n-1] << " " << py1[n-1] << endl;
		return 0;
	}

	if(sx1[2]<=sx2[2] && sy1[2]<=sy2[2])
	{
		cout << sx1[2] << " " << sy1[2] << endl;
		return 0;
	}

	for(int i = 2; i <= n-1; ++i)
	{
		if(max(px1[i-1], sx1[i+1])<=min(px2[i-1], sx2[i+1]) && max(py1[i-1], sy1[i+1])<=min(py2[i-1], sy2[i+1]))
		{
			cout << max(px1[i-1], sx1[i+1]) << " " << max(py1[i-1], sy1[i+1]) << endl;
			return 0;
		}
	}
}