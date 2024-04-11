#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;

void solve(int l, int r, int m) {
    if(l > r) return ;
    if(l == r) {
        for(int i = 1; i * 2 <= m + 1; i++) {
            cout << l << " " << i << "\n";
            if(i < m + 1 - i) cout << l << " " << m + 1 - i << "\n";
        }
        return ;
    }
    for(int i = 1; i <= m; i++) {
        cout << l << " " << i << "\n";
        cout << r << " " << m + 1 - i << "\n";
    }
    solve(l + 1, r - 1, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    solve(1, n, m);
}