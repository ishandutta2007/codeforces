#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int S = 350, N = (int)1e5 + 50;

int n, m, q;
int go[N][S];
vi to[N];
int rto[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    fill(rto, rto + n, -1);
    rep(i, 0, m) {
        int l, r; cin >> l >> r; l--, r--;
        to[l].push_back(r);
        rto[r] = l;
    }
    rep(i, 0, (n - 1) / S + 1) {
        int r = i * S;
        stack<pii> St;
        for(int j = r; j >= 0; j--) {
            for(int rj : to[j]) {
                if(rj > r) continue;
                while(!St.empty() && rj >= St.top().second) St.pop();
                if(St.empty() || rj < St.top().first) St.push({j, rj});
                else St.top().first = j;
            }
            go[j][i] = (St.empty() || St.top().first > j ? j : St.top().second);
//            cout << "go " << j + 1 << " " << r + 1 << " " << go[j][i] + 1 << endl;
        }
    }

    cin >> q;
    while(q--) {
        int x, y; cin >> x >> y; x--, y--;
        int by = y / S * S;
        int tl, tr, tx;
        if(x > by) tl = x, tr = y, tx = x;
        else tl = by, tr = y, tx = go[x][by / S];
//        cout << tl + 1 << " " << tr + 1 << " " << tx + 1 << endl;
        rep(i, tl, tr + 1) {

            if(rto[i] != -1)  {
                int l = rto[i];
                if(x <= l && l <= tx) tx = i;
            }
        }
        cout << tx + 1 << '\n';
    }
}