#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

map < pair < int, int >, set < vector < int > > > M;

set < vector < int > > solve(vector < int > &a, int l, int r) {
    if (M.count(make_pair(l, r))) {
        return M[make_pair(l, r)];
    }
    if (l == r) {
        vector < int > res(a.size());
        res[l] = 1;
        set < vector < int > > S;
        S.insert(res);
        return M[make_pair(l, r)] = S;
    }

    set < vector < int > > res;
    for (int i = l; i < r; ++i) {
        set < vector < int > > x = solve(a, l, i);
        set < vector < int > > y = solve(a, i + 1, r);

        for (auto& u : y) {
            for (auto& v : x) {
                vector < int > w = u;
                for (int j = 0; j < w.size(); ++j) {
                    w[j] -= v[j];
                }
                res.insert(w);
            }
        }
    }
    return M[make_pair(l, r)] = res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    /*while (true) {
        M.clear();
        int n;
        cin >> n;
        vector < int > a(n);

        set < vector < int > > x = solve(a, 0, n - 1);
        for (auto& key : x) {
            for (auto& y : key) {
                cout << (y > 0 ? '+' : '-');
            }
            cout << endl;
        }

        cout << x.size() << endl;
    }*/

    long long n, T;
    cin >> n >> T;
    string s;
    cin >> s;

    vector < int > a(n);
    for (int i = 0; i < s.size(); ++i) {
        a[i] = s[i] - 'a';
    }

    long long score = (1 << a[n - 1]) - (1 << a[n - 2]);
    T -= score;

    vector < int > cnt(26);
    for (int i = 0; i < n - 2; ++i) {
        ++cnt[a[i]];
    }

    vector < long long > L(26), R(26);
    for (int i = 0; i < 26; ++i) {
        L[i] = -cnt[i];
        R[i] = cnt[i];
        L[i] *= (1LL << i);
        R[i] *= (1LL << i);

        if (i > 0) {
            L[i] += L[i - 1];
            R[i] += R[i - 1];
        }
    }

    for (int i = 25; i > 0; --i) {
        if (T > R[i] || T < L[i]) {
            cout << "No" << endl;
            return 0;
        }

        bool ok = false;
        for (int j = -cnt[i]; j <= cnt[i]; j += 2) {
            long long nT = T + (long long)(j) * (1LL << i);
            if (nT >= L[i - 1] && nT <= R[i - 1]) {
                T = nT;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }

    if ((T + cnt[0]) % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}