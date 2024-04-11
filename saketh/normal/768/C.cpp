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

const int MAXV = 1024;

int ct[2][MAXV + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K, X;
    cin >> N >> K >> X;

    bool x = 0;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        ct[x][v]++;
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= MAXV; j++)
            ct[!x][j] = 0;

        bool par = 0;
        for (int j = 0; j <= MAXV; j++) {
            if (!par) {
                ct[!x][j ^ X] += (ct[x][j] + 1) / 2;
                ct[!x][j] += ct[x][j] / 2;
            } else {
                ct[!x][j] += (ct[x][j] + 1) / 2;
                ct[!x][j ^ X] += ct[x][j] / 2;
            }

            if (ct[x][j] & 1) par = !par;
        }

        x = !x;
    }

    int lo = 0, hi = MAXV;
    while (!ct[x][lo]) lo++;
    while (!ct[x][hi]) hi--;
    cout << hi << " " << lo << endl;

    return 0;
}