# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<cstdlib>
using namespace std;
int a[5];
bool used[5];
long long talk[100][100];
long long best=-1;
void check()
{
    if (a[0]==2 && a[1]==3 && a[2]==1 && a[3]==5 && a[4]==4)
    {
        int g;
    }
    long long ans=0;
    for (int i=0;i<5;i++)
    {
        for (int x=i;x<5;x+=2)
        {
            if (x+1<5)
            {
                ans+=talk[a[x]][a[x+1]]+talk[a[x+1]][a[x]];
            }
        }
    }
    if (ans>best)
        best=ans;
}
void solve(int i)
{
    if (i==5)
    {
        check();
    }
    else
    {
        for (int x=0;x<5;x++)
        {
            if (!used[x])
            {
                used[x]=1;
                a[i]=x;
                solve(i+1);
                used[x]=0;
            }
        }
    }
}
int main()
{
    for (int i=0;i<5;i++)
    {
        for (int x=0;x<5;x++)
        {
            cin>>talk[i][x];
        }
    }
    solve(0);
    cout<<best<<endl;
}