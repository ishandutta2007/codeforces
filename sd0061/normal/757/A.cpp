#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "Bulbasaur";
    string s;
    cin >> s;
    map<char , int> a , b;
    for (auto c : str) {
        ++ a[c];
    }
    for (auto c : s) {
        ++ b[c];
    }
    int res = 1 << 30;
    for (auto it : a) {
        if (!b.count(it.first)) {
            res = 0;
        } else {
            res = min(res , b[it.first] / it.second);
        }
    }
    cout << res << endl;
}