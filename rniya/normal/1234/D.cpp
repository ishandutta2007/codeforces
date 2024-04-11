#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; int q; cin >> S >> q;
    int N=S.size();
    vector<set<int>> pos(26);
    for (int i=0;i<N;++i)
        pos[S[i]-'a'].insert(i);
    for (;q--;){
        int t; cin >> t;
        if (t==1){
            int k; char c; cin >> k >> c; --k;
            for (int i=0;i<26;++i)
                if (pos[i].count(k)) pos[i].erase(k);
            pos[c-'a'].insert(k);
        } else {
            int l,r,ans=0; cin >> l >> r; --l,--r;
            for (int i=0;i<26;++i)
                if (pos[i].upper_bound(r)!=pos[i].lower_bound(l))
                    ++ans;
            cout << ans << '\n';
        }
    }
}