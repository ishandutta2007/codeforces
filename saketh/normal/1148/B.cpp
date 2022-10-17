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

    int N, M, TA, TB, K;
    cin >> N >> M >> TA >> TB >> K;

    vi timesA(N);
    for (int i = 0; i < N; i++) {
        cin >> timesA[i];
    }

    vi timesB(M);
    for (int i = 0; i < M; i++) {
        cin >> timesB[i];
    }

    int ans = 0;

    for (int ca = 0; ca <= K; ca++) {
        int arriveB = ca < N ? timesA[ca] + TA : INT_MAX;

        int firstAvail = lower_bound(all(timesB), arriveB) - timesB.begin();
        int leaveB = firstAvail + (K - ca);

        int arriveC = leaveB < M ? timesB[leaveB] + TB : INT_MAX;

        ans = max(ans, arriveC);
    }

    cout << (ans < INT_MAX ? ans : -1) << "\n";

    return 0;
}