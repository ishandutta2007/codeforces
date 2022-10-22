#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 2000005;

int n , m;
pair<int , int> a[N];

struct stree {
    stree () {
        len = 0;
    }
    int l , r , len;
    int L , R , S;
}t[M];
int root[N];
int cnt;

void pushup(stree& A , const stree& B , const stree& C) {
    if (B.len && B.L == B.len)
        A.L = B.len + C.L;
    else
        A.L = B.L;
    if (C.len && C.R == C.len)
        A.R = C.len + B.R;
    else
        A.R = C.R;
    A.S = max(max(B.S , C.S) , B.R + C.L);
    if (!A.len) A.len = B.len + C.len;
}

void update(int& p , int q , int l , int r , int x) {
    if (!p) {
        p = ++ cnt;
        t[p].len = r - l + 1;
    }
    if (l == r) {
        t[p].L = t[p].R = t[p].S = 1;
    } else {
        int mid = l + r >> 1;
        if (x <= mid) {
            t[p].r = t[q].r;
            update(t[p].l , t[q].l , l , mid , x);
        } else {
            t[p].l = t[q].l;
            update(t[p].r , t[q].r , mid + 1 , r , x);
        }
        pushup(t[p] , t[t[p].l] , t[t[p].r]);
    }
}

stree get(int p , int l , int r , int top , int bot) {
    if (!p) return t[0];
    if (top <= l && r <= bot)
        return t[p];
    int mid = l + r >> 1;
    if (bot <= mid)
        return get(t[p].l , l , mid , top , bot);
    if (top > mid)
        return get(t[p].r , mid + 1 , r , top , bot);
    stree QAQ; pushup(QAQ , get(t[p].l , l , mid , top , bot) , get(t[p].r , mid + 1 , r , top , bot));
    return QAQ;
}

int main() {
    int i , x , y , w;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    sort(a + 1 , a + n + 1);

    for (i = n ; i > 0 ; -- i) {
        update(root[i] , root[i + 1] , 1 , n , a[i].second);
        //printf("%d : %d\n" , i , a[i].second);
    }
    scanf("%d",&m);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&w);
        int l = 1 , r = n , mid;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (get(root[mid] , 1 , n , x , y).S >= w)
                l = mid;
            else
                r = mid - 1;
        }
        printf("%d\n" , a[l].first);
    }
    return 0;
}