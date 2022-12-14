#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        int ret=0;
        while(max(a,b)<=n){
            if (a>b) b+=a;
            else a+=b;
            ret++;
        }
        cout<<ret<<endl;
    }
}