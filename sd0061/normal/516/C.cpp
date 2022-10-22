#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int n , m;
int h[N] , d[N];
LL a[N] , b[N];

inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

struct stree {
    stree () {
        mx = mn = w = 0;
    }
    LL mx , mn , w;
}t[N << 1];

stree operator + (const stree& A , const stree& B) {
    stree res;
    res.mx = max(A.mx , B.mx);
    res.mn = min(A.mn , B.mn);
    res.w = max(max(A.w , B.w) , B.mx - A.mn);
    return res;
}
void Build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        t[p].mx = a[l];
        t[p].mn = b[l];
        t[p].w = 0;
    } else {
        MID;
        Build(Left) , Build(Right);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}
stree get(int l , int r , int top , int bot) {
    if (top > bot) return stree(); 
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID;
    if (bot <= mid)
        return get(Left , top , bot);
    if (top > mid)
        return get(Right , top , bot);
    return get(Left , top , bot) + get(Right , top , bot);
}

void work() {
    int i , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &d[i]);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &h[i]);
    LL sum = 0;
    for (i = 1 ; i <= n + n ; ++ i) {
        a[i] = sum + h[(i - 1) % n + 1] + h[(i - 1) % n + 1];
        b[i] = sum - h[(i - 1) % n + 1] - h[(i - 1) % n + 1];
        sum += d[(i - 1) % n + 1];
    }
    Build(1 , n + n);
    while (m --) {
        scanf("%d%d",&x,&y);
        LL res = 0;
        if (x <= y) {
            //cout << 1 << ' ' << x - 1 << endl;
            res = max(res , get(1 , n + n , 1 , x - 1).w);
            res = max(res , get(1 , n + n , y + 1 , x + n - 1).w);
            res = max(res , get(1 , n + n , y + n + 1 , n + n).w);     
        } else {
            res = max(res , get(1 , n + n , y + 1 , x - 1).w);
            res = max(res , get(1 , n + n , y + n + 1 , x + n - 1).w);       
        }
        printf("%I64d\n" , res);
    }
}

int main() {
    work();
    return 0;
}