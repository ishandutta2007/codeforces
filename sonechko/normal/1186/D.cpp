#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 2e5 + 11;

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for (int i=1; i<=n; i++)
    {
        ld p;
        cin>>p;
        ll c1=floor(p);
        ll c2=ceil(p);
        a[i]=c1;
        b[i]=c2;
        sum+=a[i];
    }
    for (int i=1; i<=n; i++)
        if (sum<0&&a[i]!=b[i]) {sum++; cout<<b[i]<<"\n";} else
            cout<<a[i]<<"\n";
}