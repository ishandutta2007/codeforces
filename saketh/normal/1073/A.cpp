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
    string s;
    cin >> N >> s;

    for (int i = 0; i < N; i++) {
        vector<int> ct(26);
        for (int j = i; j < N; j++) {
            ct[s[j] - 'a']++;

            int len = j - i + 1;
            bool ok = true;
            for (int v : ct) {
                if (2 * v > len)
                    ok = false;
            }

            if (ok) {
                cout << "YES\n";
                cout << s.substr(i, len) << endl;
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}