#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pt
{
    int x;
    int y;
};

vector <vector<int> > g;
vector <bool> used;
vector <int> sz;
vector <pt> pts;
vector <int> ans;

pt ex;

bool cmp (int i,int j)
{
    return (pts[i].x<pts[j].x)||(pts[i].x==pts[j].x&&pts[i].y<pts[j].y);
}

bool cmp2(int i,int j)
{
    if (pts[i].x==ex.x&&pts[j].x==ex.x) return (pts[i].y<pts[j].y);
    return (long long)(pts[i].y-ex.y)*(long long) (pts[j].x-ex.x)<(long long)(pts[j].y-ex.y)*(long long)(pts[i].x-ex.x);
}

int dfs(int v)
{
    used[v]=true;
    int s=1;
    for (int i=0;i<(int)g[v].size();i++)
    {
        int to = g[v][i];
        if (!used[to])
        {
            s+=dfs(to);
        }
    }
    sz[v]=s;
    return s;
}

void solve(int v, vector <int> &r)
{
    used[v]=true;
    vector <int> tmp;
    sort(r.begin(),r.end(),cmp);
    ans[r[0]]=v+1;
    ex=pts[r[0]];
    sort(r.begin()+1,r.end(),cmp2);
    int j=1;
    for (int i=0;i<(int)g[v].size();i++)
    {
        int to = g[v][i];
        if (!used[to])
        {
            tmp.clear();
            for (int k=j;k<j+sz[to];k++)
            {
                tmp.push_back(r[k]);
            }
            j=j+sz[to];
            solve(to,tmp);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    ans.resize(n);
    g.resize(n);
    used.assign(n,false);
    sz.resize(n);
    pts.resize(n);
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    for (int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        pts[i].x=a;
        pts[i].y=b;
    }
    dfs(0);
    used.assign(n,false);
    vector <int> p;
    for (int i=0;i<n;i++)
        p.push_back(i);
    solve(0,p);
    for (int i=0;i<n;i++)
    {
        cout << ans[i] << " ";
    }


    return 0;
}