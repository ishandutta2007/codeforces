#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll inc[1000000];
ll lst1[1000000];
ll decr[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll last=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        inc[i]=inc[i-1];
        if (a[i]<=last) inc[i]+=last+1-a[i], lst1[i]=last+1;
        else lst1[i]=a[i];
        last=lst1[i];
    }
    last=0;
    ll ret=1e18;
    for (int i=n;i>=1;i--){
        decr[i]=decr[i+1];
        if (a[i]<=last) decr[i]+=last+1-a[i], last = last+1;
        else last=a[i];
        ret=min(ret,inc[i-1]+decr[i]+(lst1[i-1]==last));
    }
    cout<<ret<<endl;
}