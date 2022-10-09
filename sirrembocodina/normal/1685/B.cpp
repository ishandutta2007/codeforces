#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, ab, ba;
        cin >> a >> b >> ab >> ba;
        string s;
        cin >> s;
        vector<string> t;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i - 1] == s[i]) {
                t.push_back("");
            }
            t.back().push_back(s[i]);
        }
        int AA = 0, BB = 0;
        vector<int> AB, BA;
        for (int i = 0; i < t.size(); i++) {
            if (t[i][0] == 'A') {
                if (t[i].back() == 'A') {
                    AA++;
                } else {
                    AB.push_back(t[i].size() / 2);
                }
            } else {
                if (t[i].back() == 'A') {
                    BA.push_back(t[i].size() / 2);
                } else {
                    BB++;
                }
            }
        }
        sort(AB.rbegin(), AB.rend());
        sort(BA.rbegin(), BA.rend());
        if (AA > a || BB > b) {
            cout << "NO\n";
            continue;
        }
        a -= AA;
        b -= BB;
        if (a != b) {
            cout << "NO\n";
            continue;
        }
        int sum = 0;
        for (int i = a; i < AB.size(); i++) {
            sum += AB[i];
        }
        if (sum > ab) {
            cout << "NO\n";
            continue;
        }
        sum = 0;
        for (int i = a; i < BA.size(); i++) {
            sum += BA[i];
        }
        if (sum > ba) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}