#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int now = -1;
    int mink = 0;
    set <char> q;
    q.insert('A');
    q.insert('I');
    q.insert('E');
    q.insert('U');
    q.insert('O');
    q.insert('Y');
    for (int i = 0; i < s.size(); i++) {
        if (q.find(s[i]) != q.end()) {
            mink = max(mink, i - now);
            now = i;
        }
    }
    mink = max(mink, (int) s.size() - now);
    cout << mink;
}