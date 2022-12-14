# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
int can;
int mx(int d1,int h1,int d2,int h2)
{
    if (abs(d2-d1)<abs(h1-h2))
    {
        can=-1;
        return 0;
    }
    return (abs(d2-d1)-abs(h1-h2))/2+max(h1,h2);
}
int main()
{
    int ret=0;
    int n,m;
    cin>>n>>m;
    int ld=1,lh=0;
    for (int i=0;i<m;i++)
    {
        int d,h;
        cin>>d>>h;
        if (i>0)
        {
        ret=max(ret,mx(ld,lh,d,h));
        }
        else
        {
            ret=max(ret,h+d-1);
        }
        lh=h;
        ld=d;
        if (i==m-1)
        {
            ret=max(ret,h+n-d);
        }
    }
    if (can==-1)
        cout<<"IMPOSSIBLE"<<endl;
    else
        cout<<ret<<endl;
}