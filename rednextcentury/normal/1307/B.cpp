#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll ret=1e12;
        ll mx=0;
        ll amx=0;
        for (int i=0;i<n;i++){
            cin>>r[i];
            ret = min(ret, max(1LL,d/r[i])+((d%r[i])>0));
        }
        cout<<ret<<endl;
    }
}