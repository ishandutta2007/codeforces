#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int ans=0;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        ll p1=l*x1+r*y1+k;
        ll p2=l*x2+r*y2+k;
        if ((p1<0&&p2>0)||(p2<0&&p1>0)) ans++;
    }
    cout<<ans<<endl;
}