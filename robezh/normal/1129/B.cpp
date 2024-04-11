#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005;

int k;
int n = 2000;
int res[N];


int main() {
    cin >> k;
    int y = (2000 - k % 2000) % 2000;
    while(y + 2000 <= (int)1e6) y += 2000;
    int zf = 1999 * y - k;
    assert(zf % 2000 == 0);
    int z = zf / 2000;
    res[n-1] = y;
//    cout << y << " " << z <<endl;
    for(int i = n - 2; i >= 0; i--) {
        if(z == 0) continue;
        res[i] -= min((int)1e6, z);
        z -= min((int)1e6, z);
//        cout << res[i] << " ";
    }
    cout << n << endl;
    for(int i = 0; i < n; i++) cout << res[i] << " ";


}