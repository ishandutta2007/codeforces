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

    int N, H, A, B, K;
    cin >> N >> H >> A >> B >> K;

    for (int k = 0; k < K; k++) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;

        int ans = abs(ta - tb);
        if (ta == tb) {
            ans += abs(fa - fb);
        } else if (fa > B && fb > B) {
            ans += abs(fa - B) + abs(fb - B);
        } else if (fa < A && fb < A) {
            ans += abs(fa - A) + abs(fb - A);
        } else {
            ans += abs(fa - fb);
        }
        cout << ans << "\n";
    }

    return 0;
}