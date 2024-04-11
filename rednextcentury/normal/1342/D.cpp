#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[1000000];
int have[1000000];
int one[1000000];
vector<vector<int> > ret;
int n,k;
bool check(ll mid){
    for (int i=1;i<=k;i++){
        ll x = one[i]*mid;
        x = min(x, 0LL+n);
        have[i] = x;
    }
    ll take = 0;
    for (int i=k;i>=1;i--){
        int cur = have[i] - take;
        if (cnt[i] > cur) return 0;
        take += cnt[i];
    }
    return 1;
}
void build(ll mid){
    set<pair<int,int> > s;
    for (int i=1;i<=k;i++){
        ll x = one[i]*mid;
        x = min(x, 0LL+n);
        have[i] = x;
    }
    for (int i=1;i<=mid;i++){
        s.insert({0, i-1});
        ret.push_back({});
    }
    ll take = 0;
    for (int i=k;i>=1;i--){
        while(cnt[i]--){
            auto p = *s.begin();
            s.erase(p);
            s.insert({p.first+1,p.second});
            ret[p.second].push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for (int i=1;i<=k;i++){
        cin>>one[i];
    }
    int ans=-1;
    ll l=1, r=n;
    while(l<=r){
        ll mid = (l+r)/2;
        if (check(mid)) ans=mid, r = mid-1;
        else l=mid+1;
    }
    build(ans);
    cout<<ans<<endl;
    for (auto test:ret){
        cout<<test.size();
        for (auto x:test)cout<<' '<<x;
        cout<<endl;
    }
}