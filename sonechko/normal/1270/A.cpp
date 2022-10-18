#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k1,k2;
        cin>>n>>k1>>k2;
        int c=0;
        for (int i=1; i<=k1; i++)
        {
            int x;
            cin>>x;
            if (x==n) c=1;
        }
        for (int i=1; i<=k2; i++)
        {
            int x;
            cin>>x;
            if (x==n) c=2;
        }
        if (c==1) cout<<"YES\n"; else cout<<"NO\n";
    }
}