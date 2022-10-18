#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

ll a[N],d[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    {
        s[i]=s[i-1]+a[i];
        if (i<m) d[i]=s[i]; else d[i]=d[i-m]+s[i];
        cout<<d[i]<<" ";
    }
}

/**

**/