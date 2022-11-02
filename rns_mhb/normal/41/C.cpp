#include <bits/stdc++.h>
using namespace std;
#define N 110

char c, s[N], t[N];
bool fl = 1;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    gets(s);
    int len = strlen(s); t[0] = s[0];
    for (int i = 1, j = 1; i < len; i ++) {
        if (s[i] == 'a' && fl) {
            if (s[i+1] == 't') t[j++] = '@', i ++, fl = 0;
            else t[j++] = s[i];
        }
        else if (s[i] == 'd') {
            if (i + 3 < len && s[i+1] == 'o' && s[i+2] == 't') t[j++] = '.', i += 2;
            else t[j++] = s[i];
        }
        else t[j++] = s[i];
    }
    puts(t);

    return 0;
}