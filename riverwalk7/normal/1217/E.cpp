#include <iostream>
#include <fstream>
#define MAXN 200200
#define MAXD 10
#define INF 1e9+7
#define lc 2*node
#define rc 2*node+1
#define mid (l+r)/2
using namespace std;
int tree[3*MAXN][MAXD][2];
int a[MAXN]; int cur; pair<int, int> ans; int ans2;
int N, M, c, x, y;
void buildtree(int node, int l, int r)
{
    if(l == r)
    {
        cur = a[l];
        for(int i=0; i<MAXD; i++)
        {
            tree[node][i][1] = tree[node][i][0] = INF;
            if(cur % 10)
            {
                tree[node][i][0] = a[l];
            }
            cur /= 10;
        }
    }
    else
    {
        buildtree(lc, l, mid); buildtree(rc, mid+1, r);
        for(int i=0; i<MAXD; i++)
        {
            tree[node][i][0] = min(tree[lc][i][0], tree[rc][i][0]);
            tree[node][i][1] = min(tree[lc][i][1], tree[rc][i][1]);
            if(tree[lc][i][0] < tree[node][i][1] && tree[rc][i][0] < tree[node][i][1])
            {
                tree[node][i][1] = max(tree[lc][i][0], tree[rc][i][0]);
            }
        }
    }
}
void update(int node, int l, int r, int qx, int qy)
{
    if(l > qx || r < qx)
    {
        return;
    }
    else if(l == r)
    {
        cur = a[qx];
        for(int i=0; i<MAXD; i++)
        {
            tree[node][i][1] = tree[node][i][0] = INF;
            if(cur % 10)
            {
                tree[node][i][0] = a[l];
            }
            cur /= 10;
        }
    }
    else
    {
        update(lc, l, mid, qx, qy); update(rc, mid+1, r, qx, qy);
        for(int i=0; i<MAXD; i++)
        {
            tree[node][i][0] = min(tree[lc][i][0], tree[rc][i][0]);
            tree[node][i][1] = min(tree[lc][i][1], tree[rc][i][1]);
            if(tree[lc][i][0] < tree[node][i][1] && tree[rc][i][0] < tree[node][i][1])
            {
                tree[node][i][1] = max(tree[lc][i][0], tree[rc][i][0]);
            }
        }
    }
}
pair<int, int> query(int node, int l, int r, int ql, int qr, int q)
{
    if(l > qr || r < ql)
    {
        return make_pair(INF, INF);
    }
    else if(ql <= l && r <= qr)
    {
        return make_pair(tree[node][q][0], tree[node][q][1]);
    }
    else
    {
        pair<int, int> cur1 = query(lc, l, mid, ql, qr, q);
        pair<int, int> cur2 = query(rc, mid+1, r, ql, qr, q);
        pair<int, int> cur3;
        cur3.first = min(cur1.first, cur2.first);
        cur3.second = min(cur1.second, cur2.second);
        if(cur1.first < cur3.second && cur2.first < cur3.second)
        {
            cur3.second = max(cur1.first, cur2.first);
        }
        return cur3;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
    }
    buildtree(1, 1, N);
    for(int i=0; i<M; i++)
    {
        cin>>c>>x>>y;
        ans2 = 2*INF;
        if(c == 1)
        {
            a[x] = y;
            update(1, 1, N, x, y);
        }
        else
        {
            for(int i=0; i<MAXD; i++)
            {
                ans = query(1, 1, N, x, y, i);
                if(ans.first != INF && ans.second != INF)
                {
                    ans2 = min(ans2, ans.first+ans.second);
                }
            }
            if(ans2 == 2*INF)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<ans2<<endl;
            }
        }
    }
}