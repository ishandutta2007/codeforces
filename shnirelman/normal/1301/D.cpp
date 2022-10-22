#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int mx = n * 4 * m - 2 * n - 2 * m;

    if(mx < k) {
        cout << "NO" << endl;
        return 0;
    }

    vector<pair<int, string>> res;
    for(int i = 0; i < n && k > 0; i++) {

        if(k < m) {
            res.emplace_back(k, "R");
            break;
        } else if(m > 1) {
            res.emplace_back(m - 1, "R");
            k -= m - 1;
        }

        if(i != n - 1) {
            if(k <= (m - 1) * 3) {
                if(k >= 3)
                    res.emplace_back(k / 3, "DUL");

                k %= 3;

                if(k == 1)
                    res.emplace_back(1, "D");
                else if(k == 2)
                    res.emplace_back(1, "DU");

                break;
            } else if(m > 1) {
                res.emplace_back(m - 1, "DUL");
                k -= (m - 1) * 3;
            }
        } else {
            if(k < m) {
                res.emplace_back(k, "L");
                break;
            } else {
                if(m > 1)
                    res.emplace_back(m - 1, "L");
                k -= m - 1;

                if(k > 0) {
                    res.emplace_back(k, "U");
                    break;
                }
            }
        }

        res.emplace_back(1, "D");
        k--;
    }

    cout << "YES" << endl;
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i].f << ' ' << res[i].s << endl;
    }

}