
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
int a[4][101];

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[0][i]>>a[1][i]>>a[2][i]>>a[3][i];
    int id=0,mn=1000000;
    for (int i=0;i<n;i++)
    {
        bool p=1;
        for (int j=0;j<n;j++)
        {
            if (a[0][i]<a[0][j] && a[1][i]<a[1][j] && a[2][i]<a[2][j])
                p=0;
        }
        if (p)
        {
            if (a[3][i]<mn)
            {
                mn=a[3][i];
                id=i+1;
            }
        }
    }
    cout<<id<<endl;
}