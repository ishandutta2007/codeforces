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
int n , m;
inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
struct stree {
    int g;
    LL f , sum;
}t[N << 1];

void Build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        t[p].g = l;
    } else {
        MID;Build(Left);Build(Right);
    }
}
void update(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot && t[p].g) {
        t[p].sum += (LL) (r - l + 1) * abs(w - t[p].g);
        t[p].f += abs(w - t[p].g);
        t[p].g = w;
        return;
    } MID; int L = id(Left) , R = id(Right);
    if (t[p].f) {
        t[L].sum += (LL) (mid - l + 1) * t[p].f;
        t[R].sum += (LL) (r - mid) * t[p].f;
        t[L].f += t[p].f , t[R].f += t[p].f;
        t[p].f = 0;
    }
    if (t[p].g) {
        t[L].g = t[R].g = t[p].g;
    }
    if (top <= mid) update(Left , top , bot , w);
    if (bot > mid) update(Right , top , bot , w);
    t[p].g = t[L].g == t[R].g ? t[L].g : 0;
    t[p].sum = t[L].sum + t[R].sum;
}
LL query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p].sum;
    MID; LL res = 0; int L = id(Left) , R = id(Right);
    if (t[p].f) {
        t[L].sum += (LL) (mid - l + 1) * t[p].f;
        t[R].sum += (LL) (r - mid) * t[p].f;
        t[L].f += t[p].f , t[R].f += t[p].f;
        t[p].f = 0;
    }
    if (t[p].g) {
        t[L].g = t[R].g = t[p].g;
    }
    if (top <= mid) res += query(Left , top , bot);
    if (bot > mid) res += query(Right , top , bot);
    return res;
}

void work() {
    int i , x , y , w;
    scanf("%d%d",&n,&m);
    Build(1 , n);
    while (m --) {
        scanf("%d",&i);
        if (i == 1) {
            scanf("%d%d%d",&x,&y,&w);
            update(1 , n , x , y , w);
        } else {
            scanf("%d%d",&x,&y);
            printf("%I64d\n" , query(1 , n , x , y));
        }
    }
}

int main()
{
    work();
    return 0;
}