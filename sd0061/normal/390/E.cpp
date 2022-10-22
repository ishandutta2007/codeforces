#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 4000005

struct CHU_2_BIT
{
    int n;
    LL B[N] , C[N];
    void init(int size) {
        n = size;
        memset(B , 0 , sizeof(B));
        memset(C , 0 , sizeof(C));
    }
    CHU_2_BIT() {}
    CHU_2_BIT(int size) {
        init(size);
    }
    void _add(LL* c , int x , LL w) {
        for ( ; x <= n ; x += x & -x)
            c[x] += w;
    }
    LL _sum(LL* c , int x) {
        LL res = 0;
        for ( ; x > 0 ; x -= x & -x)
            res += c[x];
        return res;
    }
    void add(int l , int r , LL w) {
        _add(B , l , w) , _add(B , r + 1 , -w);
        _add(C , l , w * l) , _add(C , r + 1 , -w * (r + 1));
    }
    LL sum(int l , int r) {
        LL res = 0;
        res += (r + 1) * _sum(B , r) - l * _sum(B , l - 1);
        res -= _sum(C , r) - _sum(C , l - 1);
        return res;
    }
}R , C;
int n , m , Q;

void work()
{
    int i , j , x1 , y1 , x2 , y2 , w;
    scanf("%d%d%d",&n,&m,&Q);
    R.init(n) , C.init(m);
    while (Q --)
    {
        scanf("%d",&j);
        if (!j)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&w);
            R.add(x1 , x2 , (LL)w * (y2 - y1 + 1));
            C.add(y1 , y2 , (LL)w * (x2 - x1 + 1));
        }
        else
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            printf("%I64d\n" , -R.sum(1 , x1 - 1) - R.sum(x2 + 1 , n) + C.sum(y1 , y2));
        }
    }
}

int main()
{
    work();
    return 0;
}