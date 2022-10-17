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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    cin >> N >> K >> X;

    vi val(N);
    for (int i = 0; i < N; i++)
        cin >> val[i];

    val.insert(val.begin(), 0);
    val.push_back(0);
    N += 2;
    X += 2;

    vvll dp(X + 1, vll(N, -1));
    dp[1][0] = 0;

    for (int p = 2; p <= X; p++) {
        priority_queue<pair<ll, int>> pred;
        for (int li = 0; li < N; li++) {
            if (li > 0 && dp[p-1][li-1] != -1)
                pred.push({ dp[p-1][li-1], li-1 });
            while (!pred.empty() && pred.top().second < li - K)
                pred.pop();
            if (!pred.empty())
                dp[p][li] = pred.top().first + val[li];
        }
    }

    cout << dp[X][N-1] << endl;
    return 0;
}