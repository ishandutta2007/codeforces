#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 11;

ll a[N],b[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll c=0;
    for (int i=2; i<=n; i++)
    {
        cin>>b[i];
        a[i]=a[i-1]+b[i];
        c=min(c,a[i]);
    }
    c=1-c;
    a[1]=c;
    for (int i=2; i<=n; i++)
        a[i]=a[1]+a[i];
    for (int i=1; i<=n; i++)
    {
        if (a[i]>n||use[a[i]]==1) {cout<<-1; return 0;}
        use[a[i]]=1;
    }
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}