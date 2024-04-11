#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long h;
        cin>>n>>h;
        for (int i=0;i<n;i++) cin>>a[i];
        long long l=1, r=h;
        long long ans = h;
        while(l<=r) {
            long long mid = (l+r)/2;
            long long dmg = mid;
            for (int i=0;i+1<n;i++) {
                if (dmg>=h)break;
                dmg += min(a[i+1]-a[i], mid);
            }
            if (dmg>=h) ans = min(ans, mid), r=mid-1;
            else l=mid+1;
        }
        cout<<ans<<endl;
    }
}