#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 22;

string s[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];
    int q;
    cin >> q;
    while(q--) {
        int x; cin >> x; x--;
        cout << s[x % n] + t[x % m] << "\n";
    }
}