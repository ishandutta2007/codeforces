# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;
int main()
{
    long long m,r;
    cin>>m>>r;
    long double w=r*sqrt(2.0);
    long double ans=m*r*2;
    for (int i=1;i<m;i++)
    {
        long double x=2*i+((m-2*i)*2);
        if (i==1)
            ans+=x*(2*r+w);
        else
        {
            ans+=x*((2*w+2*r)+(((i-2)*2)*r));
        }
    }
    long double c=m*m;
    cout<<fixed<<setprecision(10)<<(ans/c)<<endl;
}