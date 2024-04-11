#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <queue>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
bool vis[100][100];
string h,v;
int ans;
int n,m;
void bfs(int sx,int sy)
{
    queue<int> q1;
    queue<int> q2;
    q1.push(sx);
    q2.push(sy);
    while(!q1.empty())
    {
        int x=q1.front();
        int y=q2.front();
        q1.pop();
        q2.pop();
        if (h[x]=='>')
        {
            if (y+1<m && !vis[x][y+1])
            {
                vis[x][y+1]=1;
                q1.push(x);
                q2.push(y+1);
                ans++;
            }
        }
        else
        {
            if (y-1>=0 && !vis[x][y-1])
            {
                vis[x][y-1]=1;
                q1.push(x);
                q2.push(y-1);
                ans++;
            }
        }
        if (v[y]=='^')
        {
            if (x-1>=0 && !vis[x-1][y])
            {
                vis[x-1][y]=1;
                q1.push(x-1);
                q2.push(y);
                ans++;
            }
        }
        else
        {
            if (x+1<n && !vis[x+1][y])
            {
                vis[x+1][y]=1;
                q1.push(x+1);
                q2.push(y);
                ans++;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    cin>>h>>v;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            memset(vis,0,sizeof(vis));
            ans=1;
            bfs(i,x);
            if (ans<n*m)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}