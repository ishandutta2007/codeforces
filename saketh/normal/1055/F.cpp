#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6;

int N;
ll vals[MAXN], vxor[MAXN];
ll r1[MAXN], r2[MAXN];

ll matches(ll m) {
    ll ans = 0;
    for (int i = 0, j = 0, k = 0; i < N; i = j) {
        while (j < N && (vals[i]&m) == (vals[j]&m))
            j++;
        while (k < N && (vxor[k]&m) <= (vals[i]&m)) {
            if ((vxor[k]&m) == (vals[i]&m))
                ans += j - i;
            k++;
        }
    }
    return ans;
}

void flip(ll b) {
    int R1 = 0, R2 = 0;
    for (int i = 0; i < N; i++) {
        ll v = vxor[i];
        if (v&b) {
            r1[R1++] = v ^ b;
        } else {
            r2[R2++] = v ^ b;
        }
    }
    merge(r1, r1 + R1, r2, r2 + R2, vxor);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll K;
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        int dad;
        ll weight;
        cin >> dad >> weight;
        vals[i] = vals[dad-1] ^ weight;
    }

    sort(vals, vals + N);
    memcpy(vxor, vals, N * sizeof(ll));

    vi inx(N);
    ll res = 0, tot = 0, m = 0;
    for (int j = 61; j >= 0; j--) {
        ll b = 1ll << j;
        m += b;
        ll add = matches(m);
        if (tot + add < K) {
            res ^= b;
            flip(b);
            tot += add;
        }
    }

    cout << res << endl;
    return 0;
}