#include <iostream>
#include <vector>
#define MAXN 100100
#define INF 1e9+7
using namespace std;
struct node
{
    int val, lazy, child;
    node()
    {
        val = child = 0;
        lazy = INF;
    }
    node(int vval, int llazy, int cchild)
    {
        val = vval;
        lazy = llazy;
        child = cchild;
    }
};
int N, K, Q;
int w, x, y, z;
int arr[MAXN];
int stree[4*MAXN];
vector<node> tree;
int counter, c1, c2;
int squery(int n, int l, int r, int ql, int qr)
{
    if(l>qr||r<ql)
    {
        return INF;
    }
    else if(ql<=l&&r<=qr)
    {
        return stree[n];
    }
    else
    {
        return min(squery(2*n, l, (l+r)/2, ql, qr), squery(2*n+1, (l+r)/2+1, r, ql, qr));
    }
}
void propogate(int n)
{
    tree[tree[n].child].val = tree[n].lazy;
    tree[tree[n].child+1].val = tree[n].lazy;
    tree[tree[n].child].lazy = tree[n].lazy;
    tree[tree[n].child+1].lazy = tree[n].lazy;
    tree[n].lazy = INF;
}
void update(int n, int l, int r, int ql, int qr, int q)
{
    if(tree[n].child == 0)
    {
        tree[n].child = counter;
        counter += 2;
        tree.push_back(node());
        tree.push_back(node());
    }
    if(tree[n].lazy != INF&&l!=r)
    {
        propogate(n);
    }
    if(l>qr||r<ql)
    {
        if(tree[n].val == 0)
        {
            if((r-l+1)>=N)
            {
                tree[n].val = squery(1, 1, N, 1, N);
            }
            else
            {
                c1 = l%N;
                c2 = r%N;
                if(c1==0)
                {
                    c1 = N;
                }
                if(c2==0)
                {
                    c2 = N;
                }
                if(c1<=c2)
                {
                    tree[n].val = squery(1, 1, N, c1, c2);
                }
                else
                {
                    tree[n].val = min(squery(1, 1, N, c1, N), squery(1, 1, N, 1, c2));
                }
            }
        }
        return;
    }
    else if(ql<=l&&r<=qr)
    {
        tree[n].val = tree[n].lazy = q;
        return;
    }
    else
    {
        update(tree[n].child, l, (l+r)/2, ql, qr, q);
        update(tree[n].child+1, (l+r)/2+1, r, ql, qr, q);
        tree[n].val = min(tree[tree[n].child].val, tree[tree[n].child+1].val);
    }
}
int query(int n, int l, int r, int ql, int qr)
{
    if(tree[n].child == 0)
    {
        tree[n].child = counter;
        counter += 2;
        tree.push_back(node());
        tree.push_back(node());
    }
    if(tree[n].val == 0)
    {
        if((r-l+1)>=N)
        {
            tree[n].val = squery(1, 1, N, 1, N);
        }
        else
        {
            c1 = l%N;
            c2 = r%N;
            if(c1==0)
            {
                c1 = N;
            }
            if(c2==0)
            {
                c2 = N;
            }
            if(c1<=c2)
            {
                tree[n].val = squery(1, 1, N, c1, c2);
            }
            else
            {
                tree[n].val = min(squery(1, 1, N, c1, N), squery(1, 1, N, 1, c2));
            }
        }
    }
    if(tree[n].lazy != INF&&l!=r)
    {
        propogate(n);
    }
    if(l>qr||r<ql)
    {
        return INF;
    }
    else if(ql<=l&&r<=qr)
    {
        return tree[n].val;
    }
    else
    {
        return min(query(tree[n].child, l, (l+r)/2, ql, qr), query(tree[n].child+1, (l+r)/2+1, r, ql, qr));
    }
}
void buildtree(int n, int l, int r)
{
    if(l==r)
    {
        stree[n] = arr[l];
        return;
    }
    else
    {
        buildtree(2*n, l, (l+r)/2);
        buildtree(2*n+1, (l+r)/2+1, r);
        stree[n] = min(stree[2*n], stree[2*n+1]);
    }
}
int main()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        cin>>arr[i];
    }
    buildtree(1, 1, N);
    counter = 1;
    tree.push_back(node());
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>w;
        if(w==1)
        {
            cin>>x>>y>>z;
            update(0, 1, N*K, x, y, z);
        }
        else
        {
            cin>>x>>y;
            cout<<query(0, 1, N*K, x, y)<<endl;
        }
    }
}