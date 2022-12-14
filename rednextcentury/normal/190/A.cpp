#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,m;
    cin>>n>>m;
    if (n==0 && m>0)
    {
        cout<<"Impossible"<<endl;
    }
    else
    {
        long long mn = n+max(m-n,0LL);
        long long mx = n+m-min(1LL,m);
        cout<<mn<<' '<<mx<<endl;

    }
}