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

const int N = 1.5e5+7;

int n;

int a[N];
int b[N];

void check(int x)
{
	for(int i = 1; i <= n; ++i)
	{
		if(a[i]%x && b[i]%x)
			return;
	}

	cout << x << endl;
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
	}

	int curr = a[1];

	for(int i = 2; i*i <= a[1]; ++i)
	{
		if(curr%i==0)
			check(i);
		
		while(curr%i==0)
			curr /= i;
	}

	if(curr>1)
		check(curr);

	curr = b[1];

	for(int i = 2; i*i <= b[1]; ++i)
	{
		if(curr%i==0)
			check(i);
		
		while(curr%i==0)
			curr /= i;
	}

	if(curr>1)
		check(curr);

	cout << -1 << endl;
}