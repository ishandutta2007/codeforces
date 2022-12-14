# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
int is[610][601];
char mp[1001][1001];
bool vis[1001][1002];
char ret[250][250];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<1000;i++)
    {
        for (int j=0;j<1000;j++)
        {
            mp[i][j]='x';
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>mp[500+i][500+j];
        }
    }
    int num=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (mp[i+500][j+500]=='o')
            {
                num++;
                for (int dx=-50;dx<=50;dx++)
                {
                    for (int dy=-50;dy<=50;dy++)
                    {
                        if (dx==0 && dy==0)
                            continue;
                        if (mp[i+500+dx][j+500+dy]=='x' || mp[i+500+dx][j+500+dy]=='o')
                            is[dx+50][dy+50]++;
                    }
                }
            }
        }
    }
    int sx=n-1;int sy=n-1;
    for (int i=0;i<3*n;i++)
    {
        for (int j=0;j<3*n;j++)
        {
            ret[i][j]='.';
        }
    }
    ret[sx][sy]='o';
    for (int i=0;i<=100;i++)
    {
        for (int j=0;j<=100;j++)
        {
            if (is[i][j]==num)
            {
                int nx,ny;
                nx=sx+i-50;
                ny=sy+j-50;
                if (ny>=0 && ny<2*n-1 && nx>=0 && nx<2*n-1)
                {
                    ret[nx][ny]='x';
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (mp[i+500][j+500]=='o')
            {
                for (int dx=-50;dx<=50;dx++)
                {
                    for (int dy=-50;dy<=50;dy++)
                    {
                        if (is[dx+50][dy+50]==num)
                        {
                            vis[i+500+dx][j+500+dy]=1;
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (mp[i+500][j+500]=='x')
            {
                if (vis[i+500][j+500]==0)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            if (mp[i+500][j+500]=='.')
            {
                if (vis[i+500][j+500]==1)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<2*n-1;i++)
    {
        for (int j=0;j<2*n-1;j++)
        {
            cout<<ret[i][j];
        }
        cout<<endl;
    }
}