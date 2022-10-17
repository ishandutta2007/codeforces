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

void fail() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    ll pot;

    cin >> N >> pot;

    vll len(N), lim(N);

    for (int i = 0; i < N; i++)
        cin >> len[i];

    for (int i = 0; i < N; i++)
        cin >> lim[i];

    ll remain = 0;
    ll time = 0;

    ll tot_used = 0;
    vector<ll> used;

    const int PLIM = 1e5;

    for (int i = 0; i < N; i++) {
        if (lim[i] < len[i]) fail();

        if (remain >= len[i]) {
            remain -= len[i];
            time += len[i];
            continue;
        }

        len[i] -= remain;
        lim[i] -= remain;
        time += remain;

        // time to cross = 2 * len - time boosting < lim[i]
        // so time boosting > 2 * len - lim[i]
        ll need = max(0ll, 2 * len[i] - lim[i]);

        ll slow = len[i] - need;
        time += 2 * slow;
        len[i] -= slow;

        ll use = (need + pot - 1) / pot;
        tot_used += use;

        for (int j = 0; j < use; j++) {
            if (used.size() > PLIM) break;
            used.push_back(time + j * pot);
        }

        remain = use * pot - need;
        time += need;
    }

    cout << tot_used << endl;
    if (tot_used <= PLIM)
        for (ll v : used)
            cout << v << " ";
    cout << endl;

    return 0;
}