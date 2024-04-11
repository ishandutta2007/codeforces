#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string str[3];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, 3) cin >> str[i];
        pii zs[3] = {{0, 0}, {0, 1}, {0, 2}};
        rep(i, 0, 3) {
            rep(j, 0, 2 * n) zs[i].first += (str[i][j] == '0');
        }
        sort(zs, zs + 3);
        bool reverted = false;
        if(zs[1].first <= n) {
            reverted = true;
            rep(i, 0, 3) {
                zs[i].first = 2 * n - zs[i].first;
                rep(j, 0, 2 * n) str[i][j] = (str[i][j] == '0' ? '1' : '0');
            }
        }
        sort(zs, zs + 3);
        string res;
        int r = 0;
        int c = zs[1].second, nx = zs[2].second;
//        cout << zs[1].second << zs[2].second << endl;
        for(int i = 0; i < 2 * n; i++) {
            if(str[c][i] == '1') res.push_back('1');
            else {
                while(r < 2 * n && str[nx][r] != '0') {
                    res.push_back('1');
                    r++;
                }
                assert(r < 2 * n);
                res.push_back('0');
                r++;
            }
        }
        while(r < 2 * n) res.push_back(str[nx][r++]);
        while(sz(res) < 3 * n) res.push_back('0');
        if(reverted) {
            rep(j, 0, 3 * n) res[j] = (res[j] == '0' ? '1' : '0');
        }
        cout << res << '\n';
    }

}