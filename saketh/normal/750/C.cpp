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

    int low = INT_MIN, upp = INT_MAX;

    int N;
    cin >> N;

    int off = 0;
    for (int i = 0; i < N; i++) {
        int post, div;
        cin >> post >> div;

        if (div == 1) {
            // know that start + off >= 1900
            low = max(low, 1900 - off);
        } else {
            // know that start + off <= 1899
            upp = min(upp, 1899 - off);
        }

        off += post;
    }

    if (low > upp) {
        cout << "Impossible\n";
    } else if (upp == INT_MAX) {
        cout << "Infinity\n";
    } else {
        cout << upp + off << "\n";
    }

    return 0;
}