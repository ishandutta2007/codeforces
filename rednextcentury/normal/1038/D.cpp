#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
long long a[1000000];
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll pos=0,neg=0,zero=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)neg+=a[i];
        else if (a[i]>0)pos+=a[i];
        else zero=1;
    }
    if (n==1)
    {
        cout<<a[0]<<endl;
        return 0;
    }
    sort(a,a+n);
    if (zero)
    {
        ll ret=0;
        for (int i=0;i<n;i++)
            ret+=max(a[i],-a[i]);
        cout<<ret<<endl;
        return 0;
    }
    if (pos!=0 && neg!=0)
    {
        cout<<pos-neg<<endl;
    }
    else if (pos==0)
    {
        cout<<-neg+2*a[n-1]<<endl;
    }
    else
    {
        cout<<pos-2*a[0]<<endl;
    }
}