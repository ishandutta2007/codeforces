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

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int mpow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return prod(b, mpow(b, e - 1));
    return mpow(prod(b, b), e/2);
}

int inv(int v) { return mpow(v, MOD - 2); }

const int MAXV = 3e5;
int fact[MAXV], finv[MAXV];

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXV; i++)
        fact[i] = prod(fact[i-1], i);

    for (int i = 0; i < MAXV; i++)
        finv[i] = inv(fact[i]);
}

int ncr(int n, int r) {
    if (r > n) return 0;
    assert(r >= 0);
    return prod(fact[n], prod(finv[r], finv[n-r]));
}

int arrange(int boxes, int stacks, int height) {
    ll remove = stacks * 1ll * height;
    if (remove > boxes) return 0;
    boxes -= remove;
    return ncr(boxes + stacks - 1, stacks - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    init();
    assert(ncr(6, 3) == 20);

    int F, W, H;
    cin >> F >> W >> H;

    if (F == 0) {
        if (W > H) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return 0;
    } else if (W == 0) {
        cout << 1 << "\n";
        return 0;
    }

    int good = 0, all = 0;

    for (int ns = 2; ns <= F + W; ns++) {
        {
            // case 1, start with a wine stack
            all = sum(all, prod(arrange(F, ns/2, 1),
                        arrange(W, (ns+1)/2, 1)));

            good = sum(good, prod(arrange(F, ns/2, 1),
                        arrange(W, (ns+1)/2, H + 1)));
        }
        {
            // case 2, start with a food stack
            all = sum(all, prod(arrange(F, (ns+1)/2, 1),
                        arrange(W, ns/2, 1)));

            good = sum(good, prod(arrange(F, (ns+1)/2, 1),
                        arrange(W, ns/2, H + 1)));
        }
    }

    cout << prod(good, inv(all)) << endl;
    return 0;
}