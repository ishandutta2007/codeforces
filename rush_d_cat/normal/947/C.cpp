#include <iostream>
using namespace std;
#define N 10000000+5
typedef long long LL;
int ch[N][2], fa[N];
int sum[N], cnt;

void insert(LL x) 
{
    int rt = 0;
    for (int i = 31; i >= 0; i --) 
    {
        int bit = (x >> i) & 1;
        if (!ch[rt][bit])
        {
            ch[rt][bit] = ++cnt;
            fa[cnt] = rt;
        }
        rt = ch[rt][bit];
    }

    sum[rt]  ++;
    rt = fa[rt];
    while (rt) 
    {
        sum[rt] = sum[ch[rt][0]] + sum[ch[rt][1]];
        rt = fa[rt];
    }

} 

LL query(LL x) 
{
    int rt = 0; LL ret = 0;
    for (int i = 31; i >= 0; i --)
    {
        int bit = (x >> i) & 1;
        if (sum[ch[rt][bit]])
        {
            rt = ch[rt][bit];
        } else {
            ret |= 1 << i;
            rt = ch[rt][bit ^ 1];
        }
    }
    sum[rt] --;
    rt = fa[rt];
    while (rt) 
    {
        sum[rt] = sum[ch[rt][0]] + sum[ch[rt][1]];
        rt = fa[rt];
    }
    return ret;
}

int n; 
LL a[N], p[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &p[i]);
        insert(p[i]);
    }
    for (int i = 1; i <= n; i ++) {
        printf("%lld\n", query(a[i]));
    }
}