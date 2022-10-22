#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,m; string S; cin >> n >> m >> S;
        vector<int> p(m);
        for (int i=0;i<m;++i) cin >> p[i],--p[i];
        sort(p.begin(),p.end());
        vector<int> cnt(26,0);
        for (int i=0;i<n;++i){
            cnt[S[i]-'a']+=p.end()-lower_bound(p.begin(),p.end(),i)+1;
        }
        for (int i=0;i<26;++i) cout << cnt[i] << (i!=25?' ':'\n');
    }
}