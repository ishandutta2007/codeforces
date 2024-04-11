#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7005;
typedef bitset<MAXN> BS;
int mobius[MAXN];
BS def[MAXN], help[MAXN], cur[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int m = 1; m < MAXN; m++) {
        for(int d = 1; d < MAXN; d++)
            if(m % d == 0)
                def[m].set(d);
    }
    for(int m = 1; m < MAXN; m++) {
        mobius[m] = 1;
        for(int d = 2; d < 100; d++) {
            if(m % (d * d) == 0) {
                mobius[m] = 0;
            }
        }
    }
    for(int m = 1; m < MAXN; m++) {
        for(int i = 1; i * m < MAXN; i++)
            if(mobius[i])
                help[m].set(m * i);
    }
    int n, q;
    cin >> n >> q;
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            int v;
            cin >> v;
            cur[x] = def[v];
        }
        if(t == 2) {
            int y, z;
            cin >> y >> z;
            cur[x] = cur[y] ^ cur[z];
        }
        if(t == 3) {
            int y, z;
            cin >> y >> z;
            cur[x] = cur[y] & cur[z];
        }
        if(t == 4) {
            int v;
            cin >> v;
            cout << (cur[x] & help[v]).count() % 2;
        }
        /*cout << q << endl;
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
            for(int j = 20; j > 0; j--)
                cout << cur[i][j];
            cout << endl;
        }
        cout << endl;*/
    }
    cout << endl;
}