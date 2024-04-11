#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ct = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    string s;
    cin >> s;
    cout << ct[s[0] - '0'] * ct[s[1] - '0'] << endl;
}