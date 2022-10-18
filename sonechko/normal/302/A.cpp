#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 1e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a1=0,a2=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l==1) a1++; else a2++;
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        if (a1>=(r-l+1)/2&&a2>=(r-l+1)/2&&(r-l+1)%2==0) cout<<1<<"\n"; else
            cout<<0<<"\n";
    }
}