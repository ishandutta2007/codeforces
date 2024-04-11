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

    vi l(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    vi get(N, -1);
    int assigned = 0;
    int give = N;

    auto fail = []() {
        cout << "NO" << endl;
        exit(0);
    };

    while (assigned < N) {
        vi zeroes;
        for (int i = 0; i < N; i++) {
            if (get[i] != -1) continue;
            if (l[i] == 0 && r[i] == 0) {
                zeroes.push_back(i);
            }
        }

        if (zeroes.empty()) {
            fail();
        }

        for (int v : zeroes) {
            get[v] = give;
        }
        assigned += zeroes.size();

        for (int v : zeroes) {
            for (int i = 0; i < N; i++) {
                if (get[i] != -1) continue;
                if (i < v) {
                    if (!r[i]) fail();
                    r[i]--;
                }
                if (i > v) {
                    if (!l[i]) fail();
                    l[i]--;
                }
            }
        }

        give--;
    }

    cout << "YES" << endl;
    for (int v : get) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}