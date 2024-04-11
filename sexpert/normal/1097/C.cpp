#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ends;
    multiset<int> starts;
    int valid = 0;
    for(int i = 0; i < n; i++) {
        int mn = 0, cn = 0;
        string s;
        cin >> s;
        for(auto c : s) {
            if(c == '(')
                cn++;
            else
                cn--;
            mn = min(mn, cn);
        }
        if(mn == 0) {
            if(cn == 0)
                valid++;
            else
                starts.insert(cn);
        }
        else {
            if(mn < cn)
                continue;
            ends.push_back(-cn);
        }
    }    
    int ans = valid/2;
    for(auto e : ends) {
        auto it = starts.lower_bound(e);
        if(it != starts.end() && *it == e) {
            ans++;
            starts.erase(it);
        }
    }
    cout << ans << endl;
}