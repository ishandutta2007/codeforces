#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long double x[6000],y[6000],z[6000];
    long double A,B;
    int n,m,k;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
       cin>>x[i];
    cin>>m;
    for(i=0;i<m;i++)
       cin>>y[i];
    cin>>k;
    for(i=0;i<k;i++)
       cin>>z[i];
    cin>>A>>B;
    long double maxi1=x[0];
    for(i=0;i<n;i++)
      if(maxi1<x[i])
         maxi1=x[i];
    long double xx;
    long double yy;
    long double maxi2=y[0];
    for(i=0;i<m;i++)
       if(maxi2<y[i])
         maxi2=y[i];
    long double mini=z[0];
    for(i=0;i<k;i++)
       if(mini>z[i])
          mini=z[i];

    xx=maxi2/mini;
    yy=A/B;
    long double zz=xx/(xx+yy);
    long double l=0.00000000;
    long  double r=2.000000000;
    long double ff;
    while(r-l>0.000000001)
    {
        ff=(l+r)/2;
        if(ff*ff>zz)
            r=ff;
        else
            l=ff;
    }
    double r2=(double)maxi1*ff;
    printf("%.10f",r2);
    cout<<endl;
    return 0;
}