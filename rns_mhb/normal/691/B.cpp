#include <bits/stdc++.h>
using namespace std;

#define N 1005
#define K 26

int n;
char s[N];
string a = "AHIMOoTUVvWwXxY";

bool sym(char c, char d) {
    if (c == 'b' && d == 'd') return 1;
    if (c == 'd' && d == 'b') return 1;
    if (c == 'p' && d == 'q') return 1;
    if (c == 'q' && d == 'p') return 1;
    if (c != d) return 0;
    for (int i = 0; i < a.size(); i ++) if (a[i] == c) return 1;
    return 0;
}

int main() {
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; i ++) {
        if (!sym(s[i], s[n-1-i])) return puts("NIE"), 0;
    }
    return puts("TAK"), 0;
}