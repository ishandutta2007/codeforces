#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> m(k, -1);
        string s;
        cin >> s;

        bool ok = true;
        for(int i = 0; i < n; ++i){
            int idx = i % k;
            if(s[i] == '?') continue;
            if(m[idx] != -1 && m[idx] != (s[i] - '0')){
                cout << "NO\n";
                ok = false;
                break;
            }
            else m[idx] = (s[i] - '0');
        }

        if(ok){
            int l = 0, r = 0;
            for(int i = 0; i < k; ++i){
                if(m[i] == -1) r++;
                else if(m[i] == 1) l++, r++;
            }

            if(l <= k / 2 && k / 2 <= r) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}