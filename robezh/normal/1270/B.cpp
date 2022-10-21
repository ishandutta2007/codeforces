#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

int n;
int a[N];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i + 1 < n; i++) {
        if(abs(a[i] - a[i+1]) >= 2) {
            cout << "YES\n";
            cout << i + 1 << " " << i + 2 << '\n';
            return ;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}