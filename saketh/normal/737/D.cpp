#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int sum(vi &pref, int i, int j) {
    return pref[j+1] - pref[i];
}

bool seen[4005][105][205];
int cache[4005][105][205];

int solve(int i, int j, int k, bool p, vi &pref) {
    int len = j - i + 1;
    if (k > len) return 0;

    int ans;
    if (p) {
        int c1 = solve(i, j - k, k, !p, pref) - sum(pref, j-k+1, j);
        if (len >= k + 1) {
            int c2 = solve(i, j - k - 1, k+1, !p, pref) - sum(pref, j-k, j);
            c1 = min(c1, c2);
        }
        ans = c1;
    } else {
        int rep = (pref.size() - j) - i + 100;
        if (rep < 0 || rep > 200) return 0;

        if (seen[i][k][rep]) return cache[i][k][rep];
        seen[i][k][rep] = true;

        int c1 = solve(i + k, j, k, !p, pref) + sum(pref, i, i+k-1);
        if (len >= k + 1) {
            int c2 = solve(i + k + 1, j, k+1, !p, pref) + sum(pref, i, i+k);
            c1 = max(c1, c2);
        }
        ans = c1;

        cache[i][k][rep] = ans;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi val(N), pref(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
        pref[i+1] = val[i] + pref[i];
    }

    cout << solve(0, N - 1, 1, false, pref) << endl;
    return 0;
}