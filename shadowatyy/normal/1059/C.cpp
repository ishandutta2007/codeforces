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

const int N = 1e6+7;

int n;

void solve(int m, int len)
{
	if(len==1)
	{
		cout << m << " ";
	}
	else if(len==2)
	{
		cout << m << " " << 2*m << " ";
	}
	else if(len==3)
	{
		cout << m << " " << m << " " << 3*m << " ";
	}
	else
	{
		for(int i = 1; i <= (len+1)/2; ++i)
			cout << m << " ";

		solve(2*m, len/2);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	solve(1, n);
}