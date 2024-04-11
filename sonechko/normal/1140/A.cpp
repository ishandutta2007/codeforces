#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int p=0,ans=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        p=max(p,a[i]);
        if (p==i) ans++;
    }
    cout<<ans<<endl;
}