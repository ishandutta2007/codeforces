#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld eps = 1e-6;
ld glasses[15][15];

int main() {
    int n, ans = 0;
    cin >> n >> glasses[0][0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(glasses[i][j] >= 1.0 - eps) {
                ans++;
                glasses[i][j] -= 1.0;
                glasses[i + 1][j] += glasses[i][j]/2.0;
                glasses[i + 1][j + 1] += glasses[i][j]/2.0;
            }
        }
    }
    cout << ans << endl;
}