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

int ask(int x)
{
	if(x>n)
		x -= n;

	cout << "? " << x << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

void ans(int x)
{
	cout << "! " << x << endl;
	fflush(stdout);
	exit(0);
}

void solve(int l, int r, int vl, int vr)
{
	if(l==r)
		ans(l);

	if(r-l+1<=3)
	{
		for(int i = l; i <= r; ++i)
		{
			int a = ask(i);
			int b = ask(i+n/2);

			if(a==b)
				ans(i);
		}

		ans(-1);
	}

	int m = (l+r)/2;
	int a = ask(m);
	int b = ask(m+n/2);
	int vm = a-b;

	if(vm==0)
		ans(m);

	if(vl<vr)
	{
		if(vm>0)
			solve(l, m, vl, vm);
		else
			solve(m, r, vm, vr);
	}
	else
	{
		if(vm<0)
			solve(l, m, vl, vm);
		else
			solve(m, r, vm, vr);
	}
}

int32_t main()
{
	cin >> n;

	if((n/2)%2)
		ans(-1);

	int a = ask(1);
	int b = ask(1+n/2);

	if(a==b)
		ans(1);

	solve(1, 1+n/2, a-b, b-a);
}