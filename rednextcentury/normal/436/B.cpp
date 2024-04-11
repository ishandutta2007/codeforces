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
# include<ios>
using namespace std;
char a[3000][3000];
int main()
{   
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            cin>>a[i][x];   
        }
    }
    for (int x=0;x<m;x++)
    {
        int now=0;
        for (int i=0;i<n;i++)
        {
            if (x+i<m && a[i][x+i]=='L')
                now++;
            if (x>=i && a[i][x-i]=='R')
                now++;
            if (a[i][x]=='U' && i%2==0)
                now++;
        }
        cout<<now<<" ";
    }
    cout<<endl;
}