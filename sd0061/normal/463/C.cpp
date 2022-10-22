#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 2005;
int n , a[N][N];
LL R[N + N] , C[N + N];
void work() {
    int i , j ;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < n ; ++ j) {
            scanf("%d",&a[i][j]);
            R[i + j + 1] += a[i][j];
            C[i - j + n] += a[i][j];
        }
    int X1 , X2 , Y1 , Y2;
    LL max1 = -1 , max2 = -1;
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < n ; ++ j) {
            LL x = R[i + j + 1] + C[i - j + n] - a[i][j];
            if (i + j & 1) {
                if (x > max1) {
                    max1 = x;
                    X1 = i + 1;
                    Y1 = j + 1;
                }
            } else {
                if (x > max2) {
                    max2 = x;
                    X2 = i + 1;
                    Y2 = j + 1;
                }
            }
        }
    cout << max1 + max2 << endl;
    cout << X1 << ' ' << Y1 << ' ';
    cout << X2 << ' ' << Y2 << ' ';
}

int main() {
    work();
    return 0;
}