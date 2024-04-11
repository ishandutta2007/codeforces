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
const int N = 300005;
int n , m;
LL a[N] , F[N];
int T[N][2] , S[N][2];
const LL Q = 1e9 + 9 , SQR = 383008016;
LL inv(LL x) {return x == 1 ? 1 : (Q - Q / x) * inv(Q % x) % Q;}
const LL INV2 = inv(2) , INVSQR = inv(SQR);
const LL P1 = (1 + SQR) * INV2 % Q;
const LL P2 = (1 + Q - SQR) * INV2 % Q;
const LL INVP1 = inv(Q + 1 - P1) , INVP2 = inv(Q + 1 - P2);
LL pw1[N] , pw2[N];
struct stree {
    LL f1 , f2;
    LL s;
}t[N << 1];
inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

inline void pushdown(int l , int mid , int r) {
    int p = id(l , r) , L = id(Left) , R = id(Right);
    t[L].f1 += t[p].f1 , t[L].f1 %= Q;
    t[L].f2 += t[p].f2 , t[L].f2 %= Q;
    t[L].s += t[p].f1 * (Q + 1 - pw1[mid - l + 1]) % Q * INVP1 % Q;
    t[L].s -= t[p].f2 * (Q + 1 - pw2[mid - l + 1]) % Q * INVP2 % Q;
    if (t[L].s < 0) t[L].s += Q; t[L].s %= Q;

    t[p].f1 *= pw1[mid - l + 1] , t[p].f1 %= Q;
    t[p].f2 *= pw2[mid - l + 1] , t[p].f2 %= Q;

    t[R].f1 += t[p].f1 , t[R].f1 %= Q;
    t[R].f2 += t[p].f2 , t[R].f2 %= Q;
    t[R].s += t[p].f1 * (Q + 1 - pw1[r - mid]) % Q * INVP1 % Q;
    t[R].s -= t[p].f2 * (Q + 1 - pw2[r - mid]) % Q * INVP2 % Q;
    if (t[R].s < 0) t[R].s += Q; t[R].s %= Q;
    t[p].f1 = t[p].f2 = 0;
}
void add(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].f1 += pw1[l - top + 1] , t[p].f1 %= Q;
        t[p].f2 += pw2[l - top + 1] , t[p].f2 %= Q;
        t[p].s += pw1[l - top + 1] * (Q + 1 - pw1[r - l + 1]) % Q * INVP1 % Q;
        t[p].s -= pw2[l - top + 1] * (Q + 1 - pw2[r - l + 1]) % Q * INVP2 % Q;
        if (t[p].s < 0) t[p].s += Q; t[p].s %= Q;
        return;
    } MID; pushdown(l , mid , r);
    if (top <= mid)
        add(Left , top , bot);
    if (bot > mid)
        add(Right , top , bot);
    t[p].s = (t[id(Left)].s + t[id(Right)].s) % Q;
}
LL query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        return t[p].s;
    } MID; pushdown(l , mid , r); LL res = 0;
    if (top <= mid)
        res += query(Left , top , bot) , res %= Q;
    if (bot > mid)
        res += query(Right , top , bot) , res %= Q;
    return res;
}

void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&x) , a[i] = (a[i - 1] + x) % Q;
    pw1[0] = pw2[0] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        pw1[i] = pw1[i - 1] * P1 % Q;
        pw2[i] = pw2[i - 1] * P2 % Q;
    }
    while (m --) {
        scanf("%d%d%d",&i,&x,&y);
        if (i == 1)
            add(1 , n , x , y);
        else {
            j = (a[y] - a[x - 1] + Q) % Q;
            j += query(1 , n , x , y) * INVSQR % Q;
            printf("%d\n" , j % Q);
        }
    }
}
int main()
{
    work();
    return 0;
}