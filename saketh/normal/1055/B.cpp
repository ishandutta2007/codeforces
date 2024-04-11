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

struct union_find {
    vi P, R, S;

    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        for (int i = 0; i < N; i++)
            P[i] = i;
    }

    int rep(int i) {
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, L;
    cin >> N >> M >> L;

    vll hairs(N);
    union_find uf(N);
    int small = 0;
    int merges = 0;

    for (int i = 0; i < N; i++) {
        cin >> hairs[i];
        if (hairs[i] <= L) {
            small++;
        } else {
            if (i > 0 && hairs[i-1] > L) {
                merges += uf.unio(i, i-1);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int t, p, d;
        cin >> t;
        if (t == 0) {
            cout << N - small - merges << "\n";
        } else {
            cin >> p >> d;
            --p;

            if (hairs[p] > L) {
                // don't need to do anything
            } else {
                hairs[p] += d;
                if (hairs[p] > L) {
                    small--;
                    if (p > 0 && hairs[p - 1] > L) {
                        merges += uf.unio(p, p - 1);
                    }
                    if (p+1 < N && hairs[p + 1] > L) {
                        merges += uf.unio(p, p + 1);
                    }
                }
            }
        }
    }

    return 0;
}