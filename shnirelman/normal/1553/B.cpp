//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/

void solve() {
    string s, t;
    cin >> s >> t;

    for(int i = 0; i < s.size(); i++) {
        bool res = true;
        for(int j = i; j < s.size(); j++) {
            if(s[j] != t[j - i]) {
                res = false;
                break;
            }

            if(j + j - i + 1 >= t.size()) {
//                cout << i << ' ' << j << endl;
                bool is = true;
                int cur = j - i + 1;
                for(int k = j - 1; cur < t.size(); k--, cur++)
                    if(t[cur] != s[k]) {
                        is = false;
                        break;
                    }

                if(is) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}