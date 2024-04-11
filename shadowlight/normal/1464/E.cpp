#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, m;

int mex(vector<int>& a) {
	vector <int> exists(a.size() + 1, 0);
	for (int x : a) {
		if (x >= exists.size()) continue;
		exists[x] = 1;
	}
	for (int i = 0; i < a.size() + 1; ++i) {
		if (!exists[i]) {
			return i;
		}
	}
	assert(false);
}

vector <vector <int>> gr;
vector <int> dp;

int lazy(int v) {
	if (dp[v] != -1) {
		return dp[v];
	}
	vector <int> vals;
	for (int u : gr[v]) {
		vals.pb(lazy(u));
	}
	return dp[v] = mex(vals);
}

const int MOD = 998244353;

class GaussModulo {
    const int mod = 998244353;

public:
    enum GaussSolution {
        ZERO, ONE, MANY
    };

    int n;
    GaussSolution solutions_cnt;
    vector<int> solutions;

    // eqs = A|b
    // A*x = b
    GaussModulo(vector< vector<int> >& eqs) {
        n = (int)eqs.back().size() - 1;
        solutions.resize(n, 0);

        int cur_eq = 0;
        for (int v = 0; v < n; v++) {
            int correct_eq_num = -1;
            for (int eq_num = cur_eq; eq_num < eqs.size(); eq_num++) {
                if (eqs[eq_num][v] != 0) {
                    correct_eq_num = eq_num;
                    break;
                }
            }

            if (correct_eq_num == -1) continue;

            swap(eqs[cur_eq], eqs[correct_eq_num]);

            int rev_val = get_rev(eqs[cur_eq][v]);
            for (int i = v; i < eqs[cur_eq].size(); i++) {
                eqs[cur_eq][i] = mult(eqs[cur_eq][i], rev_val);
            }

            for (int eq_num = cur_eq + 1; eq_num < eqs.size(); eq_num++) {
                int cur_val = eqs[eq_num][v];
                for (int i = v; i < eqs[eq_num].size(); i++) {
                    eqs[eq_num][i] -= mult(eqs[cur_eq][i], cur_val);
                    if (eqs[eq_num][i] < 0) eqs[eq_num][i] += mod;
                }
            }

            cur_eq++;
        }

        for (int i = cur_eq; i < eqs.size(); i++) {
            if (eqs[i].back() != 0) {
                solutions_cnt = ZERO;
                return;
            }
        }

        if (cur_eq < n) {
            solutions_cnt = MANY;
        } else {
            solutions_cnt = ONE;
        }

        for (int v = n - 1; v >= 0; v--) {
            int pos = -1;
            for (int i = 0; i + 1 < eqs[v].size(); ++i) {
                if (eqs[v][i] != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) continue;
            solutions[pos] = eqs[v].back();

            for (int eq_num = v - 1; eq_num >= 0; eq_num--) {
                eqs[eq_num].back() -= mult(eqs[eq_num][pos], eqs[v].back());
                if (eqs[eq_num].back() < 0) eqs[eq_num].back() += mod;
                eqs[eq_num][pos] = 0;
            }
        }
    }

    int mult(int a, int b){
        return a * (ll)b % mod;
    }
    
    int pow(int a, int n) {
        int res = 1;
        while (n) {
            if (n & 1) res = mult(res, a);
            a = mult(a, a);
            n >>= 1;
        }
        return res;
    }

    int get_rev(int val) {
        return pow(val, mod - 2);
    }
};

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	gr.resize(n);

	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		gr[v].pb(u);
	}
	dp.resize(n, -1);

	for (int i = 0; i < n; ++i) {
		lazy(i);
	}


	int mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, dp[i]);
	}
	
	int val = 1;
	while (val <= mx) {
		val *= 2;
	}
	vector <int> ways(val, 0);
	for (int i = 0; i < n; ++i) {
		++ways[dp[i]];
	}

	vector <vector <int>> eqs;

	for (int i = 0; i < val; ++i) {
		vector <int> now(val + 1, 0);
		now[i] += (n + 1);
		for (int t = 0; t < val; ++t) {
			assert((t ^ i) < val);
			now[t] -= ways[t ^ i];  
		}
		if (!i) {
			now.back() = 1;
		}
		for (int &x : now) {
			if (x < 0) {
				x += MOD;
			}
		}
		eqs.pb(now);
	}

	GaussModulo gauss(eqs);
	assert(gauss.solutions_cnt == GaussModulo::GaussSolution::ONE);

	cout << (1 - gauss.solutions[0] + MOD) % MOD << "\n";
}