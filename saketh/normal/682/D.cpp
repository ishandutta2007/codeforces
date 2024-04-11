#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

const int NEG_INF = INT_MIN / 2;

const int MAXL = 1024;
const int MAXK = 12;

int N, M, K;
string s, t;

int fc[MAXL][MAXL][MAXK];
int gc[MAXL][MAXL][MAXK];

int g(int, int, int);

int f(int i, int j, int k) {
    if (k == 0) return 0;
    if (i >= N || j >= M) return NEG_INF;

    int &ans = fc[i][j][k];
    if (ans != -1) return ans;

    ans = max(f(i+1, j, k), f(i, j+1, k));
    if (s[i] == t[j]) ans = max(ans, 1 + g(i+1, j+1, k));
    return ans;
}

int g(int i, int j, int k) {
    if (i >= N || j >= M) {
        if (k <= 1) return 0;
        return NEG_INF;
    }

    int &ans = gc[i][j][k];
    if (ans != -1) return ans;

    ans = f(i, j, k-1);
    if (s[i] == t[j]) ans = max(ans, 1 + g(i+1, j+1, k));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> K >> s >> t;

    memset(fc, 0xff, sizeof(fc));
    memset(gc, 0xff, sizeof(gc));

    cout << f(0, 0, K) << "\n";

    return 0;
}