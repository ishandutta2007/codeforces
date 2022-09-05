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
const int MAX = 707;
const int MOD = 1000000007; 
 
int dp[MAX][MAX][2][2];
 
int nx[MAX];

string s;

int f(int l, int r, bool a, bool b) {
	if (l > r) return 1;
	int & res = dp[l][r][a][b];
	if (res != -1)
		return res;
	res = 0;
	int m = nx[l];
	Int A = f(l + 1, m - 1, 1, 0);
	if (m != r) {
		A *= f(m + 1, r, 0, b);
	}
	A %= MOD;
	A *= 2 - a;
	A %= MOD;
	res += A;

	A = f(l + 1, m - 1, 0, 1);
	if (m != r) {
		A *= f(m + 1, r, 1, b);
	}
	A %= MOD;
	if (b == 0 || m < r) {
		A *= 2;
		A %= MOD;
	}
	res += A;
	res %= MOD;
	return res;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
 
	FILL(dp, -1);

	
	cin >> s;
	VI A;
	FOR(i,0,SZ(s)) {
		if (s[i] == '(')
			A.push_back(i);
		else
		{
			nx[A.back()] = i;
			A.pop_back();
		}
		
	}

	cout << f(0, SZ(s) - 1, 0, 0) << endl;

	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}