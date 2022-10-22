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
const int N = 500005;
int n , a[N] , d[N] , D;
int L[N] , pre[N];

int f[N] , g[N] , w[N];
bool r[N];
pair<int , int> t[N << 1];
inline int id (int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

void update(int l , int r , int x , pair<int , int> w) {
    int p = id(l , r);
    if (l == r)
        t[p] = w;
    else {
        MID;
        if (x <= mid)
            update(Left , x , w);
        else
            update(Right , x , w);
        t[p] = max(t[id(Left)] , t[id(Right)]);
    }
}
pair<int , int> get(int l , int r , int top , int bot) {
    if (top > bot) return make_pair(-1 << 30 , -1);
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID; pair<int , int> res = make_pair(-1 << 30 , -1);
    if (top <= mid) res = max(res , get(Left , top , bot));
    if (bot > mid) res = max(res , get(Right , top , bot));
    return res;
}
pair<int , int> b[N];
pair<int , int> q[N];

void print(int i) {
    if (i <= 0)
        return;
    if (pre[i] + 1 == i)
        print(i - 1);
    else if (!r[i]){
        print(pre[i]);
        int y = a[i] , x = a[w[i]];
        printf("%d %d %d %d " , d[x - 1] , d[y - 1] , d[x - 1] , d[y - 1]);
    } else {
        assert(r[i]);
        print(pre[i]);
        int x = d[a[i] - 1];
        printf("%d %d %d %d " , x , x , x , x);
    }
}

void work() {
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
        d[D ++] = a[i];
    }
    sort(d , d + D);
    D = unique(d , d + D) - d;
    for (i = 1 ; i <= n ; ++ i) {
        a[i] = lower_bound(d , d + D , a[i]) - d + 1;
        L[i] = pre[a[i]] , pre[a[i]] = i;
        b[i] = make_pair(L[i] , i);
    }
    sort(b + 1 , b + n + 1);
    for (i = 1 ; i <= n ; ++ i) {
        update(1 , n , i , make_pair(-1 << 30 , -1));
    }
    j = 1;
    for (i = 1 ; i <= n ; ++ i) {
        while (j <= n && b[j].first < b[i].first) {
            update(1 , n , b[j].second , make_pair(b[j].first , b[j].second));
            ++ j;
        }
        pair<int , int> Tmp = get(1 , n , b[i].first + 1 , b[i].second - 1);
        g[b[i].second] = Tmp.first;
        w[b[i].second] = Tmp.second;
    }
    pair<int , int> ans(0 , 0);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= n ; ++ i) {
        f[i] = f[i - 1] , pre[i] = i - 1;
        if (g[i] > 0 && f[g[i] - 1] + 1 > f[i]) {
            f[i] = f[g[i] - 1] + 1;
            pre[i] = g[i] - 1;
        }
        int x = i;
        x = L[x];
        x = L[x];
        x = L[x];
        if (x && f[x - 1] + 1 > f[i]) {
            pre[i] = x - 1;
            r[i] = 1;
            f[i] = f[x - 1] + 1;
        }
        ans = max(ans , make_pair(f[i] , i));
    }
    cout << ans.first * 4 << endl;
    if (ans.first)
        print(ans.second);
}

int main() {
    work();
    return 0;
}