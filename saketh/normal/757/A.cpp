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

    string need = "Bulbasaur";
    vector<int> ct(256);
    for (char c : need)
        ct[int(c)]++;

    string newsp;
    cin >> newsp;

    vector<int> have(256);
    for (char c : newsp)
        have[int(c)]++;

    int ans = INT_MAX;
    for (int i = 0; i < 256; i++) {
        if (ct[i]) {
            ans = min(ans, have[i] / ct[i]);
        }
    }
    cout << ans << endl;

    return 0;
}