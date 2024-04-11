#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q,k;
    cin>>n>>q>>k;
    a[n+1] = k+1;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        b[i] = (a[i] - a[i-1] - 1) + (a[i+1] - a[i] - 1);
        b[i]+=b[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if (l==r) {
            cout<<k-1<<endl;
        }
        else {
            ll ret = b[r-1] - b[l];
            ret += k-a[r] + (a[l]-1) + (a[l+1]-a[l]-1) + (a[r] - a[r-1]-1);
            cout<<ret<<endl;
        }
    }
}