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
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 300005;
int n , a[N];
ULL MAGIC = 3 , power[N];
struct stree {
    ULL Hl , Hr;
}t[N << 1];
inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

inline void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].Hl = t[L].Hl * power[r - mid] + t[R].Hl;
    t[p].Hr = t[R].Hr * power[mid - l + 1] + t[L].Hr;
}

void update(int l , int r , int x , int w) {
    int p = id(l , r);
    if (l == r) {
        t[p].Hl = t[p].Hr = w + 1;
        return;
    } MID;
    if (x <= mid)
        update(Left , x , w);
    else
        update(Right , x , w);
    pushup(p , l , mid , r);
}
ULL gethashl(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p].Hl;
    MID;
    if (bot <= mid)
        return gethashl(Left , top , bot);
    else if (top > mid)
        return gethashl(Right , top , bot);
    else
        return gethashl(Left , top , mid) * power[bot - mid] + gethashl(Right , mid + 1 , bot);
}
ULL gethashr(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p].Hr;
    MID;
    if (bot <= mid)
        return gethashr(Left , top , bot);
    else if (top > mid)
        return gethashr(Right , top , bot);
    else
        return gethashr(Right , mid + 1 , bot) * power[mid - top + 1] + gethashr(Left , top , mid);
}

void work() {
    int i , x , y;
    scanf("%d",&n) , power[0] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
        update(1 , n , i , 0);
        power[i] = power[i - 1] * MAGIC;
    }
    for (i = 1 ; i <= n ; ++ i) {
        update(1 , n , a[i] , 1);
        x = min(a[i] - 1 , n - a[i]);
        //[a[i] - x , a[i] - 1]
        //[a[i] + 1 , a[i] + x]
        if (x && gethashl(1 , n , a[i] - x , a[i] - 1) != gethashr(1 , n , a[i] + 1 , a[i] + x)) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main()
{
    work();
    return 0;
}