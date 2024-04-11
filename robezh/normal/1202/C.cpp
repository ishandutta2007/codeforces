#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

struct node {
    int xl, xr, yu, yd;

    void init() {
        xl = xr = yu = yd = 0;
    }

    void print() {
        cout << xl << " " << xr << " " << yu << " " << yd << endl;
    }

    void update(char c, int rev) {
        if((rev && c == 'S') || (!rev && c == 'W')) {
            yu++;
            yd = min(0, yd + 1);
        }
        else if((rev && c == 'W') || (!rev && c == 'S')) {
            yd--;
            yu = max(0, yu - 1);
        }
        else if((rev && c == 'A') || (!rev && c == 'D')) {
            xr++;
            xl = min(0, xl + 1);
        }
        else {
            xl--;
            xr = max(0, xr - 1);
        }
    }
} L[N], R[N];

int T, n;
string str;
char dirc[4] = {'W', 'A', 'S', 'D'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> str;
        n = str.length();
        str = " " + str;
        L[0].init(), R[n + 1].init();
        for(int i = 1; i <= n; i++) L[i] = L[i-1], L[i].update(str[i], 1);
        for(int i = n; i >= 1; i--) R[i] = R[i+1], R[i].update(str[i], 0);
        ll res = INF;
        for(int i = 1; i <= n; i++) {
            for(int d = 0; d < 4; d++) {
                node nl = L[i], nr = R[i+1];
                nl.update(dirc[d], 1);
//                nr.update(dirc[d]);
                int xl = min(nl.xl, nr.xl);
                int xr = max(nl.xr, nr.xr);
                int yd = min(nl.yd, nr.yd);
                int yu = max(nl.yu, nr.yu);
//                if(1LL * (xr - xl + 1) * (yu - yd + 1) == 6) {
//                    cout << i << " " << dirc[d] << endl;
//                    nl.print();
//                    nr.print();
//                }
                res = min(res, 1LL * (xr - xl + 1) * (yu - yd + 1));
            }
        }
        cout << res << "\n";

    }
}