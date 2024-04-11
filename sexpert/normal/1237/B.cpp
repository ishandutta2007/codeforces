#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int to[MAXN], perm[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        to[x] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> x;
        perm[i] = to[x];
    }
    int mn = n + 1;
    for(int i = n; i >= 1; i--) {
        if(perm[i] > mn)
            ans++;
        mn = min(perm[i], mn);
    }
    cout << ans << '\n';
}