#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cost;
pair<ll,int> operator+(pair<ll,int> A,pair<ll,int> B) {
    return {A.first+B.first, A.second+B.second };
}
int n, k, l;
int vis[1000000];
int T;
string s;
pair<ll,int> dp[1000000];
pair<ll,int> sol(int i) {
    if (i==n)
        return {0,0};
    if (vis[i]==T)
        return dp[i];
    vis[i]=T;
    dp[i]= sol(i+1);
    dp[i].first += isupper(s[i]);
    if (i+l<=n) {
        auto cur = sol(i+l);
        cur.second++;
        cur.first+=cost;
        dp[i] = min(dp[i], cur);
    }

    return dp[i];
}
ll solve(){
    ll l = -1e12, r = 1e12;
    ll ret = -1;
    while(l<=r){
        T++;
        cost = (l+r)/2;
        if (sol(0).second > k)
            l=cost+1;
        else if (sol(0).second <= k)
            r = cost - 1, ret = sol(0).first - cost*k;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>l;
    if (n <= l*1LL*k) {
        cout<<0<<endl;
        return 0;
    }
    cin>>s;
    ll L = solve();
    for (auto &x:s) if (islower(x)) x = toupper(x); else x = tolower(x);
    L = min(L, solve());
    cout<<L<<endl;
}