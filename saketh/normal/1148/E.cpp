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

    int N;
    cin >> N;

    vector<array<int, 2>> s(N);
    vi t(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i][0];
        s[i][1] = i;
    }

    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(all(s));
    sort(all(t));

    ll tot = 0;
    for (int i = 0; i < N; i++) {
        tot += t[i] - s[i][0];
        if (tot < 0) { cout << "NO\n"; return 0; }
    }

    if (tot != 0) { cout << "NO\n"; return 0; }

    vector<array<int, 3>> moves;

    for (int i = 0, j = 0; ; ) {
        while(i < N && s[i][0] == t[i])
            i++;
        while (j < N && s[j][0] <= t[j])
            j++;
        if (i == N) break;

        assert(s[i][0] < t[i]);
        assert(s[j][0] > t[j]);
        assert(i < j);
        assert(j < N);
        assert(t[i] <= t[j]);

        int d1 = t[i] - s[i][0];
        int d2 = s[j][0] - t[j];
        int md = min(d1, d2);

        moves.push_back({ s[i][1] + 1, s[j][1] + 1, md });
        s[i][0] += md;
        s[j][0] -= md;
    }

    for (int i = 0; i < N; i++)
        assert(s[i][0] == t[i]);

    cout << "YES\n";
    cout << moves.size() << "\n";
    for (auto p : moves) {
        cout << p[0] << " " << p[1] << " " << p[2] << "\n";
    }

    return 0;
}