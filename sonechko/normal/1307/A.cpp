#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

void up()
{
    int n,d;
    cin>>n>>d;
    int ans;
    cin>>ans;
    for (int i=2; i<=n; i++)
    {
        int x;
        cin>>x;
        int t=min(d/(i-1),x);
        ans+=t;
        d-=t*(i-1);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}