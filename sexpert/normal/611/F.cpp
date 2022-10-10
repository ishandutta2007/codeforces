#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int remw, remh, w, h, n;
map<char, int> dx = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
map<char, int> dy = {{'R', 0}, {'L', 0}, {'U', 1}, {'D', -1}};
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h >> w;
    remh = h;
    remw = w;
    string s;
    cin >> s;
    ll ans = 0, mov = 0;
    int x = 0, y = 0, mx = 0, my = 0, Mx = 0, My = 0;
    auto fx = [&]() {
        if(x > Mx) {
            Mx = x; 
            if(remw) {
                ans += mov * remh;
                remw--;
            }
        }
        if(x < mx) {
            mx = x;
            if(remw) {
                ans += mov * remh;
                remw--;
            }
        }
        ans %= MOD;
    };
    auto fy = [&]() {
        if(y > My) {
            My = y; 
            if(remh) {
                ans += mov * remw;
                remh--;
            }
        }
        if(y < my) {
            my = y;
            if(remh) {
                ans += mov * remw;
                remh--;
            }
        }
        ans %= MOD;
    };
    for(auto c : s) {
        x += dx[c];
        y += dy[c];
        //cout << x << " " << y << endl;
        mov++;
        fx();
        fy();
    }
    if(remh == 0 || remw == 0) {
        cout << ans << endl;
        return 0;
    }
    if(x == 0 && y == 0) {
        cout << "-1\n";
        return 0;
    }
    //cout << ans << endl;
    vector<pair<int, int>> moves;
    int prv = mov;
    for(auto c : s) {
        x += dx[c];
        y += dy[c];
        mov++;
        ll ca = ans;
        fy();
        if(ca != ans) {
            moves.push_back({mov - prv, 1});
            prv = mov;
            ca = ans;
        }
        ans = ca;
        fx();
        if(ca != ans) {
            moves.push_back({mov - prv, -1});
            prv = mov;
        }
    }
    moves.push_back({mov - prv, 0});
    //for(auto m : moves)
    //    cout << m.first << " " << m.second << endl;
    //cout << remw << " " << remh << " " << mov << " " << ans << endl;
    int ct = 0, mvs = moves.size();
    while(remw > 0 && remh > 0) {
        auto p = moves[ct++ % mvs];
        mov += p.first;
        mov %= MOD;
        if(p.second == 1) {
            ans += mov * remw;
            ans %= MOD;
            remh--;
        }
        if(p.second == -1) {
            ans += mov * remh;
            ans %= MOD;
            remw--;
        }
    }
    cout << ans << '\n';
}