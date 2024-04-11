#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
           + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}
vector<int> vec[1000000];
Vertex *root[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    scanf("%d%d",&n,&k);
    root[0]=build(1,n);
    for (int i=1;i<=n;i++) {
        root[i] = root[i-1];
        int x;
        scanf("%d",&x);
        vec[x].push_back(i);
        root[i] = update(root[i],1,n,i,1);
        if (vec[x].size()>k)
            root[i] = update(root[i],1,n,vec[x][vec[x].size()-k - 1],0);
    }
    int q;
    int last=0;
    scanf("%d",&q);
    while(q--) {
        int l,r;
        scanf("%d%d",&l,&r);
        l = (l+last)%n + 1;
        r = (r+last)%n + 1;
        if (l>r)swap(l,r);
        last = get_sum(root[r],1,n,l,r);
        printf("%d\n",last);
    }
}