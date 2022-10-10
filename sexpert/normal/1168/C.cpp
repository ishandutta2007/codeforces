#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
const int LOG = 20;

int fwd[MAXN][LOG], seen[LOG], a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int l = 0; l < LOG; l++) {
        fwd[n][l] = n + 1;
        seen[l] = n + 1;
        if(a[n] & (1 << l))
            seen[l] = n;
    }
    for(int i = n - 1; i >= 1; i--) {
        for(int l = 0; l < LOG; l++) {
            if(a[i] & (1 << l)) {
                fwd[i][l] = seen[l];
                seen[l] = i;
            }
        }
        for(int l = 0; l < LOG; l++) {
            if(!fwd[i][l]) {
                fwd[i][l] = n + 1;
                for(int k = 0; k < LOG; k++) {
                    if((a[i] & (1 << k)) && fwd[i][k] <= n)
                        fwd[i][l] = min(fwd[i][l], fwd[fwd[i][k]][l]);
                }
            }
        }
    }
    //for(int i = 1; i <= n; i++) {
    //    for(int l = 0; l < LOG; l++)
    //        cout << fwd[i][l] << " ";
    //    cout << endl;
    //}
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        bool can = false;
        for(int l = 0; l < LOG; l++) {
            if((a[y] & (1 << l)) && fwd[x][l] <= y)
                can = true;
        }
        cout << (can ? "Shi\n" : "Fou\n");
    }
}