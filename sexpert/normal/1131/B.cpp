#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
 
int solve(int x1, int y1, int x2, int y2) {
    if(x1 < y1) {
        if(x2 < y1)
            return 0;
        return min(x2 - y1 + 1, y2 - y1 + 1);
    }
    if(x1 > y1) {
        if(x1 > y2)
            return 0;
        return min(y2 - x1 + 1, x2 - x1 + 1);
    }
    if(x1 == y1) {
        return min(x2 - x1, y2 - y1);
    }
}
 
int main() {
    int n;
    cin >> n;
    vector<ii> v(n + 1);
    v[0] = {0, 0};
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    int ans = 1;
    for(int i = 1; i <= n; i++)
        ans += solve(v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
    cout << ans << endl;
}