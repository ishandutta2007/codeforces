#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int ALL = 500, INF = (int)2e9;

int n, m;
P best[ALL][2];
int mm[ALL];
int val[ALL];

int a[10];

int main() {
    for(int i = 0; i < ALL; i++) best[i][0] = best[i][1] = {-1, -1};
    mm[0]=-1;
    for(int i = 1; i < ALL; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[j];
        for(int mask = 0; mask < (1 << m); mask++) {
            if(mask == 0) val[0] = INF;
            else val[mask] = min(val[mask ^ (1 << mm[mask])], a[mm[mask]]);
            P cur = {val[mask], i};
            for(int j = 0; j < 2; j++) {
                if(cur.first > best[mask][j].first) swap(cur, best[mask][j]);
            }
        }
//        cout << i << ": " << endl;
//        for(int j = 0; j < (1 << m); j++) cout << j << ": " << val[j] << endl;
    }
    int res = -1, oi = -1, oj = -1;
    int all = (1 << m) - 1;
    for(int mask = 0; mask < (1 << m); mask++) {
        P p1 = best[mask][0];
        P p2 = best[all ^ mask][0];
        if(min(p1.first, p2.first) > res) {
            res = min(p1.first, p2.first);
            oi = p1.second;
            oj = p2.second;
        }
    }
//    cout << res << endl;
    cout << oi + 1 << " " << oj + 1 << endl;

}