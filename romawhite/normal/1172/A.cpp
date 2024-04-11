#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const Int LINF = INF * (Int) INF;
 
const int MAX = 200007;
 
const int MOD = 987654319;

int a[MAX];
int b[MAX];
int pos[MAX];

int main(int argc, char* argv[])
{
	// freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	FOR(i,0,n)
	{
		scanf("%d", &a[i]);
		--a[i];
	}
	FOR(i,0,n)
	{
		scanf("%d", &b[i]);
		--b[i];
	}
	FILL(pos, -1);
	FOR(i,0,n)
	{
		if (b[i] != -1)
		{
			pos[b[i]] = i;
		}
	}
	int res = n;
	FOR(i,0,n)
	{
		if (pos[i] != -1)
		{
			res = max(res , pos[i] + 1 + n - i);
		}
	}
	if (pos[0] != -1)
	{
		int ps = pos[0];
		bool ok = true;
		FOR(i,ps, n)
		{
			if (b[i] != i - ps)
				ok = false;
		}

		int cur = n - ps;
		
		set<int> S;
		FOR(i,0,n)
		{
			if (a[i] != -1)
				S.insert(a[i]);
		}
		FOR(i,0,ps)
		{
			if (S.find(cur + i) == S.end())
			{
				ok = 0;
				break;
			}
			S.insert(b[i]);
		}
		if (ok)
		{
			cout << ps << endl;
			return 0;
		}
		
	}
	cout << res << endl;

	

	// cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
}