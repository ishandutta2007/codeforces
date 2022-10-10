#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++) {
        int h;
        cin >> h;
        h %= (a + b);
        if(h == 0)
            h = a + b;
        q.push((h + a - 1)/a - 1);
    }
    int ans = 0;
    while(q.size()) {
        int u = q.top(); q.pop();
        if(u > k)
            break;
        k -= u;
        ans++;
    }
    cout << ans << '\n';
}