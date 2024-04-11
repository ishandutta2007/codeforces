#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> invs;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            invs.push_back({i, i + 1});
        } else {
            invs.back().second++;
        }
    }
    bool valid = true;
    for (int i = 0; i < invs.size(); i++) {
        if (invs[i].second - invs[i].first < 2) {
            valid = false;
            break;
        }
    }
    if(valid){
        for(auto p: invs){
            int f = p.first + 1;
            int s = p.second;
            for(int i = f; i < s; i++){
                int j = i + 1;
                cout << j << " ";
            }
            cout << f << " ";
        }
        cout << "\n";
    }
    else cout << "-1\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}