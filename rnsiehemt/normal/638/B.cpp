#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 105;

int n, offset[maxn];
char t[99];
std::string s[maxn];
bool seen[maxn];
std::map<int, char> m;

void go(int i) {
    seen[i] = true;
    for (int ii = 0; ii < sz(s[i]); ii++) m[offset[i] + ii] = s[i][ii];
    for (int j = 0; j < n; j++) if (!seen[j]) {
        for (int ii = 0; ii < sz(s[i]); ii++) for (int jj = 0; jj < sz(s[j]); jj++) {
            if (!seen[j] && s[i][ii] == s[j][jj]) {
                offset[j] = offset[i] + ii - jj;
                go(j);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf(" %s", t); s[i] = t; }
    for (int i = 0; i < n; i++) if (!seen[i]) {
        go(i);
        for (auto &it : m) printf("%c", it.second);
        m.clear();
    }
    printf("\n");
}