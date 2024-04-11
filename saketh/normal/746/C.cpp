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

int wait_tram(int S, int T, int spos, int sdir, int tpos, int tdir, int mini) {
    if (tpos == 0) tdir = -1;
    if (tpos == S) tdir = 1;

    int cur = 0;
    while (cur*T < mini || spos != tpos || sdir != tdir) {
        if (spos == 0 && sdir == -1) sdir *= -1;
        if (spos == S && sdir == 1) sdir *= -1;
        spos += sdir;
        cur++;
    }
    return cur * T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, S, T;
    cin >> N >> S >> T;

    int T1, T2;
    cin >> T1 >> T2;

    int P, D;
    cin >> P >> D;

    // can just walk
    int ans = abs(S - T) * T2;

    // otherwise, we get on the tram at some point
    for (int enter = min(S, T); enter <= max(S, T); enter++) {
        // first need to walk there
        int time = abs(S - enter) * T2;
        // wait for the tram to arrive, in the right direction
        time = wait_tram(N, T1, P, D, enter, enter <= T ? 1 : -1, time);
        // take the tram to the target
        time += abs(T - enter) * T1;

        ans = min(ans, time);
    }

    cout << ans << endl;
    return 0;
}