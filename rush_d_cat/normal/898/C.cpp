#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<string, int> mp;
vector<string> v[22];
set<string> ans[22];
string str[22];

int n, x, cnt; 
string name;
string num;

bool is_suf(string a, string b) {
    if (a.length() >= b.length()) return 0;
    for (int i = 0; i < a.length(); i ++) {
        if (a[i] != b[i+b.length()-a.length()]) return 0;
    }
    return 1;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> name >> x;
        if (mp[name] == 0) {
            mp[name] = ++cnt;
            str[cnt] = name;
        }
        for (int j = 1; j <= x; j ++) {
            cin >> num; 
            v[mp[name]].push_back(num);
        }
    }

    for (int i = 1; i <= cnt; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            bool ok = 1;
            for (int k = 0; k < v[i].size(); k ++) {
                if (v[i][j].length() != v[i][k].length()) {
                    if (is_suf(v[i][j], v[i][k]))
                        ok = 0;
                }
            }
            if (ok) ans[i].insert(v[i][j]);
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i ++) {
        cout << str[i] << " " << ans[i].size();
        for (set<string>::iterator it = ans[i].begin(); it != ans[i].end(); it ++) {
            cout << " " << *it;
        }
        cout << endl;
    }
}