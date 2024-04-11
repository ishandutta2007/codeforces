#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    int eight = 0, not8 = 0;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == '8') {
            eight++;
        } else {
            not8++;
        }
    }

    for (int ans = eight; ans >= 0; ans--) {
        int avail = eight - ans + not8;
        if (avail / 10 >= ans) {
            cout << ans << endl;
            break;
        }
    }

    return 0;
}