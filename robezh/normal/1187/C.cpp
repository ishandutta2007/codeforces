#include <bits/stdc++.h>
using namespace std;

const int N = 1005, E4 = (int)1e4;

struct qry {
    int t, l, r;
} qr[N];

int n, m;
bool eq[N];
int res[N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> qr[i].t >> qr[i].l >> qr[i].r;
        qr[i].l--, qr[i].r--;
        if(qr[i].t) {
            for(int j = qr[i].l + 1; j <= qr[i].r; j++) eq[j] = true;
        }
    }
    res[0] = E4;
    for(int i = 1; i < n; i++) {
        res[i] = res[i-1];
        if(!eq[i]) res[i]--;
    }
    for(int i = 0; i < m; i++) {
        if(!qr[i].t) {
            bool found = false;
            for(int j = qr[i].l + 1; j <= qr[i].r; j++) {
                if(res[j-1] > res[j]) found = true;
            }
            if(!found) return cout << "NO" << endl, 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << res[i] << " ";

}