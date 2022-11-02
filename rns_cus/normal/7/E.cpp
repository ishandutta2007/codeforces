#include <bits/stdc++.h>
using namespace std;

#define N 111

map <string, int> mp;

char s[N][N];
char t[N];

int solve(string s) {
    char b = 0, d = 0, x = 0;
    string p;
    for (char c : s + '.') {
        if (c == '(') b ++;
        if (c == ')') b --;
        if (!b) x |= ((c == '+' || c == '-') << 1) ^ (c == '*' || c == '/');
        if (isalpha(c) || c == ' ' || isdigit(c)) {
            if (isalpha(c)) p += c;
            continue;
        }
        if (p != "") {
            int r = mp[p];
            if (r > 1 && (d == '*' || d == '-' || c == '*' || c == '/') || r && d == '/' || r > 3) x = 4;
            p = "";
        }
        d = c;
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf(" # %s %s ", t, t);
        gets(s[i]);
        mp[t] = solve(s[i]);
    }
    gets(t);
    puts(solve(t) < 4 ? "OK" : "Suspicious");

    return 0;
}