#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

template<typename T> vector<T> compress(vector<T> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}

template<typename T> map<T,int> dict(vector<T> v){
    map<T,int> res;
    for (int i=0;i<v.size();++i) res[v[i]]=i;
    return res;
}

int n;

void solve(){
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    map<int,int> d=dict(compress(a));
    for (int i=0;i<n;++i) a[i]=d[a[i]];
    vector<int> Min(n,INF),Max(n,-1);
    for (int i=0;i<n;++i){
        Min[a[i]]=min(Min[a[i]],i);
        Max[a[i]]=max(Max[a[i]],i);
    }
    vector<vector<int>> dp(n,vector<int>(3,-INF));
    map<int,int> pre;
    int ans=0;
    for (int i=0;i<n;++i){
        dp[i][2]=1;
        if (pre.count(a[i]-1)){
            int nxt=(i==Min[a[i]]?1:0);
            if (i==Max[a[i]]&&nxt==1) nxt=2;
            dp[i][nxt]=max(dp[i][nxt],dp[pre[a[i]-1]][2]+1);
        }
        if (pre.count(a[i])){
            dp[i][0]=max(dp[i][0],dp[pre[a[i]]][0]+1);
            dp[i][1]=max(dp[i][1],dp[pre[a[i]]][1]+1);
            dp[i][2]=max(dp[i][2],dp[pre[a[i]]][2]+1);
            if (i==Max[a[i]]) dp[i][2]=max(dp[i][2],dp[pre[a[i]]][1]+1);
        }
        ans=max(ans,max({dp[i][0],dp[i][1],dp[i][2]}));
        pre[a[i]]=i;
    }
    cout << n-ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n;
        solve();
    }
}