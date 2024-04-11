#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int b[200005];
int ll[200005],rr[200005];
vector<int> v;
long long ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int l=0;
    int r=1e9;
    for (int i=1;i<=n;++i) {
        cin>>a[i]>>b[i];
        b[i]=a[i]+b[i];
        --l; ++r;
        l=max(l,a[i]);
        r=min(r,b[i]);
        if (l>r) {
            cout<<"-1";
            return 0;
        }
        ll[i]=l; rr[i]=r;
    }
    for (int i=n;i>0;--i) {
        ans+=(long long)(r-a[i]);
        v.push_back(r);
        if (i==1) break;
        if (r<ll[i-1]) ++r;
        else if (r>rr[i-1]) --r;
        else if (r<rr[i-1]) ++r;
    }
    cout<<ans<<'\n';
    for (int i=v.size()-1;i>=0;--i)
        cout<<v[i]<<" ";
}