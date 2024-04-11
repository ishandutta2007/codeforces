#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
long long static a[4],b,c,d,e;
int main()
{
    cin>>b;
    e=0;
    for (c=1; c<=b; c++)
    {
        cin>>d;
        if (d==4) e++; else a[d]++;
    }
    a[1]-=a[3];
    e+=a[3];
    e+=a[2]/2;
    if (a[2]%2==1)
    {
        a[1]-=2;
        e++;
    }
    if (a[1]>0)
    {
        e+=a[1]/4;
        if (a[1]%4>0) e++;
    }
    cout<<e;
}