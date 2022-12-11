#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

typedef long double ld;
typedef long long ll;

void f(string& s) {
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '0') {
            s[i] = 'o';
        }
        if (s[i] == '1') {
            s[i] = 'l';
        }
        if (s[i] == 'i') {
            s[i] = 'l';
        }
        if (s[i] == 'I') {
            s[i] = 'l';
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

int main() {
    string s;
    cin >> s;
    f(s);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == s) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}