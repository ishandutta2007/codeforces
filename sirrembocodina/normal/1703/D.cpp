#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> s(n);
        set<string> ss;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            ss.insert(s[i]);
        }
        for (int i = 0; i < n; i++) {
            bool was = false;
            for (int len = 1; len < s[i].size(); len++) {
                if (ss.find(s[i].substr(0, len)) != ss.end() &&
                    ss.find(s[i].substr(len)) != ss.end()) {
                    was = true;
                    break;
                }
            }
            cout << int(was);
        }
        cout << '\n';
    }
}