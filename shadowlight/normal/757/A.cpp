#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    map <char, int> data;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        data[x]++;
    }
    cout << min({data['B'], data['u'] / 2, data['l'], data['b'], data['a'] / 2, data['s'], data['r']});
}