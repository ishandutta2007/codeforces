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


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		bool ok = false;
		vector<string> S(n);
		FOR(i,0,n)
			cin >> S[i];
		FOR(i,0,n) {
			string t = S[i];
			reverse(ALL(t));
			if (t == S[i])
				ok = true;
		}
		set<string> S2;
		set<string> S3;
		set<string> S32;
		for(string s: S) {
			if (SZ(s) == 2) {
				string t = s;
				reverse(ALL(t));
				if (S2.find(t) != S2.end())
					ok = true;
				if (S32.find(t) != S32.end())
					ok = true;
				S2.insert(s);
			} else {
				string t = s;
				reverse(ALL(t));
				if (S3.find(t) != S3.end())
					ok = true;
				t = s.substr(1);
				reverse(ALL(t));
				if (S2.find(t) != S2.end())
					ok = true;
				S3.insert(s);
				S32.insert(s.substr(0, 2));
			}
		}
		if (ok) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}