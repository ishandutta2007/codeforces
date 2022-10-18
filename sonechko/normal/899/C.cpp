#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    if (n%4==0)
    {
        cout<<0<<endl;
        cout<<n/2<<" ";
        for (int i=1; i<=n/4; i++)
            cout<<i<<" "<<n-i+1<<" ";
        cout<<endl;
        return 0;
    }
    if (n%2==0)
    {
        cout<<1<<endl;
        cout<<n/2<<" ";
        for (int i=1; i<=n/4; i++)
        cout<<i<<" "<<n-i+1<<" ";
        cout<<n/2<<endl;
        return 0;
    }
    if (n%4==1)
    {
        cout<<1<<endl;
        cout<<n/2<<" ";
        for (int i=2; i<=n/4+1; i++)
        cout<<i<<" "<<n-i+2<<" ";
        cout<<endl;
        return 0;
    }
    cout<<0<<endl;
    cout<<n/2<<" ";
    for (int i=2; i<=n/4+1; i++)
    cout<<i<<" "<<n-i+2<<" ";
    cout<<n/2+2<<endl;
}