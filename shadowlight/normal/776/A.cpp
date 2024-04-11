#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin.tie(0);
    cin >> s1 >> s2;
    int n;
    cin >> n;
    cout << s1 << " " << s2 << endl;
    for (int i = 0; i < n; i++) {
        string s3, s4;
        cin >> s3 >> s4;
        if (s3 == s2) {
            cout << s1 << " " << s4 << endl;
            s2 = s4;
        } else if (s3 == s1) {
            cout << s2 << " " << s4 << endl;
            s1 = s4;
        } else if (s4 == s1) {
            cout << s2 << " " << s3 << endl;
            s1 = s3;
        } else {
            cout << s1 << " " << s3 << endl;
            s2 = s3;
        }
    }
}