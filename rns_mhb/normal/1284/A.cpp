#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <string> x(n), y(m);
    for(int i = 0; i < n; i ++) cin >> x[i];
    for(int i = 0; i < m; i ++) cin >> y[i];
    int q;
    cin >> q;
    while(q --) {
        int k;
        cin >> k;
        k --;
        string ans = x[k%n] + y[k%m];
        cout << ans << endl;
    }
}