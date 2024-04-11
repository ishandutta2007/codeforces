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

string build(int L, char f, char b, int occ) {
    if (L == 1 && f != b) return "";

    string res(L, 'B');
    res.front() = f;
    res.back() = b;

    if (L == 2 && res == "AC" && occ != 1) return "";

    for (int i = (f != 'A'); i < 2 * occ; i += 2) {
        res[i] = 'A';
        res[i+1] = 'C';
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, X, N, M;
    cin >> K >> X >> N >> M;

    string elt = "ABC";
    for (char f1 : elt) {
        for (char b1 : elt) {
            for (char f2 : elt) {
                for (char b2 : elt) {
                    int lim1 = (N - (f1 != 'A') - (b1 != 'C')) / 2;
                    int lim2 = (M - (f2 != 'A') - (b2 != 'C')) / 2;

                    for (int c1 = 0; c1 <= lim1; c1++) {
                        string s1 = build(N, f1, b1, c1);
                        if (s1 == "") continue;
                        for (int c2 = 0; c2 <= lim2; c2++) {
                            string s2 = build(M, f2, b2, c2);
                            if (s2 == "") continue;

                            vector<tuple<char, char, ll>> dp(K);
                            dp[0] = { f1, b1, c1 };
                            dp[1] = { f2, b2, c2 };
                            for (int i = 2; i < K; i++) {
                                dp[i] = { get<0>(dp[i-2]), get<1>(dp[i-1]),
                                    get<2>(dp[i-2]) + get<2>(dp[i-1])
                                        + (get<1>(dp[i-2]) == 'A' && get<0>(dp[i-1]) == 'C') };
                            }

                            if (get<2>(dp.back()) == X) {
                                cout << s1 << "\n" << s2 << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "Happy new year!\n";
    return 0;
}