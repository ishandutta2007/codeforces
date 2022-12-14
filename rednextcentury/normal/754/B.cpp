#include<bits/stdc++.h>
using namespace std;
char a[5][5];
bool check()
{
    int n=4;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j]!='x')
                continue;
            if (i+2<4 && j-2>=0 && a[i+1][j-1]=='x' && a[i+2][j-2]=='x')
                return 1;
            if (i-2>=0 && j+2<4 && a[i-1][j+1]=='x' && a[i-2][j+2]=='x')
                return 1;
            if (i+2<4 && j+2<4 && a[i+1][j+1]=='x' && a[i+2][j+2]=='x')
                return 1;
            if (i-2>=0 && j-2>=0 && a[i-1][j-1]=='x' && a[i-2][j-2]=='x')
                return 1;
            if (i+2<4 && a[i+1][j]=='x' && a[i+2][j]=='x')
                return 1;
            if (i-2>=0 && a[i-1][j]=='x' && a[i-2][j]=='x')
                return 1;
            if (j+2<4 && a[i][j+1]=='x' && a[i][j+2]=='x')
                return 1;
            if (j-2>=0 && a[i][j-1]=='x' && a[i][j-2]=='x')
                return 1;
        }
    }
    return 0;
}
int main()
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            cin>>a[i][j];
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (a[i][j]=='.')
            {
                a[i][j]='x';
                if (check())
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
                a[i][j]='o';
            }
        }
    }
    cout<<"NO"<<endl;
}