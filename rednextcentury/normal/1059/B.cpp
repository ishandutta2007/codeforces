#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=0;i+2<n;i++)
    {
        for (int j=0;j+2<m;j++)
        {
            if (a[i][j]=='#')
            {
                int num=0;

                for (int x=i;x<=i+2;x++)
                    for (int y=j;y<=j+2;y++)
                        if (a[x][y]=='#')num++;
                if (a[i+1][j+1]=='#')
                    num--;
                if (num==8)
                {
                    for (int x=i;x<=i+2;x++)
                        for (int y=j;y<=j+2;y++)
                            if (x!=i+1 || y!=j+1)
                                vis[x][y]=1;
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (!vis[i][j] && a[i][j]=='#')
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}