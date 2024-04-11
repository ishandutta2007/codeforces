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

int read() {
    string elt;
    cin >> elt;
    int val = 0;
    for (char c : elt)
        val = (val << 1) + (c == '1');
    return val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, Q;
    cin >> N >> M >> Q;

    vi w(N);
    for (int i = 0; i < N; i++)
        cin >> w[i];
    reverse(all(w));

    const int LIM = 1 << N;

    vi wu(LIM);
    for (int i = 0; i < LIM; i++) {
        for (int j = 0; j < N; j++)
            if ((i >> j)&1)
                wu[i] += w[j];
    }
    WATCHC(wu);

    vi ct(LIM);
    for (int i = 0; i < M; i++) {
        ct[read()]++;
    }
    WATCHC(ct);

    vi ans(LIM * 101);
    for (int t = 0; t < LIM; t++) {
        for (int s = 0; s < LIM; s++) {
            int r = wu[ t ^ s ^ (LIM - 1) ];
            if (t == 0) {
                WATCH(s);
                WATCH(r);
            }
            if (r <= 100) ans[t * 101 + r] += ct[s];
        }

        for (int v = 1; v <= 100; v++)
            ans[t * 101 + v] += ans[t * 101 + v - 1];
    }

    for (int i = 0; i < Q; i++) {
        int t, k;
        t = read();
        cin >> k;
        WATCH(t);
        WATCH(k);
        cout << ans[t * 101 + k] << "\n";
    }

    return 0;
}