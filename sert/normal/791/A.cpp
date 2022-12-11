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

    int a, b;
    cin >> a >> b;
    for (int i = 1; true; i++) {
        a *= 3;
        b *= 2;
        if (a > b) {
            cout << i;
            return 0;
        }
    }

    return 0;
}