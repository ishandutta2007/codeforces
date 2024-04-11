#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];
    int pos=1,ans=0;
    for (int i=1; i<=n; i++)
    {
        if (b[pos]>=a[i]) {ans++; pos++;}
    }
    cout<<ans<<endl;
}