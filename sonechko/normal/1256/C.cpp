#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int c[N],ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    int pos=0;
    for (int i=1; i<=m; i++)
    {
        pos+=d;
        int l;
        cin>>l;
        pos+=l-1;
        c[i]=l;
    }
    pos+=d;
    if (pos<n+1) {cout<<"NO"; return 0;}
    cout<<"YES\n";
    pos=0;
    int sum=0;
    for (int i=1; i<=m; i++)
        sum+=c[i];
    for (int i=1; i<=m; i++)
    {
        if (pos+d+sum-1<=n) pos+=d; else pos=n-sum+1;
        for (int j=pos; j<=pos+c[i]-1; j++)
            ans[j]=i;
        pos+=c[i]-1;
        sum-=c[i];
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}