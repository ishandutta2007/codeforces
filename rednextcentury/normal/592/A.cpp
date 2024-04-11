#include<bits/stdc++.h>
using namespace std;
char mp[10][10];
int main()
{
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            cin>>mp[i][j];
        }
    }
    int A=100,B=100;
    for (int i=0;i<8;i++)
    {
        int x=7;
        while(x>=0 && mp[x][i]=='.')
            x--;
        if (x<0)
            continue;
        if (mp[x][i]=='B')
            B=min(B,7-x);

    }
    for (int i=0;i<8;i++)
    {
        int x=0;
        while(x<8 && mp[x][i]=='.')
            x++;
        if (x>=8)
            continue;
        if (mp[x][i]=='W')
            A=min(A,x);

    }
    if (A<=B)
        cout<<'A'<<endl;
    else
        cout<<'B'<<endl;
}