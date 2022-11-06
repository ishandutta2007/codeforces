#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+5;

int ara[sz], a[sz];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &ara[i]);

    int msk=1, ans=0;
    for(int k=1; k<26; k++) {
        for(int i=0; i<n; i++) a[i]=ara[i]&msk;
        sort(a,a+n);

        ll cnt=0;
        int up=msk, dn=msk>>1;
        int up2=up|(1<<k), dn2=dn|(1<<k);
        for(int i=0; i<n; i++) {
            cnt += upper_bound(a+i+1,a+n,up-a[i]) - upper_bound(a+i+1,a+n,dn-a[i]);
            cnt += upper_bound(a+i+1,a+n,up2-a[i]) - upper_bound(a+i+1,a+n,dn2-a[i]);
        }
        if(cnt&1) ans|=up^dn;

        msk|=(1<<k);
    }

    cout << ans;
}