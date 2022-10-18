#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N],b[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    int k1=0,k2=0;
    for (int i=1; i<=n; i++)
        if (a[i]==1) k1++; else
        if (a[i]==-1) k2++;
    for (int i=n; i>=1; i--)
    {
        if (a[i]==1) k1--; else
        if (a[i]==-1) k2--;
        if (a[i]==b[i]) continue;
        if (a[i]<b[i]&&k1==0) {cout<<"NO\n"; return;}
        if (a[i]>b[i]&&k2==0) {cout<<"NO\n"; return;}
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}