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
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 100007;
const int MOD = 998244353;

Int f(Int c0, Int c1, Int a, Int b, int t) {
	Int res = min(c0, c1) * (a + b);
	if (c0 > c1 && t == 0)
		res += a;
	if (c1 > c0 && t == 1)
		res += b;
	return res;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		Int a, b, c;
		cin >> n >> a >> b >> c;
		
		string s;
		cin >> s;
		vector<PII> A;
		int cnt = 1;
		FOR(i,1,SZ(s)) {
			if (s[i] == s[i - 1])
				++ cnt;
			else {
				A.push_back(MP(s[i - 1] - '0', cnt));
				cnt = 1;
			}
		}
		A.push_back(MP(s.back() - '0', cnt));

		int c1 = 0;
		int c0 = 0;
		int g0 = 0;
		int g1 = 1;
		FOR(i,0,SZ(A))
			if (A[i].first == 1) {
				c1 += A[i].second - 1;
				g1 ++;
			} else {
				c0 += A[i].second - 1;
				g0 ++;
			}
		VI B;
		FOR(i,1,SZ(A) - 1) {
			if(A[i].first == 0)
				B.push_back(A[i].second);
		}
		if (A[0].first == 0)
			B.push_back(INF);
		if (SZ(A) > 1 && A.back().first == 0)
			B.push_back(INF);
		sort(ALL(B));
		Int res = max(f(c0, c1, a, b, 0), f(c0, c1, a, b, 1));

		int steps = c1;
		Int cc1 = c1;
		FOR(i,0,g0) {
			if (i < SZ(B)) {
				steps = steps - (B[i] - 1);
				if (steps >= 0)
					cc1 ++;
			}
			Int cc0 = c0 + i + 1;
			
			Int cur = f(cc0, cc1, a, b, 0) - 1LL * (i + 1) * (a + c);
			res = max(res, cur);
		}
		cc1 = c1;
		steps = c1 - 1;
		FOR(i,0,g0) {
			if (i < SZ(B)) {
				steps = steps - (B[i] - 1);
				if (steps >= 0)
					cc1 ++;
			}
			Int cc0 = c0 + i + 1;
			Int cur = f(cc0, cc1, a, b, 1) - 1LL * (i + 1) * (a + c);
			res = max(res, cur);
		}
		cout << res << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}