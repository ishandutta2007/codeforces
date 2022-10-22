#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , K , Q;
pair<int , int> a[N];
struct Query {
    int x1 , x2 , y1 , y2;
}q[N];
bool res[N];
void init() {
    scanf("%d%d%d%d",&n,&m,&K,&Q);
    for (int i = 0 ; i < K ; ++ i)
        scanf("%d%d" , &a[i].first , &a[i].second);
    for (int i = 0 ; i < Q ; ++ i)
        scanf("%d%d%d%d",&q[i].x1 , &q[i].y1 , &q[i].x2 , &q[i].y2);
}

inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
int t[N << 1];
void update(int l , int r , int x , int w) {
    int p = id(l , r);
    if (l == r) {
        t[p] = w;
        return;
    } MID;
    if (x <= mid)
        update(Left , x , w);
    else
        update(Right , x , w);
    t[p] = min(t[id(Left)] , t[id(Right)]);
}
int query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID; int res = 1 << 30;
    if (top <= mid) res = min(res , query(Left , top , bot));
    if (bot > mid) res = min(res , query(Right , top , bot));
    return res;
}



pair<int , int> w[N];
void work() {
    int i , j , k , x , y;
    sort(a , a + K);
    for (i = 0 ; i < Q ; ++ i)
        w[i] = make_pair(q[i].x2 , i);
    sort(w , w + Q);
    memset(t , 0 , sizeof(t));
    for (i = 0 , j = 0; i < Q ; ++ i) {
        while (j < K && a[j].first <= w[i].first) {
            update(1 , m , a[j].second , a[j].first);
            ++ j;
        }
        k = w[i].second;
        if (query(1 , m , q[k].y1 , q[k].y2) >= q[k].x1)
            res[k] |= 1;            
    }    
}

int main () {
    init();
    work();
    swap(n , m);
    for (int i = 0 ; i < K ; ++ i)
        swap(a[i].first , a[i].second);
    for (int i = 0 ; i < Q ; ++ i) {
        swap(q[i].x1 , q[i].y1);
        swap(q[i].x2 , q[i].y2);
    }
    work();
    for (int i = 0 ; i < Q ; ++ i)
        puts(res[i] ? "YES" : "NO");
    return 0;
}