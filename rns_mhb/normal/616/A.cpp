#include <bits/stdc++.h>
using namespace std;
#define N 1000100
#define gc getchar
#define pc putchar
#define pb push_back
#define X first
#define Y second
#define Mod(x) (((x) % mod + mod) % mod)
#define all(x) x.begin(), x.end()

const int inf = 1e9 + 7;
const double eps = 1e-7;
const double pi = 3.14159265358979323846264338327950288L;

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

char s[N+10], t[N+10];

void read(char *s) {
    gets(s);
    int len = strlen(s);
    for (int i = N; i >= 0; i --) {
        if (i >= N - len) s[i] = s[i-N+len];
        else s[i] = '0';
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    read(s), read(t);
    int c = strcmp(s, t);
    if (c > 0) puts(">");
    else if (c < 0) puts("<");
    else puts("=");

    return 0;
}