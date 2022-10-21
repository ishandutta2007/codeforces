#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    map<int,vector<pair<int,int>>> m;
    for (int r=0;r<n;++r){
        int sum=0;
        for (int l=r;l>=0;--l){
            sum+=a[l];
            m[sum].emplace_back(l+1,r+1);
        }
    }
    int ans=0;
    vector<pair<int,int>> blocks;
    for (auto x:m){
        auto v=x.second;
        int cnt=0,now=0;
        vector<pair<int,int>> tmp;
        for (auto p:v){
            if (now<p.first){
                ++cnt; tmp.emplace_back(p);
                now=p.second;
            }
        }
        if (ans<cnt) ans=cnt,blocks=tmp;
    }
    cout << ans << '\n';
    for (auto p:blocks) cout << p.first << ' ' << p.second << '\n';
}