#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; string S; cin >> n >> S;
    set<pair<int,int>> s;
    vector<int> ans(n);
    for (int i=0;i<n;++i){
        int nxt=-(S[i]-'a');
        auto itr=s.lower_bound({nxt,0});
        if (itr!=s.end()){
            ans[i]=(*itr).second;
            s.erase(itr); s.emplace(nxt,ans[i]);
        } else {
            ans[i]=s.size()+1;
            s.emplace(nxt,ans[i]);
        }
    }
    cout << s.size() << '\n';
    for (int i=0;i<n;++i) cout << ans[i] << (i!=n-1?' ':'\n');
}