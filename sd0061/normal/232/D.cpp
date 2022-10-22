#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 4000005;

int n , m , a[N] , d[N] , D;
int s[N] , len;

int sa[N] , t1[N] , t2[N] , c[N];
int Rank[N] , height[N];
int f[18][N] , LOG[N];
void buildsa(int n , int m)
{
    int i , k , *x = t1 , *y = t2;
    for (i = 0 ; i < m ; ++ i) c[i] = 0;
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 ; k <= n ; k <<= 1) {
        int p = 0;
        for (i = n - k ; i < n ; ++ i) y[p ++] = i;
        for (i = 0 ; i < n ; ++ i) if (sa[i] >= k) y[p ++] = sa[i] - k;
        for (i = 0 ; i < m ; ++ i) c[i] = 0;
        for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
        for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
        for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
        swap(x , y) , p = 1 , x[sa[0]] = 0;
        for (i = 1 ; i < n ; ++ i)
            x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) ? p -
                1 : p ++;
        if (p >= n) break;
        m = p;
    }
    k = 0;
    for (i = 0 ; i < n ; ++ i) Rank[sa[i]] = i;
    for (i = 0 ; i < n ; ++ i) {
        if (k) -- k; if (!Rank[i]) continue;
        int j = sa[Rank[i] - 1];
        while (s[i + k] == s[j + k]) ++ k;
        height[Rank[i]] = k;
    }
    for (i = 0 ; 1 << i <= n ; ++ i)
        LOG[1 << i] = i;
    for (i = 2 ; i <= n ; ++ i)
        if (!LOG[i])
            LOG[i] = LOG[i - 1];
    for (i = 0 ; i < n ; ++ i)
        f[0][i] = height[i];
    for (int j = 1 ; 1 << j <= n ; ++ j)
        for (i = 1 ; i + (1 << j) - 1 < n ; ++ i)
            f[j][i] = min(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
}
int RMQ(int x , int y) {
    int j = LOG[y - x + 1];
    return min(f[j][x] , f[j][y - (1 << j) + 1]);
}

#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
int root[N];
int ch[M][2] , cnt[M] , nodecnt;

void add(int& p , int q , int l , int r , int x) {
    if (!p) p = ++ nodecnt , cnt[p] = cnt[q]; ++ cnt[p];
    if (l == r) return; MID;
    if (x <= mid) ch[p][1] = ch[q][1] , add(ch[p][0] , ch[q][0] , Left , x);
    if (x > mid) ch[p][0] = ch[q][0] , add(ch[p][1] , ch[q][1] , Right , x);    
}
int res;
void query(int p , int l , int r , int top , int bot) {
    if (!p || top > bot) return;
    if (top <= l && r <= bot)
        res += cnt[p];
    else {
        MID;
        if (top <= mid) query(ch[p][0] , Left , top , bot);
        if (bot > mid) query(ch[p][1] , Right , top , bot);
    }
}

void work() {
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    for (i = 1 ; i < n ; ++ i) {
        d[D ++] = a[i] - a[i - 1];
        d[D ++] = a[i - 1] - a[i];
    }
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (i = 0 ; i + 1 < n ; ++ i)
        s[len ++] = lower_bound(d , d + D , a[i + 1] - a[i]) - d + 2;
    s[len ++] = 1;
    for (i = 0 ; i + 1 < n ; ++ i)
        s[len ++] = lower_bound(d , d + D , a[i] - a[i + 1]) - d + 2;
    s[len ++] = 0;
    buildsa(len , D + 5);
   
    for (i = 2 ; i < len ; ++ i)
        add(root[i] , root[i - 1] , 0 , len , sa[i]);
    
    scanf("%d" , &m);
    while (m --) {
        scanf("%d%d",&x,&y);
        -- x , -- y;
        if (x == y) {
            printf("%d\n" , n - 1);
            continue;
        }
        int match = y - x , pos = Rank[x + n];
        int L , R , l , r , mid;
        l = 0 , r = pos;
        while (l < r) {
            mid = l + r >> 1;
            if (RMQ(mid + 1 , pos) >= match)
                r = mid;
            else
                l = mid + 1;
        }
        L = l;
        l = pos , r = len - 1;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (RMQ(pos + 1 , mid) >= match)
                l = mid;
            else
                r = mid - 1;
        }
        R = l;
        res = 0;
        query(root[L - 1] , 0 , len , 0 , x - match - 1);
        query(root[L - 1] , 0 , len , y + 1 , n - match - 1);
        res = -res;
        query(root[R] , 0 , len , 0 , x - match - 1);
        query(root[R] , 0 , len , y + 1 , n - match - 1);
        printf("%d\n" , res);        
    }
}

int main() {
    work();
    return 0;
}