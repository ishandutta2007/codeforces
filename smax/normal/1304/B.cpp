#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<string> v;
    unordered_set<string> st;
    map<string, int> p;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        string r = s;
        reverse(r.begin(), r.end());
        if (st.count(r)) {
            v.push_back(s);
            st.erase(r);
        } else if (r == s)
            p[s]++;
        else {
            st.insert(s);
        }
    }

    string ret;
    for (string s : v)
        ret += s;
    for (auto s : p) {
        if (s.second > 1)
            ret += s.first;
    }
    for (auto s : p)
        if (s.second == 1) {
            ret += s.first;
            break;
        }
    for (auto it=p.rbegin(); it!=p.rend(); it++)
        if (it->second > 1)
            ret += it->first;
    for (int i=v.size()-1; i>=0; i--) {
        reverse(v[i].begin(), v[i].end());
        ret += v[i];
    }
    cout << ret.length() << "\n" << ret << "\n";

    return 0;
}