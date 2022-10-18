#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=1,p1=0,p2=0;
    for (int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        if (p1>p2&&y>=p1) ans+=min(x,y)-p1+1; else
        if (p2>p1&&x>=p2) ans+=min(x,y)-p2+1; else
        if (p1==p2) ans+=min(x,y)-p1;
        p1=x;
        p2=y;
       // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}