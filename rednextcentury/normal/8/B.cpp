#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;
bool open[1000][1000];
bool visited[1000][1000];
int ans[1000][1000];
void bfs()
{
    visited[500][500]=1;
    ans[500][500]=0;
    queue<int> q1;
    queue<int> q2;
    q1.push(500);
    q2.push(500);
    while(!q1.empty())
    {
        int x=q1.front();
        int y=q2.front();
        q1.pop();
        q2.pop();
        if (open[x-1][y] && !visited[x-1][y])
        {
            visited[x-1][y]=1;
            ans[x-1][y]=ans[x][y]+1;
            q1.push(x-1);
            q2.push(y);
        }
        if (open[x+1][y] && !visited[x+1][y])
        {
            visited[x+1][y]=1;
            ans[x+1][y]=ans[x][y]+1;
            q1.push(x+1);
            q2.push(y);
        }
        if (open[x][y-1] && !visited[x][y-1])
        {
            visited[x][y-1]=1;
            ans[x][y-1]=ans[x][y]+1;
            q1.push(x);
            q2.push(y-1);
        }
        if (open[x][y+1] && !visited[x][y+1])
        {
            visited[x][y+1]=1;
            ans[x][y+1]=ans[x][y]+1;
            q1.push(x);
            q2.push(y+1);
        }
    }
}
int main()
{
    string s;
    cin>>s;
    int sx=500,sy=500;
    int n=s.length();
    open[500][500]=1;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='U')
        {
            open[sx][sy+1]=1;
            sy++;
        }
        else if (s[i]=='D')
        {
            open[sx][sy-1]=1;
            sy--;
        }
        else if (s[i]=='L')
        {
            open[sx-1][sy]=1;
            sx--;
        }
        else
        {
            open[sx+1][sy]=1;
            sx++;
        }
    }
    bfs();
    if (ans[sx][sy]==n)
        cout<<"OK"<<endl;
    else
        cout<<"BUG\n";
}