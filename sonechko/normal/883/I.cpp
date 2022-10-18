#include <bits/stdc++.h>
using namespace std;



int n,k;
int dp[300005];
int a[300005];

inline bool ff(int l,int r){
    return dp[r]-(l ? dp[l-1] : 0);
}
inline bool f(int mid){
    if (a[n]-a[1]==mid) return true;
    dp[0]=1;
    int l=1;
    for (int i=1;i<=n;++i) {
        dp[i]=dp[i-1];
        while (l<i && a[i]-a[l]>mid) ++l;
        if (i-l+1<k) continue;
        if (ff(l-1,i-k)) dp[i]++;
    }
    return (dp[n]-dp[n-1]>0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=0;
    int r=a[n]-a[1];
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (f(mid)) r=mid;
        else l=mid+1;
    }
    if (f(l)) cout<<l;
    else cout<<r;
}