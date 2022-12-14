
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<cmath>
# include <vector>
# include <iomanip>
#define EPS 1e-9
using namespace std;
long double dist(long double x,long double y,long double c,long double d)
{
    return sqrt((x-c)*(x-c) + (y-d)*(y-d));
}
int main()
{
    int n,k;
    cin>>n>>k;
    long double lx,ly;
    cin>>lx>>ly;
    long double ret=0;
    for (int i=1;i<n;i++)
    {
        long double x,y;
        cin>>x>>y;
        ret+=dist(lx,ly,x,y)/50.0;
        lx=x,ly=y;
    }
    cout<<setprecision(10)<<ret*k<<endl;
}