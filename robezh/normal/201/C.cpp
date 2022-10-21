#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef long long ll;

int n;
int a[N];
ll ssum[2][N], psum[2][N];

int main() {
    cin >> n;
    n--;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--) {
        if(a[i] <= 1) ssum[1][i] = 0;
        else ssum[1][i] = a[i] / 2 * 2 + ssum[1][i+1];
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] <= 1) psum[1][i] = 0;
        else psum[1][i] = a[i] / 2 * 2 + psum[1][i-1];
    }
    for(int i= n; i >= 1; i--) {
        ssum[0][i] = (a[i] - 1) / 2 * 2 + 1 + max(ssum[1][i+1], ssum[0][i+1]);
    }
    for(int i = 1; i <= n; i++) {
        psum[0][i] = (a[i] - 1) / 2 * 2 + 1 + max(psum[1][i-1], psum[0][i-1]);
    }
    ll res = 0;
    for(int i = 1; i <= n + 1; i++) {
        res = max(res, psum[0][i-1] + ssum[1][i]);
        res = max(res, psum[1][i-1] + ssum[1][i]);
        res = max(res, psum[1][i-1] + ssum[0][i]);
    }
    cout << res << endl;
}