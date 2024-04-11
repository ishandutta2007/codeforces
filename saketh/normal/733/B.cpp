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

    vector<array<ll, 2>> vals(N);

    ll left = 0, right = 0;

    for (int i = 0; i < N; i++) {
        cin >> vals[i][0] >> vals[i][1];
        left += vals[i][0];
        right += vals[i][1];
    }

    ll imp = 0, ans = 0;

    for (int i = 0; i < N; i++) {
        ll left2 = left - vals[i][0] + vals[i][1];
        ll right2 = right - vals[i][1] + vals[i][0];

        ll better = llabs(left2 - right2) - llabs(left - right);
        if (better > imp) {
            imp = better;
            ans = i + 1;
        }
    }

    cout << ans << endl;
    return 0;
}