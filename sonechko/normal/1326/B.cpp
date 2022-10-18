#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll mx=0;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        a[i]=mx+b[i];
        mx=max(mx,a[i]);
        cout<<a[i]<<" ";
    }

}