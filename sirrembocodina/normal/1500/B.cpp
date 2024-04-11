#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int wx[1000000];
int wy[1000000];
int wc[1000000];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    //n = 500000;
    //m = 499999;
    //k = 1e12;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        //x = i + 1;
        x--;
        wx[x] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        //y = i + 1;
        y--;
        wy[y] = i + 1;
    }
    int x, y, d;
    d = gcd(n, m, x, y);
    y = -y;
    m /= d;
    vector<int> good;
    for (int i = 0; i < 1000000; i++) {
        if (!wx[i] || !wy[i] || abs(wx[i] - wy[i]) % d) {
            continue;
        }
        good.push_back(i);
        wc[i] = (wy[i] - wx[i]) / d;
        wc[i] *= -x;
        wc[i]--;
        if (wc[i] >= 0) {
            wc[i] %= m;
        } else {
            wc[i] = -wc[i] % m;
            if (wc[i] > 0) {
                wc[i] = m - wc[i];
            }
        }
    }
    int l = 0, r = 9e18;
    while (r - l > 1) {
        int mid = ((unsigned long long)(l) + (unsigned long long)(r)) / 2;
        int cnt = 0;
        for (int i: good) {
            if (k < wx[i]) {
                continue;
            }
            cnt += ((mid - wx[i]) / n + 1 + wc[i]) / m;
        }
        cnt = mid - cnt;
        if (cnt < k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
//    cerr << clock() * 1.0 / CLOCKS_PER_SEC;
}
/*


1 6 4 3 5 7 2 8 1 6 4 3 5 7 2 8 1 6 4 3 5 7 2 8 1 6 4 3 5 7 2 8 1 6 4 3 5 7 2 8 1 6 4 3 5 7 
1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 3 2 1 



*/