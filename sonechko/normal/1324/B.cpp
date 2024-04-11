#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int a[N],use[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int g=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            use[j]=0;
        for (int j=1; j<i; j++)
            use[a[j]]=1;
        for (int j=i+1; j<=n; j++)
            if (use[a[j]]==1) g=1;
    }
    for (int i=1; i<=n; i++)
    {
        int l=i,r=-1;
        for (int j=i+1; j<=n; j++)
        if (a[i]==a[j]) {r=j; break;}
        if (r==-1) continue;
        for (int j=1; j<=n; j++)
            use[j]=0;
        for (int j=1; j<l; j++)
            use[a[j]]=1;
        for (int j=r+1; j<=n; j++)
            if (use[a[j]]==1) g=1;
    }
    if (g) cout<<"YES\n"; else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}