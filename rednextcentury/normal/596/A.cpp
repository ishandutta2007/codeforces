//#include <cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include <map>
#include<cstdio>
using namespace std;
int x[100],y[100];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>x[i]>>y[i];
    if (n==1)
        cout<<-1<<endl;
    else if (n==2)
    {
        if (x[0]==x[1] || y[0]==y[1])
            cout<<-1<<endl;
        else
            cout<<abs(y[0]-y[1])*abs(x[0]-x[1])<<endl;
    }
    else
    {
        int mnx=1000000,mxx=-100000,mny=1000000,mxy=-1000000;
        for (int i=0;i<n;i++)
        {
            mnx=min(mnx,x[i]);
            mny=min(mny,y[i]);
            mxx=max(mxx,x[i]);
            mxy=max(mxy,y[i]);

        }
        cout<<(mxy-mny)*(mxx-mnx)<<endl;
    }
}