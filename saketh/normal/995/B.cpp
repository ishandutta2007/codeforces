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
    cin >> N;

    vi vals(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> vals[i];
        vals[i]--;
    }

    vi floc(N);
    for (int i = 2 * N - 1; i >= 0; i--) {
        floc[vals[i]] = i;
    }

    int inv = 0;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = i + 1; j < 2 * N; j++) {
            if (floc[vals[i]] > floc[vals[j]])
                inv++;
        }
    }

    cout << inv << endl;

    return 0;
}