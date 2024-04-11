#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y1 kdjf

const int N = 4e5 + 11;
const ll MOD = 1e9 + 7;

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int l=1,x=0;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        if (b[i]>b[l]) l=i;
    }
    b[0]=b[n];
    for (int i=1; i<=n; i++)
        if (b[i]==b[l]&&b[i]>b[i-1]) l=i;
    for (int i=1; i<=n; i++)
        if (b[i]!=b[l]) x=1;
    if (x==0&&b[1]==0)
    {
        cout<<"YES\n";
        for (int i=1; i<=n; i++)
            cout<<1<<" ";
        cout<<"\n";
        return 0;
    }
    if (x==0) {cout<<"NO"; return 0;}
    cout<<"YES\n";
    x=l;
    ll sum=b[x]*2;
    a[x]=b[x];
    for (int i=x-1; i>=1; i--)
    {
        sum+=b[i];
        a[i]=sum;
    }
    for (int i=n; i>x; i--)
    {
        sum+=b[i];
        a[i]=sum;
    }
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}