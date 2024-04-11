#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pp;
 
bool solve() {
    string s, t;
    cin >> s >> t;
    vector<pp> cs, ct;
    int cnt = 0;
    char cc = s[0];
    for(int i = 0; i < s.size(); i++) {
        if(i && s[i] != s[i - 1]) {
            cs.push_back(pp{cc, cnt});
            cnt = 0;
            cc = s[i];
        }
        cnt++;
    }
    cs.push_back(pp{cc, cnt});
    cnt = 0;
    cc = t[0];
    for(int i = 0; i < t.size(); i++) {
        if(i && t[i] != t[i - 1]) {
            ct.push_back(pp{cc, cnt});
            cnt = 0;
            cc = t[i];
        }
        cnt++;
    }
    ct.push_back(pp{cc, cnt});
    if(cs.size() != ct.size()) return false;
    for(int i = 0; i < cs.size(); i++) {
        if(cs[i].first != ct[i].first || cs[i].second > ct[i].second) return false;
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    while(n--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}