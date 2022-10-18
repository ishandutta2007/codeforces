#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l,r;
    cin>>l>>r;
    cout<<"YES\n";
    while (l<=r)
    {
        cout<<l<<" "<<l+1<<"\n";
        l+=2;
    }
}
/**

**/