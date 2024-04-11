#include <bits/stdc++.h>
using namespace std;
char a[22][22];
bool check()
{
    for (int i=1;i<=10;i++)
    {
        for (int j=1;j<=10;j++)
        {
            int x=i,y=j;
            bool ok=1;
            for (int k=0;k<5;k++)
            {
                if (a[x][y]!='X')
                {
                    ok=0;
                    break;
                }
                x++;
                y++;
            }
            if (ok)return 1;
            x=i,y=j;
            ok=1;
            for (int k=0;k<5;k++)
            {
                if (a[x][y]!='X')
                {
                    ok=0;
                    break;
                }
                x++;
                y--;
            }
            if (ok)return 1;
            x=i,y=j;
            ok=1;
            for (int k=0;k<5;k++)
            {
                if (a[x][y]!='X')
                {
                    ok=0;
                    break;
                }
                x++;
            }
            if (ok)return 1;
            x=i,y=j;
            ok=1;
            for (int k=0;k<5;k++)
            {
                if (a[x][y]!='X')
                {
                    ok=0;
                    break;
                }
                y++;
            }
            if (ok)return 1;
        }
    }
    return 0;
}
int main ()
{
    a[0][0]='.';
    a[11][11]='.';
    for (int i=1;i<=10;i++)
    {
        a[0][i]='.';
        a[i][0]='.';
        a[11][i]='.';
        a[i][11]='.';
        for (int j=1;j<=10;j++)
        {
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=10;i++)
    {
        for (int j=1;j<=10;j++)
        {
            if (a[i][j]=='.')
            {
                a[i][j]='X';
                if (check())
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
                a[i][j]='.';
            }
        }
    }
    cout<<"NO"<<endl;

}