# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans;
    if ((a-1)/m==(b-1)/m)
    {
        cout<<1<<endl;
        return 0;
    }
    if ((m==1 || a%m==1) && (b==n || b%m==0))
    {
        cout<<1<<endl;
        return 0;
    }
    int x=a%m;
    int y=b%m;
    if (x==0)
        x=m;
    if (y==0)
        y=m;
    if (a%m==1 || (b==n || b%m==0) || (a-1)/m+1==(b-1)/m || y+1==x)
    {
        cout<<2<<endl;
        return 0;
    }
    cout<<3<<endl;
}