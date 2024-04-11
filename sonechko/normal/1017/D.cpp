#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back


const int N = 5000 + 11;

int a[N],kk[N];
int b[N][105];
int n;

void rec(int mask1, int mask2, int ans, int kol)
{
    if (kol==n)
    {
        if (ans<=100) b[mask1][ans]+=kk[mask2];
        return;
    }
    if (mask1&(1<<kol)) rec(mask1,mask2,ans,kol+1);
    else rec(mask1,mask2,ans+a[kol],kol+1);
    if (mask1&(1<<kol)) rec(mask1,mask2+(1<<kol),ans+a[kol],kol+1);
    else rec(mask1,mask2+(1<<kol),ans,kol+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,q;
    cin>>n>>m>>q;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
    {
        string s;
        cin>>s;
        int mask=0;
        for (int j=0; j<s.size(); j++)
            if (s[j]=='1') mask+=(1<<j);
        kk[mask]++;
    }
    for (int i=0; i<(1<<n); i++)
    {
        rec(i,0,0,0);
        for (int j=1; j<=100; j++)
            b[i][j]+=b[i][j-1];
    }
    for (int i=1; i<=q; i++)
    {
        string s;
        int k;
        cin>>s>>k;
        int mask=0;
        for (int j=0; j<s.size(); j++)
            if (s[j]=='1') mask+=(1<<j);
        cout<<b[mask][k]<<"\n";
    }
}