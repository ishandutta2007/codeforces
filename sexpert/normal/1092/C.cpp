#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int>> v;
int n;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.first.length() < b.first.length();
}

string check(string s) {
    string ret = "";
    for(int i = 0; i < 2*n - 2; i++)
        ret += '.';
    for(int len = 1; len <= n - 1; len++) {
        if(s.substr(0, len) == v[2*len - 2].first && s.substr(n - len, len) == v[2*len - 1].first) {
            ret[v[2*len - 2].second] = 'P';
            ret[v[2*len - 1].second] = 'S';
            continue;
        }
        if(s.substr(0, len) == v[2*len - 1].first && s.substr(n - len, len) == v[2*len - 2].first) {
            ret[v[2*len - 1].second] = 'P';
            ret[v[2*len - 2].second] = 'S';
            continue;
        }
        return "*";
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < 2*n - 2; i++) {
        string s;
        cin >> s;
        v.push_back(make_pair(s, i));
    }
    sort(v.begin(), v.end(), cmp);
    vector<string> cands = {v[2*n - 3].first + v[0].first, v[2*n - 3].first + v[1].first, v[2*n - 4].first + v[0].first, v[2*n - 4].first + v[1].first};
    for(string s : cands) {
        string ans = check(s);
        if(ans != "*") {
            cout << ans << endl;
            return 0;
        }
    }    
}