#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
ll a[1000000];
ll pre[1000000];
ll getAll(){
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll sum=0;
    ll ret=1e18;
    for (int i=n;i>=1;i--){
        ll L = i-1;
        ll R = n-i+1;
        sum+=a[i];
        ret=min(ret, a[i]*L - pre[i-1] + sum - a[i]*R);
    }
    return ret;
}
ll getPrefix(){
    ll ret=0;

    for (int i=1;i<=k;i++){
        ret+=a[k]-a[i];
    }
    return min(ret,ret);
}
ll getSuffix(){
    ll ret=0;

    for (int i=n;i>=n-k+1;i--) {
        ret += a[i] - a[n - k + 1];
    }
    return min(ret,ret);
}
ll P[1000000];
ll S[1000000];
ll ThisIsWhyIHateDiv3(){
    ll ans=1e18;
    for (int i=1;i<=n;i++){
        P[i]=P[i-1]+a[i];
    }
    for (int i=n;i>=1;i--){
        S[i]=S[i+1]+a[i];
    }
    for (int i=1;i<=n;){
        int j = i;
        while(j+1<=n && a[j+1]==a[i])j++;

        ll l = i, r = j;
        if (r-l+1>=k)return 0;
        ll L = i-1;
        ll R = n-j;
        ll suffixCost = S[j+1] - R*(a[i]+1);
        ll prefixCost = L*(a[i]-1) - P[i-1];
        // get suffix only
        if (R+(j-i+1)>=k) ans = min(ans, suffixCost + k-(j-i+1));
        // get prefix only
        if (L+(j-i+1)>=k) ans = min(ans, prefixCost + k-(j-i+1));
        // get both
        ans=min(ans, prefixCost+suffixCost+k-(j-i+1));
        i=j+1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    cout<<min(min(getPrefix(), getSuffix()),min(getAll(), ThisIsWhyIHateDiv3()))<<endl;
}