#include <cstdio>
#include <iostream>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 3e5 + 1;

int n, q, k, l, a[N];
int all[N << 2];

int P, K;
int find(int i, int l, int r){
    if(l == r)
        return all[i] == K ? l : -1;
    if(all[i] != -1)
        all[le] = all[ri] = all[i];
    int mid = (l + r) >> 1;
    if(l >= P){
        if(all[i] == (K ^ 1))
            return -1;
        if(all[le] != (K ^ 1))
            return find(le, l, mid);
        return find(ri, mid + 1, r);
    }
    if(mid >= P){
        int res = find(le, l, mid);
        if(res != -1)
            return res;
    }
    return find(ri, mid + 1, r);
}

int query(int i, int l, int r){
    if(l == r)
        return l;
    if(all[i] != -1)
        all[le] = all[ri] = all[i];
    int mid = (l + r) >> 1;
    if(all[ri] == 0)
        return query(le, l, mid);
    else
        return query(ri, mid + 1, r);
}

int L, R;
void mod(int i, int l, int r){
    if(l >= L && r <= R){
        all[i] = K;
        return;
    }
    if(all[i] != -1)
        all[le] = all[ri] = all[i];
    int mid = (l + r) >> 1;
    if(mid >= L)
        mod(le, l, mid);
    if(mid < R)
        mod(ri, mid + 1, r);
    if(all[le] == all[ri])
        all[i] = all[le];
    else
        all[i] = -1;
}

void add(int p){
    P = p;
    K = 0;
    R = find(1, 1, N - 1) - 1;
    L = p;
    if(L <= R)
        mod(1, 1, N - 1);
    K = 1;
    L = R = R + 1;
    mod(1, 1, N - 1);
}

void del(int p){
    P = p;
    K = 1;
    R = find(1, 1, N - 1) - 1;
    L = p;
    if(L <= R)
        mod(1, 1, N - 1);
    K = 0;
    L = R = R + 1;
    mod(1, 1, N - 1);
}

int main(){
	scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        add(a[i]);
    }
    while(q--){
        scanf("%d%d", &k, &l);
        del(a[k]);
        a[k] = l;
        add(l);
        printf("%d\n", query(1, 1, N - 1));
    }
    return 0;
}