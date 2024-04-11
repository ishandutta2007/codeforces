#include <bits/stdc++.h>
using namespace std;
int main()
{
    long double a,b,c,d;
    cin>>a>>b>>c>>d;
    long double p = a/b;
    long double q = (1-a/b)*(1-c/d);
    long double ret=0;
    for (int i=0;i<1000000;i++)
        ret+=p,p*=q;
    cout<<setprecision(10)<<fixed<<ret<<endl;
}