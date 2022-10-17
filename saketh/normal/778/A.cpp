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

    string A, B;
    cin >> A >> B;

    int N = A.size();
    int M = B.size();

    vi rank(N);
    for (int i = 0; i < N; i++) {
        int wh;
        cin >> wh;
        rank[wh - 1] = i;
    }

    WATCHC(rank);

    int ans = 0, lo = 1, hi = N - M;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        WATCH(mi);

        int inx = 0;
        for (int i = 0; i < N; i++) {
            if (rank[i] < mi) continue;
            if (inx < M && A[i] == B[inx]) inx++;
        }

        WATCH(inx);

        if (inx == M) {
            ans = mi;
            lo = mi + 1;
        } else hi = mi - 1;
    }

    cout << ans << endl;
    return 0;
}