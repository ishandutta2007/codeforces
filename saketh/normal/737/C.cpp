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

    int N, S;
    cin >> N >> S;

    S--;
    
    int ans = 0;
    int fc = 0;

    vi ct(N + 1);

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;

        if (i == S) {
            if (val != 0) ans++;
            ct[0]++;
        } else {
            if (val == 0) {
                ans++;
                fc++;
            } else ct[val]++;
        }
    }

    int l = 0, r = N;
    while (l < r) {
        if (ct[l]) l++;
        else if (!ct[r]) r--;
        else if (fc > 0) {
            fc--;
            ct[l]++;
        } else {
            ct[r]--;
            ct[l]++;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}