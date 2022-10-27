#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
const LL MOD = 998244353;
LL f[N][2];int n;

vector<int> ans;
int main() {
    cin >> n;
    ans.push_back(1); ans.push_back(2);
    int las = 2; 
    while (1) {
        if (las % 2 == 0) {
            ans.push_back(las * 2);
            ans.push_back(las * 2 + 1);
            las = las * 2 + 1;
        } else {
            ans.push_back(las * 2 - 1);
            ans.push_back(las * 2);
            las = las * 2;
        }
        if (las > 1000000) break;
    }
    for (auto x: ans) {
        //printf("%d\n", x); 
        
        if (x == n) {
            return !printf("%d\n", 1);
        } 
    }
    printf("0\n");
    return 0;

    cin >> n;
    f[0][0] = f[0][1] = 1;
    f[1][1] = 1, f[1][0] = 0;
    for (int i = 2; i <= n; i ++) {
        //printf("i = %d\n", i);
        for (int x = 0; x <= i - 1; x ++) {
            if (abs((int)log2(x) - (int)log2(i-x-1)) > 1) continue;
            if (abs((int)log2(x) - (int)log2(i-x-1)) == 1) {
                if (x < i-x-1 && ((x+1)&(-(x+1))) != (x+1)) continue;
                if (x > i-x-1 && ((i-x)&(-(i-x))) != i-x) continue;
            }
            //printf("lef = %d, rig = %d\n", x, i-x-1);
            //printf("(%d, %d)\n", (int)log2(x),  (int)log2(i-x-1));
            if (x % 2) {
                (f[i][0] += (f[x][1] * f[i-x-1][0]) % MOD) %= MOD;
            } else {
                (f[i][1] += (f[x][0] * f[i-x-1][0]) % MOD) %= MOD;
            }
        }
        if (f[i][0] + f[i][1] > 0)printf("i = %d, %d %d %d\n", i, f[i][0], f[i][1], f[i][0] + f[i][1]);
    }
    printf("%lld\n", (f[n][0] + f[n][1]) % MOD);
    /*
    for (int i = 1; i  <= 1000;  ++ i) {
        printf("%d %d %d\n", f[i][0], f[i][1], f[i][0] + f[i][1]);
    } 
    */
}