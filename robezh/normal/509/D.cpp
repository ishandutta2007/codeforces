#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;
const ll VAL = -(ll)2e18;

int n, m;
int w[N][N], tw[N][N];
ll a[N], b[N];

void No() {
    cout << "NO" << endl;
    exit(0);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> w[i][j];
    }
    ll mod = -1;
    for(int swapped = 0; swapped < 2; swapped++) {
        if(swapped) {
            for(int i = 0; i < max(n, m); i++) for(int j = i + 1; j < max(n, m); j++)
                swap(w[i][j], w[j][i]);
            swap(n, m);
        }
        for(int i = 0; i < n - 1; i++) {
            ll a = VAL;
            for(int j = 0; j < m; j++) {
                ll d = w[i+1][j] - w[i][j];
                if(a == VAL) a = d;
                else if(a != d) {
                    if(a == 0) No();
                    else if(a > 0) {
                        if(d >= 0) No();
                        else {
                            ll nmod = a - d;
                            if(mod != -1 && mod != nmod) No();
                            mod = nmod;
                        }
                    }
                    else {
                        if(d <= 0) No();
                        else {
                            ll nmod = d - a;
                            if(mod != -1 && mod != nmod) No();
                            mod = nmod;
                        }
                    }
                }

            }
        }
        if(swapped) {
            for(int i = 0; i < max(n, m); i++) for(int j = i + 1; j < max(n, m); j++)
                    swap(w[i][j], w[j][i]);
            swap(n, m);
        }
    }
    if(mod == -1) mod = (ll)1e18;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(w[i][j] >= mod) No();
    for(int i = 0; i < n; i++) a[i] = w[i][0];
    for(int j = 0; j < m; j++) b[j] = (w[0][j] - w[0][0] + mod) % mod;
    cout << "YES" << endl;
    cout << mod << endl;
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    for(int j = 0; j < m; j++) cout << b[j] << " ";
    cout << "\n";


}