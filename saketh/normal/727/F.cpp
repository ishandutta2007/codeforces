#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vll prob(N);
    for (int i = 0; i < N; i++)
        cin >> prob[i];

    vll worst(N);
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = i; j < N; j++) {
            if (prob[j] >= prob[i]) {
                sum += prob[j];
                worst[i] = min(worst[i], sum);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        ll val;
        cin >> val;

        int ans = 0;
        for (int j = 0; j < N; j++) {
            if (val + worst[j] < 0) ans++;
            else val += prob[j];
        }

        cout << ans << "\n";
    }

    return 0;
}