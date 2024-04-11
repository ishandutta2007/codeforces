#include <bits/stdc++.h>

using namespace std;
int x[1000000],y[1000000];
bool is_dangerous(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if (x2==x3 && y3<y2)
        if (y1==y2 && x2<x1)
            return 1;
    if (x2==x3 && y3>y2)
        if (y1==y2 && x2>x1)
            return 1;
    if (y2==y3 && x3>x2)
        if (x1==x2 && y2<y1)
            return 1;
    if (y2==y3 && x3<x2)
        if (x1==x2 && y2>y1)
            return 1;
        return 0;
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        int j=(i-1+n)%n;
        int k=(i-2+n)%n;
        if (is_dangerous(x[k],y[k],x[j],y[j],x[i],y[i]))
            ans++;
    }
    cout<<ans<<endl;
}