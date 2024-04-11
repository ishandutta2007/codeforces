#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    string s;
    cin >> s;
    s += 'W';
    int prev = -1;
    vector <int> ans;
    if (s[0] == 'W') prev = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W' && s[i - 1] == 'B') {
            ans.push_back(i - prev - 1);
        }
        if (s[i] == 'W') {
            prev = i;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

}