#include<iostream>
#include<algorithm>
#include<cmath>
#define endl "\n"

using namespace std;

long long a[300001],res;

int main ()
{
    int n,i;

    ios::sync_with_stdio(false);

    cin>>n;

    for(i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);

    for(i=0;i<n;i++)
    {
        res+=abs(i+1-a[i]);
    }

    cout<<res<<endl;

    return 0;
}