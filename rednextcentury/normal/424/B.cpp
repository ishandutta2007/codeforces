# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <cmath>
# include <algorithm>
using namespace std;
struct city
{
    long double d;
    int k;
};
city a[10000];
bool comp(city a,city b)
{
        return a.d<b.d;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        long double x,y,p;
        cin>>x>>y>>p;
        a[i].d=sqrt(x*x+y*y);
        a[i].k=p;
    }
    sort(a,a+n,comp);
    for (int i=0;i<n;i++)
    {
        k+=a[i].k;
        if (k>=1000000)
        {
            cout<<setprecision(7)<<fixed<<a[i].d<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}