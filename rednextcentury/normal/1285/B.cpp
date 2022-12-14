#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        for (int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
        ll mx=0,cur=0;
        for (int i=n;i>1;i--) {
            cur+=a[i];
            mx = max(mx,cur);
        }
        cur=0;
        for (int i=1;i<n;i++) {
            cur+=a[i];
            if (cur<0)cur=0;
            mx=max(mx,cur);
        }
        if (sum>mx)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}