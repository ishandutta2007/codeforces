#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 105;
int n;
LL f[6][N];
int main() {
    cin >> n;
    f[0][n] = 1;
    for (int k = 0 ; k < 5 ; ++ k) {
        for (int i = 0 ; i <= n ; ++ i) {
            for (int j = 0 ; j < i ; ++ j) {
                f[k + 1][j] += f[k][i] * (n - k);
            }           
        }
    }
    LL res = 0;
    for (int i = 0 ; i <= n ; ++ i)
        res += f[5][i];
    cout << res << endl;
    return 0;
}