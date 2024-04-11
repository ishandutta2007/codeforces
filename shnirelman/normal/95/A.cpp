#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < a[i].size(); j++) {
            if('A' <= a[i][j] && a[i][j] <= 'Z') {
                a[i][j] = a[i][j] - 'A' + 'a';
            }
        }
    }

    string s;
    cin >> s;

    string s1 = s;
    for(int j = 0; j < s.size(); j++) {
        if('A' <= s[j] && s[j] <= 'Z') {
            s[j] = s[j] - 'A' + 'a';
        }
    }

    char c;
    cin >> c;

//    cout << s << endl;

    vector<bool> b(s.size(), false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j + a[i].size() <= s.size(); j++) {
//            cout << i << ' ' << j << endl;
            if(s.substr(j, a[i].size()) == a[i]) {
                for(int k = j; k < j + a[i].size(); k++)
                    b[k] = true;
            }
        }
    }

    string t = "";
    for(int i = 0; i < s.size(); i++)
        t += (b[i] ? (c != s[i] ? c : (c != 'a' ? 'a' : 'b')) : s[i]);

//    cout << t << endl;

    for(int i = 0; i < s.size(); i++) {
        cout << ('a' <= s1[i] && s1[i] <= 'z' ? t[i] : char(t[i] - int('a') + 'A'));
    }
}