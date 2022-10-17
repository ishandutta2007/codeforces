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

    int T, N;
    string str;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> str;
        bool ok = true;
        for (int i = 0; N - 1 - i > i; i++) {
            char f = str[i], g = str[N - 1 - i];
            if (f > g) swap(f, g);
            ok &= (g - f) == 0 || (g - f) == 2;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}