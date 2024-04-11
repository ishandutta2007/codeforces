#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    cin >> N >> Q;

    int pref = 0;
    int tot_read = 0;

    vi pref_cov(N + 1);
    vi read(N + 1);
    vi generated(N + 1);

    vi notifs;

    for (int i = 0; i < Q; i++) {
        int _t, x;
        cin >> _t >> x;

        if (_t == 1) { 
            notifs.push_back(x);
            generated[x]++;
        } else if (_t == 2) {
            tot_read += generated[x] - read[x];
            read[x] = generated[x];
        } else {
            x = min(x, int(notifs.size()));

            if (x > pref) {
                for (int j = pref; j < x; j++) {
                    int app = notifs[j];

                    pref_cov[app]++;
                    if (pref_cov[app] > read[app]) {
                        tot_read += pref_cov[app] - read[app];
                        read[app] = pref_cov[app];
                    }
                }
                pref = x;
            }
        }

        cout << notifs.size() - tot_read << "\n";
    }

    return 0;
}