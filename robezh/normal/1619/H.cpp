#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50, B = 400;

struct Qr {
    int tp, x, y;
};

int n, q, p[N];
vector<Qr> qrs;
bool in[N];
vector<vi> cycs;
int idx[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) cin >> p[i], p[i]--;
    qrs.resize(q);
    rep(i, 0, q) {
        cin >> qrs[i].tp >> qrs[i].x >> qrs[i].y;
        if(qrs[i].tp == 1) qrs[i].x--, qrs[i].y--;
        else  qrs[i].x--;

    }
    int cur = 0;
    while(cur < q) {
        int r = min(cur + B, q);
        cycs.clear();
        fill(in, in + n, 0);
//        fill(vis, vis + n, 0);
        for (int i = cur; i < r; i++) {
            auto &qr = qrs[i];
            if(qrs[i].tp == 1) {
                in[p[qr.x]] = in[p[qr.y]] = true;
            } else {
                in[qr.x] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            if(in[i]) {
                vi cyc;
                int cycid = sz(cycs);
                int u = i;
                do {
                    idx[u] = cycid;
                    cyc.push_back(u);
                    u = p[u];
                } while(!in[u]);
                cycs.push_back(cyc);
//                for(int x : cyc) cout << x << " ";
//                cout << endl;
            }
        }
//        cout << "?" << endl;
        for (int i = cur; i < r; i++) {
            auto &qr = qrs[i];
            if(qr.tp == 1) {
                swap(p[qr.x], p[qr.y]);
            } else {
                int cycsz = 0;
                int u = qrs[i].x;
                do {
                    cycsz += sz(cycs[idx[u]]);
                    u = p[cycs[idx[u]].back()];
                } while(u != qrs[i].x);
                qrs[i].y %= cycsz;
                u = qrs[i].x;
                int rem = qrs[i].y;
                while(rem >= sz(cycs[idx[u]])) {
                    rem -= sz(cycs[idx[u]]);
                    u = p[cycs[idx[u]].back()];
                }
                cout << cycs[idx[u]][rem] + 1 << endl;
            }
        }
        cur = r;
    }
}