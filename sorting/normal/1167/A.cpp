#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;

    cin >> n;

    string s;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '8'){
            if(s.size() - i >= 11){
                cout << "YES\n";

                return;
            }
            cout << "NO\n";

            return;
        }
    }

    cout << "NO\n";

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}