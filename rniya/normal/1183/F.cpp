#include <bits/stdc++.h>
using namespace std;

set<int> cnt;

void solve(){
    int M=*cnt.rbegin();
    int ans=0;
    if (M%2==0&&M%3==0&&M%5==0){
        if (cnt.count(M/2)&&cnt.count(M/3)&&cnt.count(M/5)){
            ans=M/2+M/3+M/5;
        }
    }
    vector<int> res;
    while(!cnt.empty()&&res.size()<3){
        int x=*cnt.rbegin(); cnt.erase(x);
        int ng=0;
        for (int y:res) ng|=(y%x==0);
        if (!ng) res.emplace_back(x);
    }
    ans=max(ans,accumulate(res.begin(),res.end(),0));
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        cnt.clear();
        for (int i=0;i<n;++i){
            int a; cin >> a;
            cnt.emplace(a);
        }
        solve();
    }
}