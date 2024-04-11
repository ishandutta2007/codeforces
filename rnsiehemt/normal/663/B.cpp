#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxl = 99;

int n;
char u[maxl], t[maxl];

int getint(std::string s) {
    int blah = 0;
    for (int i = 0; i < sz(s); i++) blah = blah * 10 + s[i] - '0';
    return blah;
}
int go(int i, int mod, int aim) {
    while (i % mod != aim) i++;
    return i;
}
void answer(int i) {
    printf("%d\n", i);
}
bool lessthan(const std::string &s, const std::string &t) {
    assert(sz(s) == sz(t));
    for (int i = 0; i < sz(s); i++) {
        if (s[i] < t[i]) return true;
        if (t[i] < s[i]) return false;
    }
    return false;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %s", t);
        for (int i = 4; i <= int(strlen(t)); i++) u[i-4] = t[i];
        std::string s = u;
        if (sz(s) == 1) {
            answer(go(1989, 10, getint(s)));
        } else if (sz(s) == 2) {
            answer(go(1999, 100, getint(s)));
        } else if (sz(s) == 3) {
            answer(go(2099, 1000, getint(s)));
        } else if (sz(s) == 4) {
            answer(go(3099, 10000, getint(s)));
        } else {
            std::string blah;
            for (int i = 5; i <= sz(s); i++) {
                blah += '1';
            }
            blah += "3099";
            if (lessthan(s, blah)) {
                s = '1' + s;
            }
            printf("%s\n", s.c_str());
        }
    }
}