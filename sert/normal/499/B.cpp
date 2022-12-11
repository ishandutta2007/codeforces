#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
string s1, s2;
unordered_map <string, string> mp;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s1 >> s2;
        if (s2.length() < s1.length())
            mp[s1] = s2;
        else
            mp[s1] = s1;
    }
    for (int i = 0; i < n; i++) {
        cin >> s1;
        cout << mp[s1] << " ";
    }
}