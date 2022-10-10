#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
set<int> di[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, ans = 0;
        cin >> x >> y;
        for(int d = 1; d * d <= x; d++) {
            if(x % d)
                continue;
            di[d].insert(i);
            if(*di[d].lower_bound(i - y) == i)
                ans++;
            if(x/d > d) {
                di[x/d].insert(i);
                if(*di[x/d].lower_bound(i - y) == i)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
}