#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define N 2005
int Q = 1e9 + 7;
int n , K;
void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}
int f[N][N];
void work()
{
    int i , j , k , ans = 0;
    cin >> n >> K;
    for (i = 1 ; i <= n ; ++ i)
        f[1][i] = 1;
    for (i = 1 ; i < K ; ++ i) {
        for (j = 1 ; j <= n ; ++ j) {
            if (f[i][j]) {
                for (k = j ; k <= n ; k += j) {
                    add(f[i + 1][k] , f[i][j]);
                }
            }
        }
    }
    for (i = 1 ; i <= n ; ++ i)
        add(ans , f[K][i]);
    cout << ans << endl;
}


int main()
{
    //freopen("~inputs.txt" , "r" , stdin);
    work();
    return 0;
}