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
    string a, b;
    cin >> N >> a >> b;

    vll ct(4);
    for (int i = 0; i < N; i++) {
        int ai = a[i] - '0';
        int bi = b[i] - '0';
        ct[2 * ai + bi]++;
    }

    ll ans = (ct[0b00] + ct[0b01]) * (ct[0b10] + ct[0b11])
           - (ct[0b01] * ct[0b11]);
    cout << ans << endl;
    return 0;
}