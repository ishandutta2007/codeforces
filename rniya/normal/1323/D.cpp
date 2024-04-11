#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n),b(n),po(28,1);
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<27;++i) po[i+1]=po[i]*2;
    int ans=0;
    for (int j=0;j<25;++j){
        ll cnt=0;
        for (int i=0;i<n;++i) b[i]=a[i]&(po[j+1]-1);
        sort(b.begin(),b.end());
        for (int i=0;i<n;++i){
            int c=a[i]&(po[j+1]-1);
            cnt+=lower_bound(b.begin(),b.end(),po[j+1]-c)
                -lower_bound(b.begin(),b.end(),po[j]-c);
            cnt+=lower_bound(b.begin(),b.end(),po[j+2]-c)
                -lower_bound(b.begin(),b.end(),po[j+1]+po[j]-c);
            if ((a[i]<<1)&po[j]) --cnt;
        }
        cnt>>=1LL;
        if (cnt&1LL) ans+=po[j];
    }
    cout << ans << '\n';
}