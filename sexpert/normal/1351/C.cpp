#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

map<char, int> dx = {{'N', 1}, {'S', -1}, {'W', 0}, {'E', 0}};
map<char, int> dy = {{'N', 0}, {'S', 0}, {'W', -1}, {'E', 1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        set<pair<ii, ii>> seen;
        int x = 0, y = 0, ans = 0;
        for(char c : s) {
            int nx = x + dx[c];
            int ny = y + dy[c];
            ii op = {x, y}, np = {nx, ny};
            pair<ii, ii> p = {min(op, np), max(op, np)};
            ans += 5 - 4*(seen.count(p));
            seen.insert(p);
            x = nx;
            y = ny;
        }
        cout << ans << '\n';
    }
}