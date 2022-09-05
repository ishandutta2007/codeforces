#include <bits/stdc++.h>
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
typedef long long ll;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 5007;
const int MOD = 1000000007; 


int dp[MAX];
int p[MAX];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
 
	
	int n;
	cin >> n;
	int w, h;
	cin >> w >> h;
	vector<pair<PII, int> > A;

	FOR(i,0,n) {
		int x, y;
		cin >> x >> y;
		if (x <= w || y <= h)
			continue;
		A.push_back(MP(MP(x, y), i));
	}

	sort(ALL(A));


	FILL(dp, 0);

	FOR(i,0,SZ(A)) {
		dp[i] = 1;
		p[i] = -1;

		FOR(j,0,i) {
			if (A[i].first.first > A[j].first.first && A[i].first.second > A[j].first.second && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}

	}


	int id = -1;
	int best = -1;
	FOR(i,0,SZ(A)) {
		if (dp[i] > best) {
			best = dp[i];
			id = i;
		}
	}
	if (best == -1)
		best = 0;
	cout << best << endl;
	if (best == 0)
		return 0;
	VI X;
	while (id != -1) {
		X.push_back(A[id].second);
		id = p[id];
	}
	reverse(ALL(X));
	FOR(i,0,SZ(X)) {
		cout << X[i] + 1 << ' ';
	}
	

	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}