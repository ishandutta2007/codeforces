#include<bits/stdc++.h>
using namespace std;
long double h;
long double tot;
long double need;
long double area(long double H)
{
    long double x=H/(2*h);
    long double width=1-2*x;
    long double height=h-H;
    return tot-width*height/2;
}
long double bs(long double l,long double r)
{
    long double ret=-1;
    long double p=l;
    for (int i=0;i<100;i++)
    {
        long double mid=(l+r)/2;
        if (area(mid)-area(p)>=need)
            ret=mid,r=mid;
        else l=mid;
    }
    return ret;
}
long double ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n>>h;
    tot=h/2;
    long double last=0;
    need=tot/n;
    for (int i=0;i<n-1;i++)
    {
        last=bs(last,h);

        ret[i]=h-last;
    }
    for (int i=n-2;i>=0;i--)
        cout<<setprecision(10)<<fixed<<ret[i]<<' ';
    cout<<endl;
}