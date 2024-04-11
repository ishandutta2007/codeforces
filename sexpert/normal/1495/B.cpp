#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
int p[MAXN], lf[MAXN], ri[MAXN], pm[MAXN], sm[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    p[0] = n + 1;
    p[n + 1] = n + 1;
    for(int i = 1; i <= n; i++) {
        if(p[i] < p[i - 1])
            lf[i] = 1;
        else
            lf[i] = lf[i - 1] + 1;
    }
    for(int i = n; i >= 1; i--) {
        if(p[i] < p[i + 1])
            ri[i] = 1;
        else
            ri[i] = ri[i + 1] + 1;
    }

    for(int i = 1; i <= n; i++)
        pm[i] = max(pm[i - 1], max(lf[i], ri[i]));

    for(int i = n; i >= 1; i--)
        sm[i] = max(sm[i + 1], max(lf[i], ri[i]));

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(lf[i] == 1 || ri[i] == 1)
            continue;
        if(lf[i]/2 != ri[i]/2)
            continue;
        if(lf[i] % 2 == 0 || ri[i] % 2 == 0)
            continue;
        if(max(pm[i - lf[i]], sm[i + ri[i]]) >= max(lf[i], ri[i]))
            continue;
        ans++;
    }
    cout << ans << '\n';
}