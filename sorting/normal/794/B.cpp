#include<iostream>
#include<cmath>

using namespace std;

int main ()
{
    int n,h,i;
    double expect,exp2=0,p;

    ios::sync_with_stdio(false);

    cin>>n>>h;

    expect=(double)h/2/n;

    for(i=0;i<n-2;i++)
    {
        exp2+=(double)expect;

        p=(double)exp2*2/h;

        p=(double)sqrt(p);

        p=(double)p*h;

        cout.precision(8);

        cout<<p<<" ";
    }

     exp2+=(double)expect;

    p=(double)exp2*2/h;

    p=(double)sqrt(p);

    p=(double)p*h;

    cout.precision(8);

    cout<<p<<endl;

    return 0;
}