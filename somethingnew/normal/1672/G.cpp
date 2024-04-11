//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
int mod = 998244353;
void solveevev(vector<string> &table) {
    int res = 1;
    for (int i = 0; i < table.size(); ++i) {
        for (auto j : table[i]) {
            if (j == '?') {
                res = res * 2 % mod;
            }
        }
    }
    cout << res;
}
void solveevodd(vector<string> &table, int n, int m) {
    if (n % 2 == 1) {
        swap(n, m);
        vector<string> t2(n, string(m, '?'));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                t2[i][j] = table[j][i];
            }
        }
        table = t2;
    }
    vector<int> mayadd(n), cnt(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == '1')
                cnt[i] ^= 1;
            if (table[i][j] == '?')
                mayadd[i]++;
        }
    }
    int res = 0, tempres = 1;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 0 and mayadd[i] == 0) {
            tempres = 0;
            break;
        }
        for (int j = 0; j < mayadd[i] - 1; ++j) {
            tempres = tempres * 2 % mod;
        }
    }
    res = tempres;tempres = 1;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 1 and mayadd[i] == 0) {
            tempres = 0;
            break;
        }
        for (int j = 0; j < mayadd[i] - 1; ++j) {
            tempres = tempres * 2 % mod;
        }
    }
    res += tempres;
    res %= mod;
    cout << res;
}
struct dsu{
    vector<int> p;
    vector<int> vals;
    void make(int nplusm, vector<int> vls) {
        vals = vls;
        p.assign(nplusm, 0);
        for (int i = 0; i < nplusm; ++i) {
            p[i] = i;
        }
    }
    int getv(int v) {
        if (p[v] == v)
            return v;
        return p[v] = getv(p[v]);
    }
    bool merge(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a == b)
            return 0;
        p[a] = b;
        vals[b] ^= vals[a];
        return 1;
    }
};
int solveoddodd(vector<string> &table, int n, int m, char one) {
    vector<int> cntn(n), cntm(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == one) {
                cntn[i] ^= 1;
                cntm[j] ^= 1;
            }
        }
    }
    for (auto i : cntm)
        cntn.push_back(i);
    dsu ds;
    int res = 1;
    ds.make(n+m, cntn);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == '?') {
                if (!ds.merge(i, j+n)) {
                    res = res * 2 % mod;
                }
            }
        }
    }
    for (int i = 0; i < n + m; ++i) {
        if (ds.vals[i] != 0 and ds.p[i] == i)
            res = 0;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }
    if (n % 2 == 0 and m % 2 == 0) {
        solveevev(table);
        return 0;
    }
    if (n % 2 == 0 or m % 2 == 0) {
        solveevodd(table, n, m);
        return 0;
    }
    cout << (solveoddodd(table, n, m, '1') + solveoddodd(table, n, m, '0')) % mod;
}