#include<bits/stdc++.h>
using namespace std;
int n,a,b;
bool can(int x1,int y1,int x2,int y2)
{
    if (x1+x2<=a && y1<=b && y2<=b)
        return 1;
    if (y1+y2<=b && x1<=a && x2<=a)
        return 1;
    return 0;
}
int x[1000],y[1000];
int main()
{
    cin>>n>>a>>b;
    for (int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    int mx=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i==j)
                continue;
            bool c=0;
            c|=can(x[i],y[i],x[j],y[j]);
            c|=can(y[i],x[i],x[j],y[j]);
            c|=can(x[i],y[i],y[j],x[j]);
            c|=can(y[i],x[i],y[j],x[j]);
            if (c)mx=max(mx,x[i]*y[i]+x[j]*y[j]);
        }
    }
    cout<<mx<<endl;
}