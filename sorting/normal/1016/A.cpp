#include<bits/stdc++.h>

using namespace std;

long long a[200001];
long long res[200001];

int main ()
{
    long long n,m,i,pr=0;

    cin>>n>>m;

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        a[i]+=pr;
        res[i]=a[i]/m;
        pr=a[i]%m;
    }

    for(i=0;i<n-1;i++)
        cout<<res[i]<<" ";
    cout<<res[i]<<endl;

    return 0;
}