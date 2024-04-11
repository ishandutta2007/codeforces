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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    int R = 1;
    vi ct;

    for (int p = 2; p * p <= N; p++) {
        if (N % p == 0) {
            int rep = 0;
            while (N % p == 0) {
                rep++;
                N /= p;
            }
            R *= p;
            ct.push_back(rep);
        }
    }
    if (N != 1) {
        R *= N;
        ct.push_back(1);
    }

    bool same = true;
    bool pow2 = true;
    int mpow = 0;
    for (int i = 0; i < ct.size(); i++) {
        if (i > 0 && ct[i] != ct[i-1]) same = false;

        int rep = 0;
        if (__builtin_popcount(ct[i]) > 1) {
            pow2 = false;
            rep = 1;
        }
        for (int tmp = ct[i]; tmp > 1; tmp /= 2)
            rep++;
        mpow = max(mpow, rep);
    }

    if (!same || !pow2) mpow++;
    cout << R << " " << mpow << endl;
    return 0;
}