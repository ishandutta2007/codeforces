#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 100;
int pr[MAXN];
vector<int> vp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p = 2; p < MAXN; p++) {
        if(pr[p]) continue;
        for(int q = p; q < MAXN; q += p)
            pr[q] = p;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while(x > 1) {
            int p = pr[x], e = 0;
            while(x % p == 0) {
                x /= p;
                e++;
            }
            vp[p].push_back(e);
        }
    }
    ll ans = 1;
    for(int p = 2; p < MAXN; p++) {
        if(pr[p] != p)
            continue;
        sort(vp[p].begin(), vp[p].end());
        if((int)vp[p].size() <= n - 2)
            continue;
        if(vp[p].size() == n - 1) {
            while(vp[p][0]--)
                ans *= p;
            continue;
        }
        while(vp[p][1]--)
            ans *= p;
    }
    cout << ans << '\n';
}