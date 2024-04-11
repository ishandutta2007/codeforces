#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 100005;
int m , n , q;
int a[N];
int t[N] , l[N] , c[N];
void work() {
    int i , j; LL x;
    scanf("%d",&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d",&t[i]);
        if (t[i] == 1) {
            scanf("%d" , &l[i]);
            if (n < 100000)
                a[n ++] = l[i];
        } else {
            scanf("%d%d",&l[i] , &c[i]);
            LL cnt = (LL)l[i] * c[i];
            for (j = 0 ; j < cnt && n < 100000 ; ++ j) {
                a[n ++] = a[j % l[i]];
            }
        }
    }
    LL cnt = 0 , delta; i = 0;
    scanf("%d",&q);
    while (q --) {
        scanf("%I64d" , &x);

        while (i < m) {
            if (t[i] == 1)
                delta = 1;
            else
                delta = (LL) l[i] * c[i];
            if (cnt < x && x <= cnt + delta) {
                if (t[i] == 1)
                    printf("%d " , l[i]);
                else
                    printf("%d " , a[(x - cnt - 1) % l[i]]);
                break;
            } else if (x > cnt + delta) {
                cnt += delta;
                ++ i;
            }
        }

    }

}

int main()
{
    work();
    return 0;
}