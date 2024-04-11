#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 270100
#define MAXK 21
#define INF 1000000007
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
using namespace std;
int N, R, M, x, y, c, p, q, k, ans;
int a[MAXN];
vector<int> conn[MAXN];
vector<int> level2[MAXN];
int parent[MAXK][MAXN];
int rect[MAXK][MAXN];
int level[MAXN], id[MAXN], lvlcounter[MAXN];
vector<int> tree[MAXK][MAXN];
int v[MAXN], u[MAXN]; //left and right range of the rectangle corresponding to the node
void dfs(int node, int par, int lvl)
{
    parent[0][node] = par; level[node] = lvl; rect[0][node] = a[node];
    lvlcounter[lvl]++;
    level2[lvl].push_back(node);
    id[node] = lvlcounter[level[node]];
    if((par==0&&conn[node].size()==0)||(par!=0&&conn[node].size()==1))
    {
        ++c;
        v[node] = u[node] = c;
    }
    for(int i=0; i<conn[node].size(); i++)
    {
        if(conn[node][i]!=par)
        {
            dfs(conn[node][i], node, lvl+1);
            v[node] = min(v[node], v[conn[node][i]]);
            u[node] = max(u[node], u[conn[node][i]]);
        }
    }
}
void update(int cx, int cy, int node, int l, int r, int q)
{
    if(l==id[q]&&r==id[q])
    {
        tree[cx][cy][node] = min(tree[cx][cy][node], rect[cx][q]);
        return;
    }
    else if(l>id[q]||r<id[q])
    {
        return;
    }
    else
    {
        update(cx, cy, lc, l, mid, q);
        update(cx, cy, rc, mid+1, r, q);
        tree[cx][cy][node] = min(tree[cx][cy][lc], tree[cx][cy][rc]);
    }
}
int query(int cx, int cy, int node, int l, int r, int ql, int qr)
{
    if(l>qr||r<ql)
    {
        return INF;
    }
    else if(ql<=l&&r<=qr)
    {
        return tree[cx][cy][node];
    }
    else
    {
        return min(query(cx, cy, lc, l, mid, ql, qr), query(cx, cy, rc, mid+1, r, ql, qr));
    }
}
int solve(int s, int t)
{
    for(int i=0; i<MAXK; i++)
    {
        if(((1<<i+1)) >= t)
        {
            int c = rect[i][s];
            int g = level[s]+t-(1<<i); int e = lvlcounter[g]+1; int f = 0;
            int lbound = 1; int hbound = lvlcounter[g]; int avg;
            if(lvlcounter[g] > 0)
            {
                do
                {
                    avg = (lbound + hbound)/2;
                    if(v[level2[g][avg-1]] >= v[s])
                    {
                        e = hbound = avg;
                    }
                    else
                    {
                        lbound = avg + 1;
                    }
                } while(lbound < hbound);
                while(e>1&&v[level2[g][e-2]] >= v[s])
                {
                    --e;
                }
                lbound = 1; hbound = lvlcounter[g];
                do
                {
                    avg = (lbound + hbound)/2;
                    if(u[level2[g][avg-1]] > u[s])
                    {
                        hbound = avg;
                    }
                    else
                    {
                        f = avg;
                        lbound = avg + 1;
                    }
                } while(lbound < hbound);
                while(f<level2[g].size()&&u[level2[g][f]]<= u[s])
                {
                    ++f;
                }
                c = min(c, query(i, g, 1, 1, lvlcounter[g], e, f));
            }
            return c;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>R;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        v[i] = INF;
    }
    for(int i=0; i<N-1; i++)
    {
        cin>>x>>y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    dfs(R, 0, 1);
    for(int i=1; i<MAXK; i++)
    {
        for(int j=1; j<=N; j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
            rect[i][j] = INF;
        }
    }
    for(int i=1; i<MAXK; i++)
    {
        for(int j=1; j<=N; j++)
        {
            rect[i][j] = min(rect[i][j], rect[i-1][j]);
            rect[i][parent[i-1][j]] = min(rect[i][parent[i-1][j]], rect[i-1][j]);
        }
    }
    for(int i=0; i<MAXK; i++)
    {
        for(int j=1; j<=N; j++)
        {
            for(int k=0; k<4; k++)
            {
                tree[i][level[j]].push_back(INF);
            }
        }
    }
    for(int i=0; i<MAXK; i++)
    {
        for(int j=1; j<=N; j++)
        {
            update(i, level[j], 1, 1, lvlcounter[level[j]], j);
        }
    }
    cin>>M;
    for(int i=0; i<M; i++)
    {
        cin>>p>>q;
        x = (p+ans)%N+1;
        k = (q+ans)%N;
        ans = solve(x, k+1);
        cout<<ans<<'\n';
    }
}