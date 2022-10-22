#include<bits/stdc++.h>
using namespace std;
const int maxn = 300010;
const int INF = 1e9;
int n, q, a[maxn];
pair<int,int> val[maxn * 4];
int flag[maxn * 4];
void build(int x, int l, int r){
    if (l == r){
        if (a[l] <= l) val[x] = make_pair(l - a[l], l); else val[x] = make_pair(INF, l);
    }else{
        int mid = l + r >> 1;
        build(x<<1, l, mid);
        build(x<<1|1, mid+1, r);
        val[x] = min(val[x<<1], val[x<<1|1]);
    }
}
pair<int,int> mn;
void ffind(int x, int l, int r){
    if (l == r) mn = val[x];
    else{
        int mid = l + r >> 1;
        if (flag[x]){
            flag[x<<1] += flag[x];
            val[x<<1].first += flag[x];
            flag[x<<1|1] += flag[x];
            val[x<<1|1].first += flag[x];
            flag[x] = 0;
        }
        if (val[x<<1].first <= 0) ffind(x<<1, l, mid);
        else ffind(x<<1|1, mid+1, r);
    }
}
void find(int x, int l, int r, int pl, int pr){
    if (mn.first <= 0) return;
    if (pl <= l && pr >= r){
        if (val[x].first <= 0) ffind(x, l, r);
        return;
    }
    if (flag[x]){
        flag[x<<1] += flag[x];
        val[x<<1].first += flag[x];
        flag[x<<1|1] += flag[x];
        val[x<<1|1].first += flag[x];
        flag[x] = 0;
    }
    int mid = l + r >> 1;
    if (pl <= mid) find(x<<1, l, mid, pl, pr);
    if (pr > mid) find(x<<1|1, mid+1, r, pl, pr);
}
void change(int x, int l, int r, int p){
    if (l == r){
        val[x] = make_pair(INF, l);
    }else{
        if (flag[x]){
            flag[x<<1] += flag[x];
            val[x<<1].first += flag[x];
            flag[x<<1|1] += flag[x];
            val[x<<1|1].first += flag[x];
            flag[x] = 0;
        }
        int mid = l + r >> 1;
        if (p <= mid) change(x << 1, l , mid, p);
        else change(x<<1|1, mid+1, r, p);
        val[x] = min(val[x<<1], val[x<<1|1]);
    }
}
void change(int x, int l, int r, int pl, int pr){
    if (pl <= l && pr >= r){
        flag[x]--; val[x].first --;
    }else{
        if (flag[x]){
            flag[x<<1] += flag[x];
            val[x<<1].first += flag[x];
            flag[x<<1|1] += flag[x];
            val[x<<1|1].first += flag[x];
            flag[x] = 0;
        }
        int mid = l + r>>1;
        if (pl <= mid) change(x<<1, l, mid, pl, pr);
        if (pr > mid) change(x<<1|1, mid+1, r, pl, pr);
        val[x] = min(val[x<<1], val[x<<1|1]);
    }
}
int st[maxn], ans[maxn];
vector<pair<int,int> >query[maxn];
void add(int x){
    for (int i = x; i <= n; i += i&(-i)) st[i] ++;
}
int get(int x){
    int cnt = 0;
    for (int i = x; i >= 1; i -= i&(-i)) cnt += st[i];
    return cnt;
}
int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= q; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        query[x + 1].push_back(make_pair(n - y, i));
    }
    build(1, 1, n);
    for (int i = n; i >= 1; i--){
        int p = i;
        while (p <= n){
            mn.first = INF;
            find(1, 1, n, p, n);
            //printf("%d %d %d\n", i, mn.first, mn.second);
            if (mn.first <= 0){
                add(mn.second);
                change(1, 1, n, mn.second);
                change(1, 1, n, mn.second, n);
                p = mn.second + 1;
                
            }else break;
        }
        for (auto q: query[i]) ans[q.second] = get(q.first);
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0; 
}