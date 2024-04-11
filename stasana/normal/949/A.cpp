#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int64_t ll;

int main() {
    string s;
    cin >> s;
    vector<int> res(s.length(), -1);
    queue<int> left, right;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            left.push(i);
        } else {
            if (left.empty()) {
                cout << -1;
                return 0;
            }
            res[left.front()] = i;
            left.pop();
        }
    }
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            right.push(i);
        } else {
            if (right.empty()) {
                cout << -1;
                return 0;
            } else {
                res[i] = right.front();
                right.pop();
            }
        }
    }
    vector<bool> used(s.length());
    vector<vector<int>> ans;
    for (int i = 0; i < s.length(); ++i) {
        if (!used[i]) {
            int v = i;
            used[v] = true;
            ans.push_back(vector<int>());
            ans.back().push_back(v);
            while (res[v] != -1) {
                v = res[v];
                used[v] = true;
                ans.back().push_back(v);
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}