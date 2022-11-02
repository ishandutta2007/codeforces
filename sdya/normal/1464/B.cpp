#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int maxN = 200000;
const long long inf = 1000000000000000000LL;

string s;
long long x, y;

long long calculate(string& s) {
    int n = s.size();

    long long a = 0, b = 0;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            res += a * x;
            ++b;
        } else if (s[i] == '0') {
            res += b * y;
            ++a;
        }
    }
    return res;
}

long long a[maxN], b[maxN];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    cin >> x >> y;

    vector < int > pos;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            pos.push_back(i);
        }
    }
    {
        int n = s.size();
        int u = 0, v = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++v;
            }
            if (s[i] == '0') {
                ++u;
            }
            if (s[i] == '?') {
                a[i] += v * y;
                b[i] += u * x;
            }
        }
        u = 0, v = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                ++v;
            }
            if (s[i] == '0') {
                ++u;
            }
            if (s[i] == '?') {
                a[i] += v * x;
                b[i] += u * y;
            }
        }
    }

    vector < pair < long long, long long > > r;
    for (int i = 0; i < pos.size(); ++i) {
        r.push_back(make_pair(a[pos[i]], b[pos[i]]));
    }

    vector < long long > sa(pos.size()), sb(pos.size());
    for (int i = 0; i < pos.size(); ++i) {
        sa[i] = a[pos[i]];
        sb[i] = b[pos[i]];
        if (i > 0) {
            sa[i] += sa[i - 1];
            sb[i] += sb[i - 1];
        }
    }

    long long res = inf;

    int m = pos.size();
    if (m == 0) {
        res = 0;
    } else {
        for (int i = 0; i <= m; ++i) {
            long long cur = (i == 0 ? 0 : sa[i - 1]) + (sb[m - 1] - (i == 0 ? 0 : sb[i - 1])) + (long long)(i) * (long long)(m - i) * x;
            res = min(res, cur);

            cur = (i == 0 ? 0 : sb[i - 1]) + (sa[m - 1] - (i == 0 ? 0 : sa[i - 1])) + (long long)(i) * (long long)(m - i) * y;
            res = min(res, cur);
        }
    }
    res += calculate(s);
    cout << res << endl;


    /*int n = pos.size();

    long long w = inf;
    string ans = s;
    for (int i = 0; i < (1 << n); ++i) {
        string t = s;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                t[pos[j]] = '0';
            } else {
                t[pos[j]] = '1';
            }
        }
        long long cur = calculate(t);
        if (cur < w) {
            w = cur;
            ans = t;
        }
    }
    cout << w << endl;
    cout << s << endl << ans << endl;*/

    return 0;
}