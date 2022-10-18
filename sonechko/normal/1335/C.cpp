#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

int kk[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        kk[i]=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        kk[l]++;
    }
    sort(kk+1,kk+n+1);
    int t=0;
    for (int i=1; i<=n; i++)
        if (kk[i]!=0) t++;
    int ans=0;
    for (int i=1; i<=kk[n]; i++)
    {
        if (i==kk[n]) t--;
        ans=max(ans,min(t,i));
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}