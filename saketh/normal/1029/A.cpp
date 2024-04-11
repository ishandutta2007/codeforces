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

    int N, K;
    string s;
    cin >> N >> K >> s;

    for (int i = 1; i <= N; i++) {
        bool ok = true;
        for (int j = 0; j < N - i; j++) {
            ok &= s[j] == s[j+i];
        }
        if (ok) {
            for (int r = 0; r < K; r++) {
                for (int j = 0; j < i; j++)
                    cout << s[j];
            }
            for (int j = i; j < N; j++)
                cout << s[j];
            cout << endl;
            return 0;
        }
    }

    return 0;
}