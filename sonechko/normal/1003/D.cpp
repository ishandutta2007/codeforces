#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int N = 2e5 + 11;

int a[N],kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        int p=0;
        while (a[i]>1)
        {
            p++;
            a[i]/=2;
        }
        kol[p]++;
    }
    for (int i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        int ans=0;
        for (int j=30; j>=0; j--)
        {
            int c=(1<<j);
            int p=min(kol[j],x/c);
            ans+=p;
            x-=p*c;
        }
        if (x!=0) cout<<-1<<"\n"; else cout<<ans<<"\n";
    }
}