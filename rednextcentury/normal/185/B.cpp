#include <bits/stdc++.h>
using namespace std;
int main()
{
    long double S;
    int a,b,c;
    cin>>S;
    cin>>a>>b>>c;
    if (a+b+c==0)
        cout<<setprecision(12)<<fixed<<0.0<<' '<<0.0<<' '<<S<<endl;
    else
    {
        long double x = (a*S)/(a+b+c);
        long double y = (b*S)/(a+b+c);
        long double z = (c*S)/(a+b+c);
        cout<<setprecision(12)<<fixed<<x<<' '<<y<<' '<<z<<endl;
    }
}