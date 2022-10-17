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

/*
 * Returns the vector z[i] = the greatest length l
 * such that s[i, i+l) is identical to s[0, l).
 */
template<typename T> vi z_algorithm(const vector<T>& s) {
    int N = s.size();
    vi z(N);
    z[0] = N;

    for (int i = 1, l, r = -1; i < N; i++) {
        z[i] = r > i ? min(r - i, z[i - l]) : 0;
        while (i + z[i] < N && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    cin >> N >> A >> B;

    string str;
    cin >> str;

    vvi zz;
    for (int i = 0; i < N; i++) {
        vector<char> substr;
        for (int j = i; j < N; j++)
            substr.push_back(str[j]);
        zz.push_back(z_algorithm(substr));
    }

    vvi mm(N, vi(N, 0));
    mm[0] = zz[0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mm[i][j] = mm[i-1][j];
            if (j >= i) mm[i][j] = max(mm[i][j], zz[i][j-i]);
        }
    }

    vi dp(str.size() + 1, INT_MAX);
    dp[0] = 0;

    for (int r = 1; r <= str.size(); r++) {
        dp[r] = dp[r-1] + A;

        for (int len = 1; ; len++) {
            int l = r - len;
            int mb = r - 2 * len;
            if (mb < 0) break;

            if (mm[mb][l] >= len) {
                //cout << "[" << l << ", " << r << ") has a previous match!\n";
                dp[r] = min(dp[r], dp[r-len] + B);
            }
        }
    }

    cout << dp.back() << endl;
    return 0;
}