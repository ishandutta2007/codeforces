#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll n,d;
        cin>>n>>d;
        bool ok=0;
        for (ll i=0;i*i<=d;i++) {
            if (i+(d/(i+1))+((d%(i+1))>0) <= n)
            {
                ok=1;
                break;
            }
        }
        if (ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}