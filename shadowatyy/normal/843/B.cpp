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
#define SIZE(x) (int)(x).size()
#define flush fflush(stdout)
using namespace std;

#define next sjsajfkasjif
#define N 50007

int n, s, x;

int val[N];
int next[N];

int32_t main()
{
	srand(time(NULL));

	cin >> n >> s >> x;

	cout << "? " << s << endl;
	flush;
	cin >> val[s] >> next[s];

	if(val[s]>=x)
	{
		cout << "! " << val[s] << endl;
		flush;
		exit(0);
	}

	for(int i = 1; i <= 1000; ++i)
	{
		int x = ((ll)rand()*2137+rand())%n+1;

		if(!next[x])
		{
			cout << "? " << x << endl;
			flush;
			cin >> val[x] >> next[x];
		}
	}

	int op = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(next[i])
		{
			if(val[i]<=x && (op==-1 || val[op]<val[i]))
				op = i;
		}
	}

	if(op==-1)
	{
		cout << "! -1" << endl;
		flush;
		exit(0);
	}

	while(op!=-1)
	{
		if(!next[op])
		{
			cout << "? " << op << endl;
			flush;
			cin >> val[op] >> next[op];
		}

		if(val[op]>=x)
		{
			cout << "! " << val[op] << endl;
			flush;
			exit(0);
		}

		op = next[op];
	}

	cout << "! -1" << endl;
	flush;
	exit(0);
}