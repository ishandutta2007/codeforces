#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[1000000];
int main()
{
    fast
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for (int i=2;i<n;i++)
    {
        if (a[i-1]+a[i-2]>a[i])
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}