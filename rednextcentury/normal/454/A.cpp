# include <iostream>
# include <algorithm>
# include<stdio.h>
#include<set>
using namespace std;
char a[1000][1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        for (int x=0;x<n;x++)
            a[i][x]='D';
    int c=1;
    for (int i=n/2-1;i>=0;i--)
    {
        for (int x=0;x<c;x++)
            a[i][x]='*',a[i][n-x-1]='*';
        c++;
    }
    c=1;
    for (int i=n/2+1;i<n;i++)
    {
        for (int x=0;x<c;x++)
            a[i][x]='*',a[i][n-x-1]='*';
        c++;
    }
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<n;x++)
        {
            cout<<a[i][x];
        }
        cout<<endl;
    }
}