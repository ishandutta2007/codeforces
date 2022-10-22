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
#define N 100005
int n , a[N] , m;

struct stree
{
    int l , r;
    LL sum;
    stree() {}
    stree(int x) { l = r = sum = x;}
}t[17][N << 1];
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

void Build(int q , int l , int r)
{
    int p = id(l , r);
    if (l == r)
    {
        t[q][p] = stree(a[l] >> q & 1);
        return;
    }MID;
    Build(q , Left) , Build(q , Right);
    int L = id(Left) , R = id(Right);
    t[q][p].l = t[q][L].l == mid - l + 1 ? t[q][L].l + t[q][R].l : t[q][L].l;
    t[q][p].r = t[q][R].r == r - mid     ? t[q][L].r + t[q][R].r : t[q][R].r;
    t[q][p].sum = t[q][L].sum + t[q][R].sum - (LL)t[q][L].r * (t[q][L].r + 1) / 2 - (LL)t[q][R].l * (t[q][R].l + 1) / 2;
    t[q][p].sum += (LL)(t[q][L].r + t[q][R].l) * (t[q][L].r + t[q][R].l + 1) / 2;
    p = p + 1;
}
void update(int q , int l , int r , int x , int w)
{
    int p = id(l , r);
    if (l == r)
    {
        t[q][p] = stree(w);
        return;
    }MID;
    int L = id(Left) , R = id(Right);
    if (x <= mid)
        update(q , Left , x , w);
    else
        update(q , Right , x , w);
    t[q][p].l = t[q][L].l == mid - l + 1 ? t[q][L].l + t[q][R].l : t[q][L].l;
    t[q][p].r = t[q][R].r == r - mid     ? t[q][L].r + t[q][R].r : t[q][R].r;
    t[q][p].sum = t[q][L].sum + t[q][R].sum - (LL)t[q][L].r * (t[q][L].r + 1) / 2 - (LL)t[q][R].l * (t[q][R].l + 1) / 2;
    t[q][p].sum += (LL)(t[q][L].r + t[q][R].l) * (t[q][L].r + t[q][R].l + 1) / 2;
}


void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (j = 0 ; j <= 16 ; ++ j)
        Build(j , 1 , n);
    while (m --)
    {
        scanf("%d%d",&x,&y);
        for (j = 0 ; j <= 16 ; ++ j)
            update(j , 1 , n , x , y >> j & 1);
        LL ans = 0;
        for (j = 16 ; j >= 0 ; -- j)
            ans <<= 1 , ans += t[j][id(1 , n)].sum;
        printf("%I64d\n" , ans);
    }


}

int main()
{
        work();
    return 0;
}