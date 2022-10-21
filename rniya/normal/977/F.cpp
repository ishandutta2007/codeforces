#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vector<int> dp(n+1),nxt(n);
    map<int,int> pre;
    for (int i=n-1;i>=0;--i){
        nxt[i]=(!pre.count(a[i]+1)?-1:pre[a[i]+1]);
        pre[a[i]]=i;
    }
    int ans=0,s;
    for (int i=n-1;i>=0;--i){
        dp[i]=(~nxt[i]?dp[nxt[i]]+1:1);
        if (ans<dp[i]) ans=dp[i],s=i;
    }
    cout << ans << '\n';
    for (int i=0;i<ans;++i){
        cout << s+1 << (i+1==ans?'\n':' ');
        s=nxt[s];
    }
}