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

    int N;
    cin >> N;

    vi perm(N);
    for (int i = 0; i < N; i++) {
        cin >> perm[i];
        perm[i]--;
    }

    vector<bool> visited(N);

    bool odd = false;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        int loc = i, len = 0;
        while (!visited[loc]) {
            visited[loc] = true;
            loc = perm[loc];
            len++;
        }

        WATCH(len);
        if ((len&1) == 0) {
            odd = !odd;
        }
    }

    bool nodd = N&1;

    if (odd == nodd) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
    }

    return 0;
}