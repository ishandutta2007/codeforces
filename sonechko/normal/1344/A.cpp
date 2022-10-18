#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 4e5 + 11;
const int MOD = 1e9 + 7;

int a[N],use[N];

void up()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
        use[i]=0;
    int ans=1;
    for (int i=0; i<n; i++)
    {
        a[i]=(a[i]+n)%n;
        int x=(i+a[i]+n)%n;
        x=(x+n)%n;
        x=(x+n)%n;
        if (use[x]==1) ans=0;
        use[x]=1;
    }
    if (ans==1) cout<<"YES\n"; else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        up();
    }
}