#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll k;
ll a[1000000];
ll pre[1000000];
ll suf[1000000];
ll solve()
{
    ll sum=0;
    for (int i=1;i<=n;i++){
        sum+=a[i];
        pre[i]=i*a[i] - sum;
    }
    if (pre[n]<=k)return 0;
    sum=0;
    for (int i=n;i>=1;i--){
        sum+=a[i];
        suf[i]=sum - (n-i+1)*a[i];
    }
    int r=2;
    ll ret = 1e18;
    for (int i=1;i<n;i++) {
        if (pre[i]>k)break;
        while(r<n && pre[i]+suf[r]>k)r++;
        ll left = i;
        ll right = (n-r+1);
        ll L = a[i];
        ll R = a[r];
        ll cur = R-L - min((k-suf[r]-pre[i])/right,a[r]-a[r-1]);
        ret=min(ret,cur);
    }
    int l=n-1;
    for (int i=n;i>1;i--) {
        if (suf[i]>k)break;
        while(l>1 && pre[l]+suf[i]>k)l--;
        ll left = l;
        ll L = a[l];
        ll R = a[i];
        ll cur = R-L - min((k-suf[i]-pre[l])/left,a[l+1]-a[l]);
        ret=min(ret,cur);
    }
    if (ret<0)ret=0;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    cout<<solve()<<endl;
}