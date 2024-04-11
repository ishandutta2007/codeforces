#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int dfs(vector<vector<int>>& a, int v) {
    int res = 0;
    for (size_t i = 0; i < a[v].size(); ++i) {
        res = max(res, dfs(a, a[v][i]));
    }
    return res + 1;
}

void f(string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> id;
    id.push_back("polycarp");
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2 >> s2;
        f(s1);
        f(s2);
        for (size_t j = 0; j < id.size(); ++j) {
            if (id[j] == s2) {
                a[j].push_back(id.size());
            }
        }
        id.push_back(s1);
    }
    cout << dfs(a, 0);
    return 0;
}