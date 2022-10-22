#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
#define N 100010
int n , a[N] , Q;
struct range
{
    int w , l , r;
    range() {}
    range(int _w , int _l , int _r) {w = _w , l = _l , r = _r;}
    range operator + (const range& A) const{
        return range(w + A.w , l , A.r);
    }
    bool operator < (const range& A) const{
        return w < A.w;
    }
};

struct stree
{
    range sum;
    bool flag;
    range lx , rx , mx;
    range ln , rn , mn;
    void init(int x)
    {
        flag = 0;
        sum = lx = rx = mx = ln = rn = mn = range(a[x] , x , x);
    }
    void change()
    {
        sum.w = -sum.w , flag ^= 1;
        swap(lx , ln) , lx.w = -lx.w , ln.w = -ln.w;
        swap(rx , rn) , rx.w = -rx.w , rn.w = -rn.w;
        swap(mx , mn) , mx.w = -mx.w , mn.w = -mn.w;
    }
}t[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = (l + r) >> 1
#define Left l , mid
#define Right mid + 1 , r

void pushup(int p , int LL , int RR)
{
    t[p].sum = t[LL].sum + t[RR].sum;
    t[p].lx = max(t[LL].lx , t[LL].sum + t[RR].lx );
    t[p].rx = max(t[RR].rx , t[LL].rx + t[RR].sum );
    t[p].mx = max(t[LL].rx + t[RR].lx , max(t[LL].mx , t[RR].mx));
    t[p].ln = min(t[LL].ln , t[LL].sum + t[RR].ln );
    t[p].rn = min(t[RR].rn , t[LL].rn + t[RR].sum );
    t[p].mn = min(t[LL].rn + t[RR].ln , min(t[LL].mn , t[RR].mn));
}
stree operator + (stree A , stree B)
{
    stree ans;
    ans.sum = A.sum + B.sum;
    ans.lx = max(A.lx , A.sum + B.lx );
    ans.rx = max(B.rx , A.rx + B.sum );
    ans.mx = max(A.rx + B.lx , max(A.mx , B.mx));
    ans.ln = min(A.ln , A.sum + B.ln );
    ans.rn = min(B.rn , A.rn + B.sum );
    ans.mn = min(A.rn + B.ln , min(A.mn , B.mn));
    return ans;
}
void pushdown(int p , int LL , int RR)
{
    if (t[p].flag)
    {
        t[p].flag = 0;
        t[LL].change() , t[RR].change();
    }
}
void Build(int l , int r)
{
    int p = id(l , r);
    if (l == r)
        t[p].init(l);
    else
    {
        MID ; Build(Left) , Build(Right);
        pushup(p , id(Left) , id(Right));
    }
}
void update(int l , int r , int x)
{
    int p = id(l , r);
    if (l == r)
        t[p].init(l);
    else
    {
        MID; pushdown(p , id(Left) , id(Right));
        if (x <= mid)
            update(Left , x);
        else
            update(Right , x);
        pushup(p , id(Left) , id(Right));
    }
}
void reverse(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        t[p].change();
    else
    {
        MID; pushdown(p , id(Left) , id(Right));
        if (top <= mid)
            reverse(Left , top , bot);
        if (bot > mid)
            reverse(Right , top , bot);
        pushup(p , id(Left) , id(Right));
    }
}
stree maxsubq(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    else
    {
        MID; pushdown(p , id(Left) , id(Right));
        if (bot <= mid)
            return maxsubq(Left , top , bot);
        else if (top > mid)
            return maxsubq(Right , top , bot);
        else
            return maxsubq(Left , top , bot) + maxsubq(Right , top , bot);
    }
}

int main()
{
    int i , j , x , l , r;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    Build(1 , n);
    scanf("%d",&Q);
    stack< pair<int , int > > S;
    while (Q --)
    {
        scanf("%d%d%d",&x,&l,&r);
        if (!x)
        {
            a[l] = r;
            update(1 , n , l);
        }
        else
        {
            scanf("%d",&j);
            int ans = 0 , sum = 0;
            while (j --)
            {
                range opt = maxsubq(1 , n , l , r).mx;
                if (opt.w <= 0) break;
                sum += opt.w , ans = max(ans , sum);
                reverse(1 , n , opt.l , opt.r);
                S.push(make_pair(opt.l , opt.r));
            }
            while (!S.empty())
                reverse(1 , n , S.top().first , S.top().second) , S.pop();
            printf("%d\n" , ans);
        }
    }
    return 0;
}