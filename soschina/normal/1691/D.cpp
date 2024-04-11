#include <cstdio>
#include <iostream>
#include <utility>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 2e5 + 1;
typedef pair<int, int> dint;
typedef pair<long long, long long> dll;

int t, n, a[N], L, R, P;

struct maxTree{
    dint tree[N << 2];
    void build(int i, int l, int r){
        if(l == r){
            tree[i] = dint(a[l], l);
            return;
        }
        int mid = (l + r) >> 1;
        build(le, l, mid);
        build(ri, mid + 1, r);
        tree[i] = max(tree[le], tree[ri]);
    }
    dint query(int i, int l, int r){
        if(l >= L && r <= R)
            return tree[i];
        int mid = (l + r) >> 1;
        dint ret(0x80000000, 0);
        if(mid >= L)
            ret = query(le, l, mid);
        if(mid < R)
            ret = max(ret, query(ri, mid + 1, r));
        return ret;
    }
}maxtree;

long long sum[N << 2], letree[N << 2], ritree[N << 2];
void build(int i, int l, int r){
    if(l == r){
        sum[i] = a[l];
        letree[i] = max(a[l], 0);
        ritree[i] = max(a[l], 0);
        return;
    }
    int mid = (l + r) >> 1;
    build(le, l, mid);
    build(ri, mid + 1, r);
    sum[i] = sum[le] + sum[ri];
    letree[i] = max(letree[ri], sum[ri] + letree[le]);
    ritree[i] = max(ritree[le], sum[le] + ritree[ri]);
}

dll queryle(int i, int l, int r){
    if(l >= L && r <= R)
        return dll(sum[i], letree[i]);
    int mid = (l + r) >> 1;
    if(mid < L)
        return queryle(ri, mid + 1, r);
    if(mid >= R)
        return queryle(le, l, mid);
    dll ll = queryle(le, l, mid);
    dll rr = queryle(ri, mid + 1, r);
    return dll(ll.first + rr.first, max(rr.second, rr.first + ll.second));
}

dll queryri(int i, int l, int r){
    if(l >= L && r <= R)
        return dll(sum[i], ritree[i]);
    int mid = (l + r) >> 1;
    if(mid < L)
        return queryri(ri, mid + 1, r);
    if(mid >= R)
        return queryri(le, l, mid);
    dll ll = queryri(le, l, mid);
    dll rr = queryri(ri, mid + 1, r);
    return dll(ll.first + rr.first, max(ll.second, ll.first + rr.second));
}

bool flag;

void solve(int l, int r){
    if(l >= r)
        return;
    L = l, R = r;
    int maxpos = maxtree.query(1, 1, n).second;
    L = l, R = maxpos - 1;
    long long now = 0;
    if(L <= R)
        now += queryle(1, 1, n).second;
    L = maxpos + 1, R = r;
    if(L <= R)
        now += queryri(1, 1, n).second;
    if(now > 0){
        flag = false;
        return;
    }
    solve(l, maxpos - 1);
    solve(maxpos + 1, r);
}

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        maxtree.build(1, 1, n);
        build(1, 1, n);
        flag = true;
        solve(1, n);
        puts(flag ? "YES" : "NO");
    }
	return 0;
}