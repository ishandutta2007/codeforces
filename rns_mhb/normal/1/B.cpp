#include <bits/stdc++.h>
using namespace std;
#define N 100

int n, r, c, len, num[4];
char s[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d\n", &n);
    while (r = c = 0, n --) {
        gets(s), len = strlen(s);
        int i, j;
        for (i = 1, j = 0; i < len; i ++)
            if (isalnum(s[i-1]) ^ isalnum(s[i])) num[j++] = i;
        if (j == 1) {
            for (int i = 0; i < num[0]; i ++) c = c * 26 + s[i] - 'A' + 1;
            for (int i = num[0]; i < len; i ++) r = r * 10 + s[i] - '0';
            printf("R%dC%d\n", r, c);
        }
        else {
            for (int i = 1; i < num[1]; i ++) r = r * 10 + s[i] - '0';
            for (int i = num[2]; i < len; i ++) c = c * 10 + s[i] - '0';
            stack <char> st;
            while (c) {
                st.push((c - 1) % 26 + 'A');
                c = (c - 1) / 26;
            }
            while (!st.empty()) putchar(st.top()), st.pop();
            printf("%d\n", r);
        }
    }

    return 0;
}