#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

int k[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    string s;
    cin>>s;
    string t;
    cin>>t;
    s="."+s;
    t="."+t;
    for (int i=1; i<=n-m+1; i++)
    {
        k[i]=k[i-1]+1;
        for (int j=1; j<=m; j++)
        if (s[i+j-1]!=t[j]) {k[i]--; break;}
    }
    for (int i=1; i<=q; i++)
    {
        int l,r;
        cin>>l>>r;
        if (r-l+1<m) cout<<0<<"\n"; else cout<<k[r-m+1]-k[l-1]<<"\n";
    }
}