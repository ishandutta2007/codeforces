#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 100;
const int INF = 1e9 + 10;
int a[MAXN];

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ck = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] != k)
            continue;
        ck++;
    }
    if(ck == n) {
        cout << "yes\n";
        return;
    }
    if(ck == 0) {
        cout << "no\n";
        return;
    }
    for(int i = 1; i + 1 <= n; i++) {
        if(a[i] >= k && a[i + 1] >= k) {
            cout << "yes\n";
            return;
        }
        if(i + 2 <= n && a[i] >= k && a[i + 2] >= k) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}