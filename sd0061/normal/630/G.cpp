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
const int N = 100005;
LL f[505][4][6];
int main() {
    int n;
    cin >> n;
    f[0][0][0] = 1;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j <= 3 ; ++ j) {
            for (int k = 0 ; k <= 5 ; ++ k) {
                for (int a = 0 ; j + a <= 3 ; ++ a) {
                    for (int b = 0 ; k + b <= 5 ; ++ b) {
                        f[i + 1][j + a][k + b] += f[i][j][k];
                    }
                }
            }
        }
    }
    cout << f[n][3][5] << endl;
    return 0;
}