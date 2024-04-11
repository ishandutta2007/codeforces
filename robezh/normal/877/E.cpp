#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int N = 300000;

int n;
int dat[4 * N];
bool lazy[4 * N];
int onAndOff[2 * N];
vector<int> num;
vector<int> p[N];
int st[N], ft[N];

void dfs(int i) {
    num.push_back(i);
    st[i] = num.size() - 1;
    for(int k = 0; k < p[i].size(); k++) {
        dfs(p[i][k]);
    }
    num.push_back(i);
    ft[i] = num.size() - 1;
}

int build_sum(int x, int l, int r) {
    if(l == r)
        return dat[x] = onAndOff[r];

    int mid = (l + r) / 2;
    int sumleft = build_sum((x<<1) + 1, l, mid);
    int sumright = build_sum((x<<1) + 2, mid+1, r);

    dat[x] = sumleft + sumright;
    return dat[x];
}

void propagate(int x, int l, int r) {
	int mid = (l + r) / 2;
	
    lazy[x] = false;
    lazy[(x<<1) + 1] ^= 1;
    lazy[(x<<1) + 2] ^= 1;
    dat[(x<<1) + 1] = (mid - l + 1) - dat[(x<<1) + 1];
    dat[(x<<1) + 2] = (r - mid) - dat[(x<<1) + 2];
}

int query(int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    //propagating the lazy value to the children
    if(lazy[x] && l < r) {
        propagate(x, l, r);
    }

    if(l >= a && r <= b) {
        return dat[x];
    }

    int lquery = query(a, b,  (x<<1) + 1, l, mid);
    int rquery = query(a, b, (x<<1) + 2, mid+1, r);
    return lquery + rquery;
}

void update(int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;

    //propagating the lazy value to the children
    if(lazy[x] && l < r) {
        propagate(x, l, r);
    }

    if(l >= a && r <= b) {
        if(l != r) lazy[x] ^= 1;
        dat[x] = (r - l + 1) - dat[x];
        return ;
    }

    update(a, b, (x<<1) + 1, l, mid);
    update(a, b, (x<<1) + 2, mid+1, r);

    dat[x] = dat[(x<<1) + 1] + dat[(x<<1) + 2];
}

void upd(int k) {
    update(st[k], ft[k], 0, 0, n - 1);
}

int get(int k) {
    return query(st[k], ft[k], 0, 0, n - 1) / 2;
}

void printnum() {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", query(i, i, 0, 0, n - 1));
    }
    printf("\n");
}

int main() {
    int from;
    scanf("%d", &n);
    fill(lazy, lazy + 4 * n, false);

    //build the graph
    for(int i = 2; i <= n; i++) {
        scanf("%d", &from);
        p[from].push_back(i);
    }

    //using euler technique to get the flat interval
    // where we can used segment tree
    dfs(1);

    int onoff;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &onoff);
        onAndOff[st[i]] = onoff;
        onAndOff[ft[i]] = onoff;
    }

    n *= 2;
    //build the tree
    dat[0] = build_sum(0,0,n-1);

    int q;
    scanf("%d" , &q);
    string str;
    int i;
    while(q--) {
        cin>>str>>i;
        if(str == "get") printf("%d\n", get(i));
        else upd(i);
    }
    
    return 0;
}