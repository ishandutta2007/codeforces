#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    bool fl = 0;
    cin >> n;
    vector <string> data(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (fl) {
            data[i] = s;
            continue;
        }
        if (s[0] == 'O' && s[1] == 'O') {
            s[0] = '+';
            s[1] = '+';
            fl = 1;
        } else if (s[3] == 'O' && s[4] == 'O') {
            s[3] = '+';
            s[4] = '+';
            fl = 1;
        }
        data[i] = s;
    }
    if (!fl) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << endl;
    }
}