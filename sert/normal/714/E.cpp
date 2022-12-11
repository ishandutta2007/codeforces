#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "dynasties"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const int N = 3431;
int n, a[N];
ll dp[N][N];
int p[N];

bool cmp(int x, int y) {
    return a[x] - x < a[y] - y;
}

void mne(ll &a, ll b) {
    if (b < a)
        a = b;
}

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i;
    }

    sort(p, p + n, cmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + 1][j] = dp[i][j] + abs(a[j] + i - j - a[i]);
        }
        for (int j = 1; j < n; j++) {
            mne(dp[i + 1][p[j]], dp[i + 1][p[j - 1]]);
        }
    }

    cout << dp[n][p[n - 1]] << "\n";

    return 0;
}