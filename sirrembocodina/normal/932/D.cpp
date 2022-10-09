#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

ll mod = 1000000007;

int lca[400100][20];
int len[400100];
ll s[400100][20];
int w[400100];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    int cnt = 0;
    int last = 0;
    len[0] = 1;
    forn (q, Q) {
        int t, x;
        ll y;
        cin >> t >> x >> y;
        x ^= last;
       --x;
        y ^= last;
//        cerr << x << " " << y << endl;
        if (t == 1) {
            ++cnt;
            w[cnt] = y;
            for (int i = 20 - 1; i >= 0; --i) {
                if (w[lca[x][i]] < y) {
                    x = lca[x][i];
                }
            }
            if (w[x] < y) {
                x = lca[x][0];
            }
            if (w[x] < y) {
                x = cnt;
            }
            lca[cnt][0] = x;
            len[cnt] = len[x] + 1;
            s[cnt][0] = y;
            forn (i, 20 - 1) {
                lca[cnt][i + 1] = lca[lca[cnt][i]][i];
                s[cnt][i + 1] = s[cnt][i] + s[lca[cnt][i]][i];
            }
//            cerr << "p " << x << endl;
//            cerr << "len " <<len[cnt] << endl;
        } else {
            last = 0;
            int upp = len[x];
            for (int i = 20 - 1; i >= 0; --i) {
                if (s[x][i] <= y) {
                    y -= s[x][i];
                    x = lca[x][i];
                    last += 1 << i;
                }
            }
            last = min(last, upp);
            cout << last << endl;
        }
    }
    return 0;
}