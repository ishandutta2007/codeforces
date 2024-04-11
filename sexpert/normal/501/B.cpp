#include <bits/stdc++.h>
using namespace std;

map<string, string> change;
set<string> seen;
vector<string> src;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        if(!seen.count(s))
            src.push_back(s);
        seen.insert(t);
        change[s] = t;
    }
    cout << src.size() << endl;
    for(auto s : src) {
        string t = s;
        cout << t << " ";
        while(change.count(t))
            t = change[t];
        cout << t << endl;
    }
}