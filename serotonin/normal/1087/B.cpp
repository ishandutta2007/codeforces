#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5,p=998244353;

int main()
{
    ll i,j,k,n,m,ans=1e15;
    cin >> n >> k;
    for(i=1; i<k; i++) {
        if(n%i==0) {
            m=i;
            j=n/i;
            ans=min(ans,j*k+m);
        }
    }
    cout << ans << endl;
}