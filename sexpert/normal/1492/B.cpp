#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
int p[MAXN], ps[MAXN], tk[MAXN];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        tk[i] = 0;
        cin >> p[i];
        ps[p[i]] = i;
    }
    int ptr = n;
    while(ptr) {
        while(tk[ptr] && ptr)
            ptr--;
        if(!ptr)
            break;
        int x = ps[ptr];
        for(;x <= n && !tk[p[x]]; x++) {
            tk[p[x]] = 1;
            cout << p[x] << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}