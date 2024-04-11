#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <set>
#include <map>
typedef long long LL;
using namespace std;
#define N 1000005
int n , Q = 1e9 + 7;
char s[N];
void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}
int f[N][2][2];
void work()
{
    int i , j , k , l;
    scanf("%s" , s + 1);
    n = strlen(s + 1);
    // i
    // ii+1
    if (s[1] == '*' || s[1] == '?')
        f[0][0][1] = 1;
    if (s[1] != '*')
        f[0][0][0] = 1;

    for (i = 1 ; i <= n ; ++ i) {
        for (j = 0 ; j < 2 ; ++ j) {
            for (k = 0 ; k < 2 ; ++ k) {
                if (!f[i - 1][j][k])
                    continue;
                // ii+1
                for (l = 0 ; l < 2 ; ++ l) {
                    if (i == n && l) continue;
                    if (s[i + 1] == '*' && !l) continue;
                    if (isdigit(s[i + 1]) && l) continue;

                    int x = j + k + l;
                    if (!isdigit(s[i]) || s[i] == x + '0') {
                        add(f[i][k][l] , f[i - 1][j][k]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (i = 0 ; i < 2 ; ++ i)
        for (j = 0 ; j < 2 ; ++ j)
            add(ans , f[n][i][j]);
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}