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
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 200007;
 
const int MOD = 1000000007;
 
const double Pi = acos(-1.0);

int a[MAX];

int res[MAX];

int main(int argc, char* argv[])
{
    // freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false); cin.tie(0);
 
    int n;
	cin >> n;

	int mx = 0;
	int mn = INF;

	FOR(i,0,n)
	{
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}

	if (2 * mn >= mx)
	{
		FOR(i,0,n)
		{
			cout << -1 << ' ';
		}
		cout << endl;
		return 0;
	}

	multiset<int> S;
	int r = 1;
	S.insert(a[0]);
	mx = a[0];
	while (true)
	{
		if (2 * a[r] >= mx)
		{
			S.insert(a[r]);
			mx = max(mx, a[r]);
			r = (r + 1) % n;
		}
		else
			break;
	}

	res[0] = SZ(S);

	RFOR(i,n,1)
	{
		while (SZ(S))
		{
			int val = *S.begin();
			if (val * 2 < a[i])
			{
				r = (r - 1 + n) % n;
				S.erase(S.find(a[r]));
			}
			else
			{
				break;
			}
		}
		S.insert(a[i]);
		res[i] = SZ(S);
	}

	FOR(i,0,n)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

 
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}