# include <iostream>
# include <string>
# include <vector>
# include <stdio.h>
# include <map>
using namespace std;
bool vis[2][1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n*n;i++)
    {
        int x,y;
        cin>>x>>y;
        if (!vis[0][x] && !vis[1][y])
        {
            cout<<i+1<<" ";
            vis[0][x]=vis[1][y]=1;
        }
    }
    cout<<endl;
}