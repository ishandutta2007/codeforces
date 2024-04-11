#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, P;
    cin >> N >> P;

    vi str(N);
    char c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        str[i] = c - 'a';
    }

    const int SZ = 1 << 17;
    bitset<SZ> disallow;

    for (int c1 = 0; c1 < P; c1++) {
        for (int c2 = 0; c2 < P; c2++) {
            int ok;
            cin >> ok;
            if (c2 < c1 || ok) continue;

            bitset<SZ> bad;

            int lst = -1;
            int btw = 0;
            for (int i = 0; i < N; i++) {
                if (str[i] == c1) {
                    if (lst == c2)
                        bad[btw] = true;
                    lst = c1;
                    btw = 0;
                } else if (str[i] == c2) {
                    if (lst == c1)
                        bad[btw] = true;
                    lst = c2;
                    btw = 0;
                } else {
                    btw |= 1 << str[i];
                }
            }

            for (int m = 0; m < bad.size(); m++) {
                for (int i = 0; i < P; i++) {
                    if (i == c1 || i == c2) continue;
                    if (bad[m]) bad[m | (1 << i)] = true;
                }
            }

            /*cout << "Because " << char('a' + c1) << " cannot be next to " << char('a' + c2) << " we cannot delete the subsets: ";
            for (int m = 0; m < (1 << P); m++) {
                if (bad[m]) {
                    for (int i = 0; i < P; i++)
                        if ((m >> i)&1)
                            cout << char('a' + i);
                    cout << " ";
                }
            }
            cout << endl;*/

            disallow |= bad;
        }
    }

    vi app(26);
    for (int v : str) {
        app[v]++;
    }

    int ans = INT_MAX;

    bitset<SZ> reach;
    reach[0] = true;

    for (int m = 0; m < (1 << P); m++) {
        if (disallow[m] || !reach[m]) continue;
        int tot = 0;
        for (int i = 0; i < P; i++) {
            if (!((m >> i)&1)) {
                tot += app[i];
                reach[m ^ (1 << i)] = true;
            }
        }
        ans = min(ans, tot);
    }

    cout << ans << endl;
    return 0;
}