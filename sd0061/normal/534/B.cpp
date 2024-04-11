#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;

int v1 , v2 , d , t;
int f[105][2005];
void work() {
    cin >> v1 >> v2 >> t >> d;
    memset(f , 0xC0 , sizeof(f));
    f[0][v1] = 0;
    for (int i = 0 ; i < t ; ++ i) {
        for (int j = 0 ; j < 2000 ; ++ j) {
            if (f[i][j] < 0) continue;
            for (int k = -d ; k <= d ; ++ k) {
                if (j + k >= 0 && j + k < 2000)
                    f[i + 1][j + k] = max(f[i + 1][j + k] , f[i][j] + j);
            }
        }
    }
    cout << f[t - 1][v2] + v2 << endl;
}

int main() {
    work();
    return 0;
}