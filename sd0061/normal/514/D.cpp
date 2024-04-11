#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;

int n , m , K , a[5][N];
int f[5][17][N];
int LOG[N] , R[N];

int check(int l , int r) {
    if (l > r) return 0;
    int j = LOG[r - l + 1];
    int sum = 0;
    for (int i = 0 ; i < m ; ++ i)
        sum += max(f[i][j][l] , f[i][j][r - (1 << j) + 1]);
    return sum;
}

void work() {
    int i , j , k , x , y;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 1 ; 1 << i <= n ; ++ i)
        LOG[1 << i] = i;
    for (i = 2 ; i <= n ; ++ i)
        if (!LOG[i])
            LOG[i] = LOG[i - 1];
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            scanf("%d" , &a[j][i]);
            f[j][0][i] = a[j][i];
        }
    }
    for (k = 0 ; k < m ; ++ k) {
        for (j = 1 ; 1 << j <= n ; ++ j)
            for (i = 0 ; i + (1 << j) - 1 < n ; ++ i)
                f[k][j][i] = max(f[k][j - 1][i] , f[k][j - 1][i + (1 << j - 1)]);
    }
    pair<int , int> res(0 , -1);
    for (i = 0 ; i < n ; ++ i) {
        int l = i - 1 , r = n - 1 , mid;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (check(i , mid) <= K)
                l = mid;
            else
                r = mid - 1;
        }
        R[i] = l; 
        res = max(res , make_pair(l - i + 1 , i));
    }
    if (res.first) {
        int l = res.second , r = R[l];
        j = LOG[r - l + 1];
        for (i = 0 ; i < m ; ++ i)
            printf("%d " , max(f[i][j][l] , f[i][j][r - (1 << j) + 1]));
    } else {
        for (i = 0 ; i < m ; ++ i)
            printf("0 ");
    }
}

int main() {
//    freopen("1" , "r" , stdin);

    work();
    return 0;
}