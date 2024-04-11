#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int kol=0;
    vector<int> v;
    for (int i=1; i<=n; i++)
        if (a[i]!=a[i-1]) v.pb(1);
    else v.back()++;
    int ans=0;
    for (int i=v.size()-1; i>=0; i--)
    ans=max(ans,v[i]);
    cout<<ans<<endl;
}