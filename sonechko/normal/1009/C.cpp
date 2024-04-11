#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ld long double
#define ll long long
#define ss second



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    for (int i=1; i<=m; i++)
    {
        ll x,d;
        cin>>x>>d;
        sum+=x*n;
        if (d>0) sum+=d*n*(n-1)/2; else
        {
            ll p=n/2;
            sum+=d*p*(p+1)/2;
            if (n%2==0) p--;
            sum+=d*p*(p+1)/2;
        }
    }
    cout.precision(10);
    cout<<fixed;
    cout<<(ld)sum/(ld)n<<endl;
}
/**

**/