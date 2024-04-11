#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 105
int n , m , K;
vector<int> deg;
int cnt[1 << 11] , sum[1 << 11];
bool f[15][25][1 << 11];

void work()
{
    int i , j , k , l , x;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &x);
        if (x == 1)
            ++ K;
        else
            deg.push_back(x);
    }
    m = deg.size();
    if (n == 1) {
        puts(m ? "NO" : "YES");
        return;
    }
    if (m > 11) {
        puts("NO");
        return;
    }
    sort(deg.begin() , deg.end());
    for (i = 0 ; i < 1 << m ; ++ i)
        for (j = 0 ; j < m ; ++ j)
            if (i >> j & 1)
                cnt[i] += deg[j] , ++ sum[i];
    f[0][0][0] = 1;
    for (i = 0 ; i < m ; ++ i)
        for (j = 0 ; j <= K ; ++ j)
            for (k = 0 ; k < 1 << m ; ++ k) {
                if (!f[i][j][k]) continue;
                x = ((1 << m) - 1) ^ k;
                for (l = x ;  ; l = (l - 1) & x) {
                    if (cnt[l] >= deg[i]) continue;
                    if (deg[i] - cnt[l] - 1 <= K - j && sum[l] + deg[i] - cnt[l] > 2)
                        f[i + 1][j + deg[i] - cnt[l] - 1][k | l] = 1;
                    if (!l) break;
                }
            }
    puts(f[m][K][(1 << m - 1) - 1] ? "YES" : "NO");
}

int main()
{
    work();
    return 0;
}