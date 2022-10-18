#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double

const int N = 2e6 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    int t;
    cin>>t;
    t--;
    int ans=n;
    for (int i=1; i<=n; i++)
        if (b[i]<=t) ans--;
    cout<<ans<<endl;
}