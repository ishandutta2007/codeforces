#include <bits/stdc++.h>

using namespace std;

vector <int> str;

bool fl = 0;

void force(vector <int> &used, string &s) {
    if (s.size() == 4) {
        cout << s << endl;
        int x, y;
        cin >> x >> y;
        if (x == 4) {
            fl = 1;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (used[i]) continue;
        used[i] = 1;
        string s1 = s;
        s1 += (char) (str[i] + '0');
        force(used, s1);
        if (fl) return;
        used[i] = 0;
    }
}

int main() {
    int now = 0;
    for (int i = 0; i < 10; i++) {
        cout << i << i << i << i << endl;
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < x; j++) {
            str.push_back(i);
        }
    }
    vector <int> used(4, 0);
    string s = "";
    force(used, s);
}