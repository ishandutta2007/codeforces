# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<cmath>
# include <vector>
# include <iomanip>
#define EPS 1e-9
using namespace std;
int f(string x,int base)
{
    int ret=0;
    int n=x.length();
    for (int i=0;i<n;i++)
    {
        ret=ret*base + x[i]-'0';
    }
    return ret;
}
int solve(int n,int base)
{
    int len=0;
    while(n>0)
    {
        len++;
        n/=base;
    }
    return len;
}
int main()
{
    string x,y;
    cin>>x>>y;
    int mx=0;
    int n=x.length();
    for (int i=0;i<n;i++)
        mx=max(mx,x[i]-'0');
    int m=y.length();
    for (int i=0;i<m;i++)
        mx=max(mx,y[i]-'0');
    cout<< solve(f(x,mx+1)+f(y,mx+1),mx+1) <<endl;
}