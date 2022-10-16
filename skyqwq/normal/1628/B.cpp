// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, c3[26][26][26], c2[26][26];

string s[N];

void inline work() {
    for (int i = 1; i <= n; i++) {
        if (s[i].size() == 1) {
            puts("YES");
            return;
        }
        if (s[i].size() == 2) {
            if (s[i][0] == s[i][1]) {
                puts("YES");
                return;
            }
            c2[s[i][0] - 'a'][s[i][1] - 'a'] = 1;
            if (c2[s[i][1] - 'a'][s[i][0] - 'a']) {
                puts("YES");
                return;
            }
            for (int j = 0; j < 26; j++) {
                if (c3[s[i][1] - 'a'][s[i][0] - 'a'][j]) {
                    puts("YES");
                    return;
                }   
            }
        }
        if (s[i].size() == 3) {
            c3[s[i][0] - 'a'][s[i][1] - 'a'][s[i][2] - 'a'] = 1;
            if (c3[s[i][2] - 'a'][s[i][1] - 'a'][s[i][0] - 'a']) {
                puts("YES");
                return;
            }
            if (c2[s[i][2] - 'a'][s[i][1] - 'a']) {
                puts("YES");
                return;
            }   
        }
    }
    puts("NO");
}
 
int main() {
    int T; read(T);
    while (T--) {
        memset(c3, 0, sizeof c3);
        memset(c2, 0, sizeof c2);
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> s[i];
        work();
    }
    return 0;
}