#include <bits/stdc++.h>
using namespace std;
char a[501][501];
char b[501][501];
int n,m;
void rotateA()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            b[i][j]=a[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=b[j][m-i+1];
    swap(n,m);
}
int d1[2001][2001];
int d2[2001][2001];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    int T=4;
    int ret=0;
    while(T--)
    {
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        rotateA();
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='1')
                {
                    d1[i+j][i]=1;
                    d2[i-j+1000][i]=1;
                }
                d1[i+j][i]+=d1[i+j][i-1];
                d2[i-j+1000][i]+=d2[i-j+1000][i-1];
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int l=1;l<=m;l++)
            {
                if (a[i][l]=='1')continue;
                for (int r=l+1;r<=m;r++)
                {
                    if (a[i][r]=='1')break;
                    if ((r-l)%2)continue;
                    int x = (r-l)/2;
                    if (i-x-1>=0)
                        if (d1[i+l][i]==d1[i+l][i-x-1] && d2[i-r+1000][i]==d2[i-r+1000][i-x-1])
                            ret++;

                }
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='1')continue;
                int c1=j,c2=i;
                for (int x=1;x<=n;x++)
                {
                    c1++,c2--;
                    if (c1>m || c2<=0)
                        break;
                    if (a[i][c1]=='1' || a[c2][j]=='1')
                        break;
                    if (d2[i-c1+1000][i]==d2[i-c1+1000][c2-1])
                        ret++;
                }
            }
        }
    }
    cout<<ret<<endl;
}