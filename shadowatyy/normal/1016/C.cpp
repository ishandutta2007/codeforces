#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll
const int N = 3e5+7;

int n;

int a[N];
int b[N];
int pa[N];
int pb[N];
int g[N];
int d[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pa[i] = a[i] + pa[i-1];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		pb[i] = b[i] + pb[i-1];
	}

	for(int i = n; i >= 1; --i)
	{
		g[i] = a[i] + 2*(n-i+1)*b[i] + g[i+1] + pa[n]-pa[i] + pb[n]-pb[i];
		d[i] = b[i] + 2*(n-i+1)*a[i] + d[i+1] + pa[n]-pa[i] + pb[n]-pb[i];
	}

	int curr = 0, ans = g[1], sum = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(i%2==1) //dol
		{
			sum += (curr+1)*a[i];
			sum += (curr+2)*b[i];
			curr += 2;
			ans = max(ans, sum + d[i+1] + curr*(pa[n]-pa[i] + pb[n]-pb[i]));
		}
		else
		{
			sum += (curr+1)*b[i];
			sum += (curr+2)*a[i];
			curr += 2;
			ans = max(ans, sum + g[i+1] + curr*(pa[n]-pa[i] + pb[n]-pb[i]));
		}
	}

	cout << ans - pa[n] - pb[n] << endl;
}