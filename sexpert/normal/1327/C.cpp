#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    string ans;
    for(int i = 0; i < n; i++)
        ans += 'U';
    for(int i = 0; i < m; i++)
        ans += 'L';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            ans += (i % 2 ? 'L' : 'R');
        }
        if(i < n - 1)
            ans += 'D';
    }
    cout << ans.size() << '\n' << ans << '\n';
}