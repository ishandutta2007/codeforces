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
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    vi a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vvi idlers(K);
    for (int i = 0; i < N; i++) {
        idlers[a[i]].emplace_back(b[i]);
    }

    priority_queue<int> avail;
    for (int j = 0; j < K; j++) {
        sort(all(idlers[j]));
        for (int i = 0; i + 1 < idlers[j].size(); i++)
            avail.push(-idlers[j][i]);
    }

    ll ans = 0;
    for (int j = 0; j < K; j++) {
        if (idlers[j].empty()) {
            ans -= avail.top();
            avail.pop();
        }
    }
    cout << ans << endl;

    return 0;
}