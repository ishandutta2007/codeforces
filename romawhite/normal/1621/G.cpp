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
const int MOD = 1000000007;

struct FenwickTree {
    vector<Int> bit;  // binary indexed tree
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
        Int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret % MOD;
    }

    int sum(int l, int r) {
        return (sum(r) - sum(l - 1) + MOD) % MOD;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += delta;
			bit[idx] %= MOD;
		}
    }
};

vector<Int> calc(VI A) {
	int n = SZ(A);
	FenwickTree F(n);
	vector<Int> res(n);
	FOR(i,0,n) {
		res[i] = (F.sum(A[i] - 1) + 1) % MOD;
		F.add(A[i], res[i]);
	}
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
		cin >> n;
		VI A(n);
		VI X;
		FOR(i,0,n) {
			cin >> A[i];
			X.push_back(A[i]);
		}
		sort(ALL(X));
		X.resize(unique(ALL(X)) - X.begin());
		FOR(i,0,n) {
			A[i] = lower_bound(ALL(X), A[i]) - X.begin();
		}

		Int res = 0;
		auto c0 = calc(A);
		VI AA = A;
		reverse(ALL(AA));
		FOR(i,0,SZ(AA))
			AA[i] = SZ(X) - 1 - AA[i];
		auto c1 = calc(AA);
		FOR(i,0,n) {
			res += c0[i] * c1[n - 1 - i] % MOD;
			res %= MOD;
		}
		vector<PII> B;
		FOR(i,0,n) {
			B.push_back(MP(A[i], -i));
		}
		sort(ALL(B));
		reverse(ALL(B));
		FOR(i,0,n)
			B[i].second = -B[i].second;
		FenwickTree F(n);
		Int sub = 0;
		map<int, pair<int, Int> > M;
		FOR(i,0,SZ(B)) {
			int p = B[i].second;
			int val = B[i].first;
			if (SZ(M) && M.rbegin()->first < p)  {
				while (SZ(M) && M.begin()->first < p) {
					int id = M.begin()->second.first;
					Int c = M.begin()->second.second;
					F.add(id, MOD - c);
					M.erase(M.begin());
				}
			}
			Int d = F.sum(p + 1, n - 1);
			if (SZ(M) == 0)
				d = 1;
			sub += d * c0[p] % MOD;
			sub %= MOD;
			F.add(p, d);
			M[p] = MP(p, d);
		}
		res = (res - sub + MOD) % MOD;
		cout << res << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}