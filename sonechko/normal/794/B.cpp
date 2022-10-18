#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define sqr(a) ((a)*(a))
const int N = 1e5 + 11;

ld b,a,h;
int n;

long double ploscha(long double hh)
{
    ld bb=hh/h;
    ld bbb=b*bb;
    ld aaa=bb;
    ld p=(bbb+bbb+aaa)/(ld)2;
    ld ss=sqrt(p*(p-bbb)*(p-bbb)*(p-aaa));
    return ss;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(10);
    cout<<fixed;
    cin>>n>>h;
    a=1;
    b=sqrt(sqr(h)+sqr(0.5));
    ld p=(b*2+(ld)1)/(ld)2;
    ld s=sqrt(p*(p-b)*(p-b)*(p-a));
    ld plo1=s/(ld)n;
    for(int i=1; i<n; i++)
    {
        ld sss=plo1*i;
        ld l=0;
        ld r=h;
        while (r-l>0.000000001)
        {
            ld mid=(l+r)/2;
            if (ploscha(mid)-sss<0.000000001) l=mid;
            else r=mid;
        }
        if (abs(ploscha(l)-sss)<=0.000000001) cout<<l<<endl; else
            cout<<r<<endl;

    }
}