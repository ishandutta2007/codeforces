#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

char dr[4] = {'R', 'L', 'D', 'U'};
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
map<char, int> mp;

bool check(string &str, int ix, int iy) {
    int x = 0, y = 0;
    for(char c : str) {
        int d = mp[c];
        if(!(x + dx[d] == ix && y + dy[d] == iy)) {
            x += dx[d];
            y += dy[d];
        }
//        cout << x << " " << y << endl;
    }
    return x == 0 && y == 0;
}

void solve() {
    string str; cin >> str;
    int x = 0, y = 0;
    vector<pii> can;
    for(char c : str) {
        for(int d = 0; d < 4; d++) can.push_back({x + dx[d], y + dy[d]});
        int d = mp[c];
        x += dx[d];
        y += dy[d];
    }

    for(pii &p : can) {
//        cout << "checking " << p.first << " " << p.second << endl;
        if(check(str, p.first, p.second)) {
            cout << p.first << " " << p.second << "\n";
            return ;
        }
    }
    cout << "0 0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 0, 4) mp[dr[i]] = i;

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}