#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    if (n==1) {cout<<1<<" "<<1<<endl; return 0;}
    int ans=0;
    ll mm=m;
    for (int i=1; i<=n; i++)
        if (i<n&&mm>0) {mm--; i++;} else
        if (i==n&&mm>0) mm--; else ans++;
    cout<<ans<<" ";
    int kol=0;
    ans=0;
    for (int i=1; i<=n; i++)
        if (m<=0) ans++; else
        {
            m-=kol;
            kol++;
        }
    cout<<ans<<endl;
}