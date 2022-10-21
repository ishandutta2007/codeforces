#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; string S; cin >> n >> S;
    vector<int> cnt(n+1,0);
    for (int i=0;i<n;++i){
        cnt[i+1]=cnt[i];
        cnt[i+1]+=(S[i]=='('?1:-1);
    }
    if (cnt[n]!=0){cout << -1 << '\n'; return 0;}
    int ans=0,last,now=1;
    for (int i=0;i<n;++i){
        if (now&&cnt[i+1]<0) now^=1,last=i;
        if (!now&&cnt[i+1]==0) now^=1,ans+=i-last+1;
    }
    cout << ans << '\n';
}