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
    string s, t;
    cin >> N >> s >> t;

    vi dest(N, -1);
    vb used(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i] == t[j] && !used[j]) {
                used[j] = true;
                dest[i] = j;
                break;
            }
        }
    }

    for (int v : dest) {
        if (v == -1) {
            cout << -1 << endl;
            return 0;
        }
    }

    vi vals(N);
    for (int i = 0; i < N; i++)
        vals[i] = i;

    vi moves;
    for (int p = 0; p < N; p++) {
        for (int i = 0; i + 1 < N; i++) {
            if (dest[vals[i]] > dest[vals[i+1]]) {
                moves.push_back(i);
                swap(vals[i], vals[i+1]);
            }
        }
    }

    cout << moves.size() << "\n";
    for (int v : moves)
        cout << v + 1 << " ";
    cout << endl;

    return 0;
}