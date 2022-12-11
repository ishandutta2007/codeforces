#include <bits/stdc++.h>
using namespace std;
string s[110];
char ch;
int n, m, ans;
set <char> ss;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m >> ch;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++) {
        if (s[i][j] == ch) ss.insert(s[i][j - 1]);
        if (s[i][j - 1] == ch) ss.insert(s[i][j]);
    }
    for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (s[i][j] == ch) ss.insert(s[i - 1][j]);
        if (s[i - 1][j] == ch) ss.insert(s[i][j]);
    }
    if (ss.find(ch) != ss.end()) ss.erase(ch);
    if (ss.find('.') != ss.end()) ss.erase('.');

    cout << ss.size();
}