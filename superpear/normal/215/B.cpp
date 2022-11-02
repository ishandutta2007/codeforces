#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>

#define maxlongint 2147483647;

using namespace std;

int main()
{
    int n,cs,a,b,r1=0,p1=0,p2=maxlongint;
    double e;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>cs;
        if (cs>r1) r1=cs;
    }
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>cs;
        if (cs>p1) p1=cs;
    }
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>cs;
        if (cs<p2) p2=cs;
    }
    cin>>a>>b;
    e=sqrt(double(b)*p1*r1*r1/(a*p2+b*p1));
    printf("%.8lf",e);
    return 0;
}