#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
string str[10];

int main() {
    cin >> n >> m;
    rep(i, 0, n) cin >> str[i];
    int cx = 0, cy = 0;
    int res = (str[0][0] == '*');
    while(cx + 1 < n || cy + 1 < n) {
        int mx = -1, my = -1, opt = 100;
        rep(i, cx, n) {
            rep(j, cy, m) {
                if(i == cx && j == cy) continue;
                if(str[i][j] == '*' && abs(i - cx) + abs(j - cy) < opt) {
                    opt = abs(i - cx) + abs(j - cy);
                    mx = i;
                    my = j;
                }
            }
        }
        if(opt == 100) break;
        res++;
        cx = mx;
        cy = my;
    }
    cout << res << '\n';


}