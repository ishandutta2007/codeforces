#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

char s[1005], r[256];
int n;

char rev(char c) {
    return r[c];
}

int main() {
    r['A'] = 'A';
    r['b'] = 'd';
    r['d'] = 'b';
    r['H'] = 'H';
    r['I'] = 'I';
    r['M'] = 'M';
    r['O'] = 'O';
    r['o'] = 'o';
    r['p'] = 'q';
    r['q'] = 'p';
    r['T'] = 'T';
    r['U'] = 'U';
    r['V'] = 'V';
    r['v'] = 'v';
    r['W'] = 'W';
    r['w'] = 'w';
    r['X'] = 'X';
    r['x'] = 'x';
    r['Y'] = 'Y';
    scanf(" %s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (rev(s[i]) != s[n-i-1]) {
            printf("NIE\n");
            return 0;
        }
    }
    printf("TAK\n");
}