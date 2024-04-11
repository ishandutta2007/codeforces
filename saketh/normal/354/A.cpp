#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 100;

int N, L, R, SL, SR;
int val[MAXN];
int pre[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> L >> R >> SL >> SR;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
        pre[i+1] = pre[i] + val[i];
    }

    int ans = 0x7fffffff;

    for (int ul = 0; ul <= N; ul++) {
        int tot = 0;

        tot += L * pre[ul];
        tot += R * (pre[N] - pre[ul]);

        int ur = N - ul;
        if(ur > ul) tot += SR * (ur - ul - 1);
        if(ul > ur) tot += SL * (ul - ur - 1);

        ans = min(ans, tot);
    }

    cout << ans << endl;
}