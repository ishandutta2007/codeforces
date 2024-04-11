#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include "unordered_set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
pair<int, vector<int>> slv(int n) {
    vector<int> a(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] + a[j] <= n) {
                res++;
                cnt[a[i] + a[j] - 1]++;
            }
        }
    }
    return {res, cnt};
}
int chc(vector<int> a) {
    map<int, int> m;
    for (int i = 0; i < a.size(); ++i) {
        m[a[i]] = 1;
    }
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (m[a[i] + a[j]])
                res++;
        }
    }
    return res;
}
void repair(vector<int> &a) {
    if (a[0] == -1)
        a[0] = 1;
    if (a[1] == -1)
        a[1] = a[0] + 1;
    bool fir = 1;
    for (int i = 2; i < a.size(); ++i) {
        if (a[i] == -1) {
            if (fir) {
                a[i] = a[i - 1] + a[i - 2] + 1;
                if (a[i] % 2 == 0)
                    a[i]++;
                fir = 0;
            } else {
                a[i] = a[i-1] + (int)1e5;
            }
        }
    }
}
int val(int n, int m) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    auto [res, ccnt] = slv(n);
    if (m > res) {
        return m;
    }
    res -= m;
    for (int i = n - 1; i >= 0; --i) {
        int cnt = ccnt[i];
        if (res >= cnt) {
            a[i] = -1;
            res -= cnt;
        } else {
            while (res) {
                a[i] += 2;
                res--;
            }
            repair(a);
            return chc(a);
        }
    }
    repair(a);
    return chc(a);
}
void sl() {
    int n = rand() % 7 + 2;
    int m = rand() % 100;
    if (val(n, m) != m) {
        cout << n << ' ' << m;
        exit(0);
    } else {
        cout << 1 << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    //while (1)
     //   sl();
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    auto [res, ccnt] = slv(n);
    if (m > res) {
        cout << -1 << '\n';
        return 0;
    }
    res -= m;
    for (int i = n - 1; i >= 0; --i) {
        int cnt = ccnt[i];
        if (res >= cnt) {
            a[i] = -1;
            res -= cnt;
        } else {
            while (res) {
                a[i] += 2;
                res--;
            }
            repair(a);
            for (int j = 0; j < n; ++j) {
                cout << a[j] << ' ';
            }
            return 0;
        }
    }
    repair(a);
    for (int j = 0; j < n; ++j) {
        cout << a[j] << ' ';
    }
    return 0;
}