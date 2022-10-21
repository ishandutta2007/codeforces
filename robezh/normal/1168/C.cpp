#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, B = (int)20;

struct qry {
    int r, id;
};

int n, q, a[N];
int la[B];
vector<qry> qr[N];
int res[N];
int nxt[N][B];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        qr[l].push_back({r, i});
    }
    fill(la, la + B, n);
    memset(nxt, 0x3f, sizeof(nxt));
    for(int i = n - 1; i >= 0; i--) {
        for(int b = 0; b < B; b++) {
            if((a[i] >> b) & 1) {
                if(la[b] != n) {
                    nxt[i][b] = min(nxt[i][b], la[b]);
                    for(int j = 0; j < B; j++) nxt[i][j] = min(nxt[i][j], nxt[la[b]][j]);
                }
                la[b] = i;
            }
        }
        for(auto p : qr[i]) {
            bool good = false;
            for(int b = 0; b < B; b++) {
                if((a[p.r] >> b) & 1) {
                    if(nxt[i][b] <= p.r) {
                        good = true;
                        break;
                    }
                }
            }
            res[p.id] = good;
        }
    }
    for(int i = 0; i < q; i++) cout << (res[i] ? "Shi" : "Fou") << "\n";


}