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

int skip(vi &costs, int spend) {
    int ans = 0;
    for (int v : costs) {
        if (spend < v) break;
        spend -= v;
        ans += 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vi temp(N);
    for (int i = 0; i < N; i++)
        cin >> temp[i];

    int i = 0;
    while (i < N && temp[i] >= 0)
        i++;

    vector<int> pos;

    int ans = 0;
    while (true) {
        if (i == N) break;
        int st = 0;
        while (i < N && temp[i] < 0)
            i++, st++;
        ans++;
        K -= st;

        if (i == N) break;
        st = 0;
        while (i < N && temp[i] >= 0)
            i++, st++;
        ans++;
        pos.push_back(st);
    }

    if (K < 0) {
        cout << -1 << endl;
        return 0;
    }

    if (temp.back() >= 0 && pos.size() > 0) {
        int last = pos.back();
        pos.pop_back();
        sort(all(pos));

        int can = skip(pos, K);
        if (K >= last)
            can = max(can, 1 + skip(pos, K - last));
        ans -= can;
    } else {
        sort(all(pos));
        ans -= skip(pos, K);
    }

    cout << ans << "\n";
    return 0;
}