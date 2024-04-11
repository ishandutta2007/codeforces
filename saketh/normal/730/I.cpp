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

    int N, A, B;
    cin >> N >> A >> B;

    vi a(N), b(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vi orderA(N);
    for (int i = 0; i < N; i++) {
        orderA[i] = i;
    }
    vi orderB = orderA;

    sort(all(orderA), [&](int i, int j) {
        return a[i] > a[j];
    });

    sort(all(orderB), [&](int i, int j) {
        return b[i] > b[j];
    });

    vvi st(N+1, vi(A+1, INT_MIN));
    vector<vb> pi(N+1, vb(A + 1, 0));

    st[0][0] = 0;

    for (int p = 1; p <= N; p++) {
        for (int t = 0; t <= min(p, A); t++) {
            if (t) {
                int cand = a[orderA[p-1]] + st[p-1][t-1];
                if (cand > st[p][t]) {
                    st[p][t] = cand;
                    pi[p][t] = true;
                }
            }

            int cand = b[orderA[p-1]] + st[p-1][t];
            if (cand > st[p][t]) {
                st[p][t] = cand;
                pi[p][t] = false;
            }
        }
    }

    int best = 0;
    vi bA, bB;

    for (int p = A; p <= A + B; p++) {
        vi state(N);

        int take = A;
        for (int q = p; q > 0; q--) {
            if (pi[q][take]) {
                state[orderA[q-1]] = 1;
                take--;
            } else {
                state[orderA[q-1]] = 2;
            }
        }

        int score = st[p][A];

        int add = B - (p - A);
        for (int i = 0; i < N; i++) {
            if (!state[orderB[i]] && add > 0) {
                state[orderB[i]] = 2;
                score += b[orderB[i]];
                add--;
            }
        }

        if (score > best) {
            best = score;
            bA.clear();
            bB.clear();

            for (int i = 0; i < N; i++) {
                if (state[i] == 1) bA.push_back(i);
                else if (state[i] == 2) bB.push_back(i);
            }
        }
    }

    cout << best << "\n";

    for (int v : bA)
        cout << v + 1 << " ";
    cout << "\n";

    for (int v : bB)
        cout << v + 1 << " ";
    cout << "\n";

    return 0;
}