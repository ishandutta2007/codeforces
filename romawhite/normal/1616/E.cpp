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
const int MAX = 1 << 20;
const int MOD = 1000000007;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

VI A[26];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		FenwickTree F(n);
		FOR(i,0,n)
			F.add(i, 1);
		string s, t;
		cin >> s >> t;
		string ss = s;
		sort(ALL(ss));
		if (ss >= t) {
			cout << -1 << endl;
			continue;
		}
		FOR(i,0,26)
			A[i].clear();
		FOR(i,0,SZ(s)) {
			A[s[i] - 'a'].push_back(i);
		}
		FOR(i,0,26)
			reverse(ALL(A[i]));
		Int res = LINF;
		Int cur = 0;
		FOR(i,0,n) {
			int c = t[i] - 'a';
			FOR(j,0,c) {
				if (SZ(A[j]))
					res = min(res, cur + F.sum(A[j].back() - 1));
			}
			if (SZ(A[c]) == 0)
				break;
			cur += F.sum(A[c].back() - 1);
			F.add(A[c].back(), -1);
			A[c].pop_back();
		}
		cout << res << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}