#include <bits/stdc++.h>

using namespace std;

int  newMask[1000000][4];
bool canMove[1000000][4];
int mv[][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int len;

int getMove(int x,int y)
{
    if (x==1 && y==0)
        return 0;
    if (x==0 && y==1)
        return 1;
    if (x==-1 && y==0)
        return 2;
    return 3;
}

vector<pair<int,int> > getLoc(int mask)
{
    vector<pair<int,int> > ret;
    ret.push_back(make_pair(0,0));
    for (int i=0;i+1<len;i++)
    {
        int j = mask%4;
        mask/=4;
        int x = ret[ret.size()-1].first  + mv[j][0];
        int y = ret[ret.size()-1].second + mv[j][1];
        ret.push_back(make_pair(x,y));
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int getMask(vector<pair<int,int> > loc)
{
    int ret = 0;
    for (int i=0;i+1<loc.size();i++)
    {
        int x = loc[i].first  - loc[i+1].first;
        int y = loc[i].second - loc[i+1].second;
        ret = ret*4 + getMove(x,y);
    }
    return ret;
}

void precalc()
{
    int num = len-1;
    for (int i=0;i<(1<<(2*num));i++)
    {
        vector<pair<int,int> > loc = getLoc(i);
        for (int x=0;x<4;x++)
        {
            bool ok=1;
            for (int j=1;j<loc.size();j++)
            {
                if (mv[x][0]==loc[j].first && mv[x][1]==loc[j].second)
                    ok=0;
            }
            if (ok)
            {
                canMove[i][x]=true;
                vector<pair<int,int> > newLoc = loc;
                newLoc.erase(newLoc.begin());
                newLoc.push_back(make_pair(mv[x][0],mv[x][1]));
                newMask[i][x]=getMask(newLoc);
            }
        }
    }
}

pair<int,int> l[10];
int n,m;
char a[100][100];
int dist[16][16][70000];
bool vis[16][16][70000];
int X,Y;
int ans;
int bfs(pair<int,int> v, int mask)
{
    ans=1000000000;
    queue<pair<int,int> > q1;
    queue<int> q2;
    q1.push(v);
    q2.push(mask);
    vis[v.first][v.second][mask]=1;
    while(!q1.empty())
    {
        v    = q1.front(); q1.pop();
        mask = q2.front(); q2.pop();
        if (v == make_pair(X,Y))
            ans = min(ans, dist[v.first][v.second][mask]);
        for (int x=0;x<4;x++)
        {
            if (!canMove[mask][x])continue;
            pair<int,int> u = v;
            u.first += mv[x][0];
            u.second += mv[x][1];
            if (u.first<0 || u.first>=n || u.second<0 || u.second>=m || a[u.first][u.second]=='#')
                continue;
            int uMask = newMask[mask][x];
            if (vis[u.first][u.second][uMask])
                continue;
            dist[u.first][u.second][uMask] = 1 + dist[v.first][v.second][mask];
            vis[u.first][u.second][uMask] = 1;
            q1.push(u);
            q2.push(uMask);
        }
    }
    if (ans==1000000000)
        return -1;
    return ans;
}

void getInput()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]>='1' && a[i][j]<='9')
                len++,l[a[i][j]-'0']=make_pair(i,j);
            if (a[i][j]=='@')
                X = i, Y = j;
        }
    }
    vector<pair<int,int> > fLoc;
    for (int i=len;i>=1;i--)
        fLoc.push_back(l[i]);
    precalc();
    int mask = getMask(fLoc);
    cout<<bfs(fLoc[fLoc.size()-1],mask)<<endl;
}

int main()
{
    getInput();
}