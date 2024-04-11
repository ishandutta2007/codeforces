#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 78;

int dp[N][N][N][2];
int a[N], cur_dp;
vector <int> es[3];
int num[N];

void mne(int &a, int b) {
    if (b < a) a = b;
}

int main() {
    init();

    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    for (int k = 0; k < N; k++)
    for (int t = 0; t < 2; t++)
        dp[i][j][k][t] = 1000000;
    dp[0][0][0][0] = 0;

    string s;
    int n;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') a[i] = 0;
        else if (s[i] == 'K') a[i] = 1;
        else a[i] = 2;
        num[i] = es[a[i]].size();
        es[a[i]].push_back(i);
    }
    int d, p;
    for (int v = 0; v <= (int)es[0].size(); v++)
    for (int k = 0; k <= (int)es[1].size(); k++)
    for (int x = 0; x <= (int)es[2].size(); x++)
    for (int lv = 0; lv <= 1; lv++)
    for (int c = 0; c <= 2; c++) {
        if (lv == 1 && c == 1) continue;
        if (v == (int)es[0].size() && c == 0) continue;
        if (k == (int)es[1].size() && c == 1) continue;
        if (x == (int)es[2].size() && c == 2) continue;
        cur_dp = dp[v][k][x][lv];
        if (c == 0) p = es[0][v];
        else if (c == 1) p = es[1][k];
        else p = es[2][x];
        d = 0;
        for (int i = 0; i < p; i++) {
            if (a[i] == 0 && num[i] >= v) d++;
            if (a[i] == 1 && num[i] >= k) d++;
            if (a[i] == 2 && num[i] >= x) d++;
        }
        if (c == 0) mne(dp[v + 1][k][x][1], cur_dp + d);
        if (c == 1) mne(dp[v][k + 1][x][0], cur_dp + d);
        if (c == 2) mne(dp[v][k][x + 1][0], cur_dp + d);
    }

    int v = es[0].size();
    int k = es[1].size();
    int x = es[2].size();

    cout << min(dp[v][k][x][1], dp[v][k][x][0]);

    return 0;
}