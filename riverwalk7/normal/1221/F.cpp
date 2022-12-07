#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#define lc 2*node
#define rc 2*node+1
#define mid (l+r)/2
#define MAXN 500500
using namespace std;
typedef long long ll;
int x[MAXN], y[MAXN], c[MAXN];
ll tree[5*MAXN], lazy[5*MAXN];
int x2[2*MAXN];
map<int, int> x3;
int N;
int counter, cur4;
vector<int> u1[2*MAXN];
int u, v; ll ans; ll cur;
void buildtree(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = -x2[l];
    }
    else
    {
        buildtree(lc, l, mid); buildtree(rc, mid+1, r);
        tree[node] = max(tree[lc], tree[rc]);
    }
}
void propagate(int node)
{
    lazy[lc] += lazy[node]; lazy[rc] += lazy[node];
    tree[lc] += lazy[node]; tree[rc] += lazy[node];
    lazy[node] = 0; return;
}
void update(int node, int l, int r, int ql, int qr, ll q)
{
    if(l != r)
    {
        propagate(node);
    }
    if(l > qr || r < ql)
    {
        return;
    }
    else if(ql <= l && r <= qr)
    {
        tree[node] += q; lazy[node] += q; return;
    }
    else
    {
        update(lc, l, mid, ql, qr, q); update(rc, mid+1, r, ql, qr, q);
        tree[node] = max(tree[lc], tree[rc]);
    }
}
ll query(int node, int l, int r, int ql, int qr)
{
    if(l != r)
    {
        propagate(node);
    }
    if(l > qr || r < ql)
    {
        return -2e9;
    }
    else if(ql <= l && r <= qr)
    {
        return tree[node];
    }
    else
    {
        return max(query(lc, l, mid, ql, qr), query(rc, mid+1, r, ql, qr));
    }
}
int query2(int node, int l, int r, ll q)
{
    if(l == r)
    {
        return l;
    }
    else
    {
        propagate(node);
        if(tree[rc] == q || mid+1 <= cur4) return query2(rc, mid+1, r, q);
        else return query2(lc, l, mid, q);
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x[i]>>y[i]>>c[i];
        x3[x[i]] = 1; x3[y[i]] = 1;
    }
    for(map<int, int>::iterator it = x3.begin(); it != x3.end(); ++it)
    {
        ++counter;
        it -> second = counter;
        x2[counter] = it -> first;
    }
    buildtree(1, 1, counter);
    for(int i=0; i<N; i++)
    {
        u1[x3[min(x[i], y[i])]].push_back(i);
        update(1, 1, counter, x3[max(x[i], y[i])], counter, c[i]);
    }
    for(int i=1; i<=counter; i++)
    {
        cur = query(1, 1, counter, i, counter);
        if(cur + x2[i] > ans)
        {
            ans = cur+x2[i];
            cur4 = i;
            u = x2[i]; v = x2[query2(1, 1, counter, cur)];
        }
        for(int j=0; j<u1[i].size(); j++)
        {
            update(1, 1, counter, x3[max(x[u1[i][j]], y[u1[i][j]])], counter, -c[u1[i][j]]);
        }
    }
    if(ans == 0)
    {
        u = v = 2e9;
    }
    cout<<ans<<endl;
    cout<<u<<" "<<u<<" "<<v<<" "<<v<<endl;
}