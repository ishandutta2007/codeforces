#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , m , p[N] , h[N];
int f[18][N];
LL c[18][N];

int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

pair<int , int> t[N << 1];

void update(int l , int r , int x , pair<int , int> w) {
    int p = id(l , r);
    if (l == r) {
        t[p] = w;
    } else {
        MID;
        if (x <= mid)
            update(Left , x , w);
        else
            update(Right , x , w);
        t[p] = max(t[id(Left)] , t[id(Right)]);
    }
}

pair<int , int> query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID; pair<int , int> res(-1 << 30 , -1 << 30);
    if (top <= mid) res = max(res , query(Left , top , bot));
    if (bot > mid) res = max(res , query(Right , top , bot));
    return res;
}

int main() {
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&p[i] , &h[i]);
    }
    f[0][n] = n + 1 , c[0][n] = 0;
    update(1 , n , n , make_pair(n + 1 , 0));
    f[0][n + 1] = n + 1 , c[0][n + 1] = 0;
    for (i = n - 1 ; i > 0 ; -- i) {
        if (h[i] + p[i] < p[i + 1]) {
            f[0][i] = i + 1;
            c[0][i] = p[i + 1] - h[i] - p[i];
        } else {
            x = upper_bound(p + 1 , p + 1 + n , h[i] + p[i]) - p;
            pair<int , int> tmp = query(1 , n , i + 1 , x - 1);
            f[0][i] = tmp.first;
            c[0][i] = -tmp.second;
            if (x == f[0][i]) {
                c[0][i] = min(c[0][i] , (LL)p[x] - h[i] - p[i]);
            }
        }
        update(1 , n , i , make_pair(f[0][i] , -c[0][i]));
    }
    //for (i = 1 ; i <= n ; ++ i)
    //    printf("%d : %d %d\n"  , i , f[0][i] , c[0][i]);
    for (j = 1 ; 1 << j < n ; ++ j)
        for (i = 1 ; i <= n + 1 ; ++ i) {
            f[j][i] = f[j - 1][f[j - 1][i]];
            c[j][i] = c[j - 1][i] + c[j - 1][f[j - 1][i]];
        }
    int L = j - 1;
    scanf("%d",&m);
    while (m --) {
        LL res = 0;
        scanf("%d%d",&x,&y);
        for (j = L ; j >= 0 ; -- j) {
            if (f[0][f[j][x]] <= y) {
                res += c[j][x];
                x = f[j][x];
            }
        }
        if (f[0][x] <= y) {
            res += c[0][x];
        }
        printf("%I64d\n" , res);
    }
    return 0;
}