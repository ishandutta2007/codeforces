#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
int n,m,k;
int op[][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool good(int x,int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return 0;
    return a[x][y]=='*';
}
void scan(int x)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            bool ok=good(i,j);
            for (int p=0;p<4;p++)
            {
                if (!good(i+op[p][0]*x,j+op[p][1]*x))
                    ok=0;
            }
            if (ok)k--;
            if (k==0)
            {
                k--;
                i++;j++;
                cout<<i<<' '<<j<<endl;
                for (int p=0;p<4;p++)
                {
                    cout<<i+op[p][0]*x<<' '<<j+op[p][1]*x<<endl;
                }
                return;
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=1;i<=160;i++)
        scan(i);
    if (k>0)cout<<-1<<endl;
}