#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
string s, t;
vector <string> a, b;

bool is_num(string t) {
    if (t.length() == 0)
        return false;
    if (t == "0")
        return true;
    if (t[0] == '0') return false;
    for (int i = 0; i < t.length(); i++)
        if (t[i] < '0' || t[i] > '9')
            return false;
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    s = s + ";";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ',' && s[i] != ';')
            t += s[i];
        else {
            if (is_num(t))
                a.push_back(t);
            else
                b.push_back(t);
            t.clear();
        }
    }

    if (a.size()) {
        cout << "\"";
        for (int i = 0; i < a.size(); i++) {
            if (i) cout << ",";
            cout << a[i];
        }
        cout << "\"\n";
    } else {
        cout << "-\n";
    }

    if (b.size()) {
        cout << "\"";
        for (int i = 0; i < b.size(); i++) {
            if (i) cout << ",";
            cout << b[i];
        }
        cout << "\"\n";
    } else {
        cout << "-\n";
    }



    return 0;
}