#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll b[1000000];
ll c1[1000000];
ll preC[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i=1;i<=2*n;i++){
            if (i<=n)cin>>a[i]>>b[i];
            else a[i] = a[i-n], b[i]=b[i-n];
            c1[i] = max(0LL, a[i]-b[i-1]);
            preC[i] = c1[i] + preC[i-1];
        }
        ll ret=1e18;
        for (int i=1;i<=n;i++){
            ll cost = a[i] + preC[i+n-1]-preC[i];
            ret=min(ret,cost);
        }
        cout<<ret<<endl;
    }
}