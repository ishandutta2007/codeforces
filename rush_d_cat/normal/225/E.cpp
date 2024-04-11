#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int p[40] = {2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,
2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,
44497,86243,110503,132049,216091,756839,859433,1257787,
1398269,2976221,3021377,6972593,13466917,20996011};
int mpow(int a,int x)  {
    if(x==0) return 1;
    int t = mpow(a,x>>1);
    if(x%2==0) return 1LL*t*t%MOD;
    return 1LL*t*t%MOD*a%MOD;
}

int main() {
    int n; cin >> n;
    n --;
    int k = p[n] - 1;
    int ans = mpow(2,k);
    ans = (ans-1+MOD) % MOD;
    cout << ans << endl;
}