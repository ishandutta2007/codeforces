#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr first
#define se second
#define oo 1000000000000000000000
using namespace std;

const int N = 1001010;
vector<int> adj[N];
queue<pair<int,pair<int,int> > > q;
int visited[N][2][4];
int a[1005][1005];
int t;

int h(int i, int j)
{
    return i + j*1000;
}

int xk(int h)
{
    if(h%1000 == 0)
        return 1000;
    else
        return h%1000;
}

int yk(int h)
{
    if(h%1000 == 0)
        return (h - 1000)/1000;
    else
        return (h - h%1000)/1000;

}

bool BFS(int s, int dir, int turns)
{
    q.push({s,{0,turns}});

    q.push({s,{1,turns}});

    visited[s][dir][turns] = 1;
    while(!q.empty())
    {
        s = q.front().first;
        dir = q.front().second.first;
        turns = q.front().second.second;
        q.pop();
        if (s==t)
            return 1;
        int xs = xk(s), ys = yk(s);
        for(auto nxt : adj[s])
        {
            int xnxt = xk(nxt);
            int ynxt = yk(nxt);

            if(dir)
            {
                if(ynxt != ys)
                {
                    if (turns+1<=2 && !visited[nxt][0][turns+1])
                    {
                        q.push({nxt,{0,turns+1}});
                        visited[nxt][0][turns+1]=1;
                    }
                }
                else
                {
                    if (turns<=2 && !visited[nxt][1][turns])
                    {
                        q.push({nxt,{1,turns}});
                        visited[nxt][1][turns]=1;
                    }
                }
            }
            else
            {
                if(xnxt != xs)
                {
                    if (turns+1<=2 && !visited[nxt][1][turns+1])
                    {
                        q.push({nxt,{1,turns+1}});
                        visited[nxt][1][turns+1]=1;
                    }
                }
                else
                {
                    if (turns<=2 && !visited[nxt][0][turns])
                    {
                        q.push({nxt,{0,turns}});
                        visited[nxt][0][turns]=1;
                    }
                }
            }
        }
    }
    return 0;

}

int main()
{
    int n, m, s;
    cin>>n>>m;

    char c;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>c;
            if(c == '*')
                a[i][j] = 0;
            else
                a[i][j] = 1;

            if(c == 'S')
                s = i + j*1000;
            else if(c == 'T')
                t = i + j*1000;
        }

    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j])
            {
                int cur = h(i, j), nxt;
                if(a[i-1][j])
                {
                    nxt = h(i-1, j);
                    adj[cur].pb(nxt);
                }
                if(a[i+1][j])
                {
                    nxt = h(i+1, j);
                    adj[cur].pb(nxt);

                }
                if(a[i][j-1])
                {
                    nxt = h(i, j-1);
                    adj[cur].pb(nxt);
                }
                if(a[i][j+1])
                {
                    nxt = h(i, j+1);
                    adj[cur].pb(nxt);
                }
            }
        }
    int res = BFS(s, 0, 0);
    (res)? cout<<"YES" : cout<<"NO";

    return 0;
}