#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 10;
int ans[MAXN], orz[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int p = n, sz = n;
    fill(orz, orz + MAXN, 1);
    for(int g = n; g >= 1; g--) {
        for(int h = 2*g; h <= n; h += g) {
            sz -= orz[h];
            orz[h] = 0;
        }
        while(p > sz)
            ans[p--] = g;
    }
    for(int i = 2; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}