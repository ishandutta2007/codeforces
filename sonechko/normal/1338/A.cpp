#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

ll a[N];

void up()
{
    int n;
    cin>>n;
    int k=0;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
    {
        ll t=a[i];
        for (int j=0; j<k; j++)
            t+=(1ll<<j);
        if (t>=a[i-1]) a[i]=max(a[i-1],a[i]); else
        {
            while (t<a[i-1])
            {
                k++;
                t+=(1ll<<(k-1));
            }
            a[i]=a[i-1];
        }
    }
    cout<<k<<"\n";
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}