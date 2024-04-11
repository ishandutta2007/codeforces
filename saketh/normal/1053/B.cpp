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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vll a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vi odd(N + 1), even(N + 1), sum(N + 1);
    even[0] = 1;
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i-1] + __builtin_popcountll(a[i-1]);
        odd[i] = odd[i-1];
        even[i] = even[i-1];
        if (sum[i]&1) odd[i]++;
        else even[i]++;
    }

    ll ans = 0;
    for (int i = 0, j; i < N; i++) {
        int bc = 0, mb = 0;
        for (j = i; j >= max(0, i - 64); j--) {
            bc += __builtin_popcountll(a[j]);
            mb = max(mb, __builtin_popcountll(a[j]));
            if ((bc % 2 == 0) && (mb * 2 <= bc))
                ans++;
        }
        if (j != -1) {
            bool state = (bc & 1) ^ (sum[j+1] & 1);
            if (state) ans += odd[j];
            else ans += even[j];
        }
    }

    cout << ans << endl;
    return 0;
}