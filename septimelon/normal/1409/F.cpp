#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    int ans = 0;
    if (t[0] == t[1]) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == t[0]) {
                ++ans;
            }
        }
        ans = min(n, ans + k);
        ans = ans * (ans - 1) / 2;
        cout << ans << "\n";
        return 0;
    }

    ll ca = 0, cb = 0, cc = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[0]) {
            ++ca;
            s[i] = 'a';
        }
        else if (s[i] == t[1]) {
            ++cb;
            s[i] = 'b';
            ans += ca;
        }
        else {
            ++cc;
            s[i] = 'c';
        }
    }

    int mans = ans;
    for (int tca = 0; cc >= 0 && tca <= k; ++tca) {
        vector<int> toas;

        for (int tba = 0; cb >= 0 && tca + tba <= k; ++tba) {
            vector<int> atob;
            vector<int> ctob;

            int laa = 0, lac = ca, rba = 0, ia = n - 1, ic = n - 1;
            int cans = 0;

            for (int i = 0; i < n; ++i) {
                if (s[i] == 'a') {
                    ++laa;
                }
                else if (s[i] == 'b') {
                    cans += laa;
                }
            }

            //cout << s << "(" << cans << ") -> ";

            for (int tb = 1; tca + tba + tb <= k; ++tb) {
                int da, dc;
                while (ia >= 0 && s[ia] != 'a') {
                    if (s[ia] == 'b') {
                        ++rba;
                    }
                    --ia;
                }
                if (ia < 0) {
                    da = -1;
                }
                else {
                    da = laa - rba - 1;
                }
                while (ic >= 0 && s[ic] != 'c') {
                    if (s[ic] == 'a') {
                        --lac;
                    }
                    --ic;
                }
                if (ic < 0) {
                    dc = -1;
                }
                else {
                    dc = lac;
                }

                if (da > dc && da >= 0) {
                    s[ia] = 'b';
                    atob.push_back(ia);
                    ++rba;
                    --laa;
                    --ia;
                    cans += da;
                }
                else if (dc >= da && dc >= 0) {
                    s[ic] = 'b';
                    ctob.push_back(ic);
                    if (ia <= ic) {
                        ++rba;
                    }
                    --ic;
                    cans += dc;
                }

                //cout << " | " << s << " - " << cans << " | ";
            }

            //cout << s << ": " << cans << "\n";

            mans = max(mans, cans);
            while (!atob.empty()) {
                s[atob.back()] = 'a';
                atob.pop_back();
            }
            while (!ctob.empty()) {
                s[ctob.back()] = 'c';
                ctob.pop_back();
            }

            if (cb > 0) {
                for (int i = 0; i < n; ++i) {
                    if (s[i] == 'b') {
                        s[i] = 'a';
                        toas.push_back(i);
                        break;
                    }
                }
                ++ca;
                --cb;
            }
        }

        while (!toas.empty()) {
            s[toas.back()] = 'b';
            toas.pop_back();
            --ca;
            ++cb;
        }

        if (cc > 0) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'c') {
                    s[i] = 'a';
                    break;
                }
            }
            ++ca;
            --cc;
        }
    }

    cout << mans << "\n";

    return 0;
}