#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define y1 y12312312
#define int ll

using namespace std;
const int N=100001;
const int inf=1e9+3;
const int md=1e9+7;
const ll linf = 1e18;

int n,a[1001];

main()
{
    bs
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int d=a[2]-a[1];
    for(int i=2;i<=n;++i)
    {
        if(a[i]-a[i-1]!=d)
        {
            cout<<a[n];
            return 0;
        }
    }
    cout<<a[n]+d;
}