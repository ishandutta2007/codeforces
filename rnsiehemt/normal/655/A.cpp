#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

char s[2][4], t[2][4];
std::vector<char> v, w;

int main() {
    scanf(" %s %s %s %s", s[0], s[1], t[0], t[1]);
    s[0][3] = s[1][0];
    s[0][2] = s[1][1];
    t[0][3] = t[1][0];
    t[0][2] = t[1][1];
    int i;
    for (i = 0; s[0][i] != 'A'; i++);
    for (int j = i; j < i+4; j++) if (s[0][j%4] != 'X') v.pb(s[0][j%4]);
    for (i = 0; t[0][i] != 'A'; i++);
    for (int j = i; j < i+4; j++) if (t[0][j%4] != 'X') w.pb(t[0][j%4]);
    for (int i = 0; i < 3; i++) if (v[i] != w[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}