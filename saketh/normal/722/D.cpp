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

    int N;
    cin >> N;

    vi y(N);
    vi posx;

    for (int i = 0; i < N; i++) {
        cin >> y[i];

        for (int tmp = y[i]; tmp > 0; tmp >>= 1)
            posx.push_back(tmp);
    }

    sort(all(posx));
    posx.erase(unique(all(posx)), posx.end());

    vvi elts(posx.size());

    for (int i = 0; i < N; i++) {
        for (int tmp = y[i]; tmp > 0; tmp >>= 1) {
            int inx = lower_bound(all(posx), tmp) - posx.begin();
            elts[inx].push_back(i);
        }
    }

    vi choice = y;

    int lo = 0, hi = posx.size() - 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        int done = 0;
        vi assign(N);
        for (int inx = mi; inx >= 0; inx--) {
            for (int pos : elts[inx])
                if (!assign[pos]) {
                    assign[pos] = posx[inx];
                    done++;
                    break;
                }
        }

        if (done == N) {
            choice = assign;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    for (int i = 0; i < N; i++)
        cout << choice[i] << " ";
    cout << endl;

    return 0;
}