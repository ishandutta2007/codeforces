
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
    int n;
    cin>>n;
    int o=0,e=0;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        if (x%2) o++;
        else e++;
    }
    if (sum%2)
    {
        cout<<o<<endl;
    }
    else
    {
        cout<<e<<endl;
    }
}