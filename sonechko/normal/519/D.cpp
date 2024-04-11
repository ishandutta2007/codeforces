#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 26;
map<ll,ll> ab[N];
ll a[N];
int main()
{
    for (int i=0; i<=25; i++)
        cin>>a[i];
    string s;
    cin>>s;
    ll sum=0;
    ll ans=0;
    for (int i=0; i<s.size(); i++)
    {
        ans+=ab[s[i]-'a'][sum];
        sum+=a[s[i]-'a'];
        ab[s[i]-'a'][sum]++;
    }
    cout<<ans<<endl;
}