#include <bits/stdc++.h>
using namespace std;
int ret=10000000;
int n;
char a[4][200][200];
int cur[401][401];
void setUp(int b[])
{
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cur[i][j]=a[b[0]][i][j]-'0';

    for (int i=n;i<2*n;i++)
        for (int j=0;j<n;j++)
            cur[i][j]=a[b[1]][i-n][j]-'0';

    for (int i=0;i<n;i++)
        for (int j=n;j<2*n;j++)
            cur[i][j]=a[b[2]][i][j-n]-'0';


    for (int i=n;i<2*n;i++)
        for (int j=n;j<2*n;j++)
            cur[i][j]=a[b[3]][i-n][j-n]-'0';

}
void solve()
{
    // 0
    int c1=0;
    for (int i=0;i<2*n;i++)
        for (int j=0;j<2*n;j++)
            if (((i+j)%2)!=cur[i][j])
                c1++;
    // 1
    int c2=4*n*n-c1;
    ret = min(min(ret,c1),c2);
}
int main()
{
    cin>>n;
    for (int i=0;i<4;i++)
    {
        for (int x=0;x<n;x++)
            for (int y=0;y<n;y++)
                cin>>a[i][x][y];
    }
    int b[] = {0,1,2,3};
    do
    {
        setUp(b);
        solve();
    }while(next_permutation(b,b+4));
    cout<<ret<<endl;
}