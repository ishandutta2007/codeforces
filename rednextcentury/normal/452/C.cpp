#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    if (n==1 && m==1)
    {
        cout<<setprecision(10)<<fixed<<1<<endl;
        return 0;
    }
    long double ret = 1.0/n;
    ret += ((n-1.0)/n)*((m-1.0)/(n*m-1.0));
    cout<<setprecision(10)<<fixed<<ret<<endl;
}