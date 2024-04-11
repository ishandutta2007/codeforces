#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pa = array<int, 2>;

map<pa, char> cur;
map<pa, int> cnt;
int god, gev;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while(m--) {
        char cc;
        cin >> cc;
        if(cc == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            cur[{u, v}] = c;
            int x = min(u, v), y = max(u, v);
            cnt[{x, y}]++;
            if(cnt[{x, y}] == 2)
                god++;
            if(cur.count({v, u}) && cur[{v, u}] == c)
                gev++;
        }
        if(cc == '-') {
            int u, v;
            cin >> u >> v;
            int x = min(u, v), y = max(u, v);
            if(cnt[{x, y}] == 2)
                god--;
            if(cur.count({v, u}) && cur[{v, u}] == cur[{u, v}])
                gev--;
            cnt[{x, y}]--;
            cur.erase({u, v});
        }
        if(cc == '?') {
            int k;
            cin >> k;
            if((((k % 2) == 1) && god) || (((k % 2) == 0) && gev))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}