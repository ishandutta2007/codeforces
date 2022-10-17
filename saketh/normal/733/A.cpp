#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

    string vow = "AEIOUY";

    string tape;
    cin >> tape;

    int loc = -1;
    int ans = 1;

    for (int i = 0; i < tape.size(); i++) {
        if (vow.find(tape[i]) != string::npos) {
            ans = max(ans, i - loc);
            loc = i;
        }
    }

    ans = max(ans, int(tape.size()) - loc);
    cout << ans << endl;

    return 0;
}