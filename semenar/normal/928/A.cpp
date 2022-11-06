#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void normalize_login(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 'a' - 'A';
        if (s[i] == '0') s[i] = 'o';
        if (s[i] == 'l' || s[i] == '1') s[i] = 'i';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string new_login;
    cin >> new_login;
    normalize_login(new_login);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string ex_login;
        cin >> ex_login;
        normalize_login(ex_login);
        if (new_login == ex_login) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}