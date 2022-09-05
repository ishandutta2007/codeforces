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
const int MAX = 200007;
const int MOD = 998244353;

int R[MAX];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		VI A(n);
		FOR(i,0,n) {
			cin >> A[i];
		}

		set<int> S;
		FOR(i,0,n + 2) {
			S.insert(i);
		}
		RFOR(i,n,0) {
			if (S.find(A[i]) != S.end())
				S.erase(A[i]);
			R[i] = *S.begin();
		}

		VI res;
		int i = 0;
		while (i < n) {
			res.push_back(R[i]);
			set<int> T;
			FOR(j,0,R[i])
				T.insert(j);
			bool first = true;
			while (SZ(T) || first) {
				first = false;
				if (T.find(A[i]) != T.end())
					T.erase(A[i]);
				++ i;
			}
		}
		cout << SZ(res) << endl;
		for(int x: res) {
			cout << x << ' ';
		}
		cout << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}