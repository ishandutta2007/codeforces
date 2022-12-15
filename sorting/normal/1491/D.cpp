#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    for(int i = 0; i < q; ++i){
        int u, v;
        cin >> u >> v;
        if(u > v){
            cout << "NO\n";
            continue;
        }
        int cnt_u = __builtin_popcount(u);
        int cnt_v = __builtin_popcount(v);
        if(cnt_u < cnt_v){
            cout << "NO\n";
            continue;
        }

        cnt_u = 0, cnt_v = 0;
        bool ok = true;
        for(int i = 0; i <= 29; ++i){
            if(!((u >> i) & 1)) cnt_u++;
            if(!((v >> i) & 1)) cnt_v++;
            if(cnt_u > cnt_v){
                cout << "NO\n";
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
    }
}