#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void up()
{
    int s;
    cin>>s;
    ll ans=0;
    while (s>=10)
    {
        int t=s/10;
        ans+=t*10;
        s-=t*10;
        s+=t;
    }
    ans+=s;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}