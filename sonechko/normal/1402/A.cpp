#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (n==1)
    {
        cout<<"1 1"<<endl;
        cout<<-a[1]<<endl;
        cout<<"1 1"<<endl;
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        cout<<0<<endl;
        return 0;
    }
    cout<<"1 1"<<endl;
    cout<<-a[1]<<endl;
    cout<<2<<" "<<n<<endl;
    a[1]=0;
    for (int i=2; i<=n; i++)
    {
        ll x=a[i]*(n-1);
        cout<<x<<" ";
        a[i]+=x;
    }
    cout<<endl;
    cout<<1<<" "<<n<<endl;
    for (int i=1; i<=n; i++)
    {
        cout<<-a[i]<<" ";
    }
    cout<<endl;
}
/**
n = 4
a[i] + a[i]*(n-1) = a[i]*n
**/