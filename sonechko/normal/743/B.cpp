#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define s second
#define ll long long
#define f first
#define mp make_pair
#define pb push_back
int main()
{
    sync;
    #ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #else
    #endif
    ll n,m;
    cin>>n>>m;
    int ans=1;
    while(m>0)
    {
        if (m%2==0) ans++; else break;
        m/=2;
    }
    cout<<ans<<endl;
}