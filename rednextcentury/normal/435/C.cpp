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
char s[10000][1000];
int a[1000];
int y[100000];
int x[100000];
int main()
{
    int nowy=5000;
    int nowx=0;
    int maxy=5000;
    int miny=5000;
    int n;
    cin>>n;
    int ys=0;
    int xs=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        
        if (i%2==0)
        {
            ys+=a[i];
        }
        else
            ys-=a[i];
        xs+=a[i];
        y[i]=ys;
        x[i]=xs;
    }
    for (int i=0;i<n;i++)
    {
        while(nowy-5000!=y[i] || nowx!=x[i])
        {
            if (nowy<miny)
                miny=nowy;
            if (nowy-5000>y[i])
            {
                s[nowy-1][nowx]='\\';
                if (nowy-1<miny)
                    miny=nowy-1;
                nowy--;
                nowx++;
            }
            else
            {
            if (nowy>maxy)
                maxy=nowy;
                s[nowy][nowx]='/';
                nowy++;
                nowx++;
            }
        }
    }
    for (int i=maxy;i>=miny;i--)
    {
        for (int j=0;j<x[n-1];j++)
        {
            if (s[i][j]=='/' || s[i][j]=='\\')
                cout<<s[i][j];
            else
                cout<<' ';
        }
        cout<<endl;
    }
}