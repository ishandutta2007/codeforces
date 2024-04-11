#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll n,u,i,j,k,a[100004];
ld mx=-1;
int main()
{
    cin >> n  >> u ;
    for (i=0;i<n;i++)
        cin >> a[i];
    i=0,k=2;
    while(i<n && k<n )
    {
        while(a[k+1]-a[i] <=u && k<n-1)k++;
        j=i+1;

        if (a[k]-a[i]<=u && j!=k)
            mx=max(mx ,(ld) (a[k]-a[j])/(a[k]-a[i]) );
        i++;
        if (i==k)k++;
    }
    cout << setprecision(20) <<  mx ;
    return 0;
}