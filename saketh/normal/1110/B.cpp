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

    int N, M, K;
    cin >> N >> M >> K;

    vi pos(N);
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
    }

    vi gaps(N - 1);
    for (int i = 0; i < N - 1; i++)
        gaps[i] = pos[i+1] - pos[i] - 1;
    sort(all(gaps));

    int ans = pos.back() - pos.front() + 1;
    for (int k = 0; k < K - 1 && !gaps.empty(); k++) {
        ans -= gaps.back();
        gaps.pop_back();
    }
    cout << ans << endl;

    return 0;
}