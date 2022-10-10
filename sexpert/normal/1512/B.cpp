#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &x : v)
        cin >> x;

    vector<int> ro(2), co(2);
    int p = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '*') {
                ro[p] = i;
                co[p] = j;
                p++;
            }
        }
    }

    if(ro[0] == ro[1]) {
        int r = (ro[0] ? ro[0] - 1 : 1);
        v[r][co[0]] = v[r][co[1]] = '*';
    }
    else if(co[0] == co[1]) {
        int c = (co[0] ? co[0] - 1 : 1);
        v[ro[0]][c] = v[ro[1]][c] = '*';
    }
    else
        v[ro[0]][co[0]] = v[ro[0]][co[1]] = v[ro[1]][co[0]] = v[ro[1]][co[1]] = '*';

    for(int i = 0; i < n; i++)
        cout << v[i] << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}