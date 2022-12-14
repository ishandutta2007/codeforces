# include<iostream>
#include<bits/stdc++.h>
#define EPS 1e-6
#include <stdio.h>
using namespace std;
int main()
{
    long double a,b,m;
    long double x,y,z;
    long double vx,vy,vz;
    cin>>a>>b>>m;
    cin>>vx>>vy>>vz;
    x=a/2,y=m,z=0;
    long double t=abs(y/vy);
    x=x+vx*t;
    y=y+vy*t;
    z=z+vz*t;
    while(1)
    {
        if (x>-EPS && x<a+EPS)
            break;
        if (x<=-EPS)
            x=-x;
        else
            x=2*a-x;
    }
    while(1)
    {
        if (z>-EPS && z<b+EPS)
            break;
        if (z<=-EPS)
            z=-z;
        else
            z=2*b-z;
    }
    cout<<setprecision(10);
    cout<<x<<" "<<z<<endl;
}