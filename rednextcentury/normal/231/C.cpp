#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll n,m;
int best;
bool check(ll len){
    ll sum=0;
    int l = 1 , r = len;
    for (int i=1;i<=len;i++){
        sum += a[i];
    }
    while(r<=n){
        if (a[r]*len - sum <= m){
            best = a[r];
            return 1;
        }
        sum+=a[r+1];
        r++;
        sum-=a[l];
        l++;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    int ret = 1, mn = a[0];
    while(l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ret = mid, mn = best;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout<<ret<<' '<<mn<<endl;
}