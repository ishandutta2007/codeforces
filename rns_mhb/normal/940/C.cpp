#include <bits/stdc++.h>
using namespace std;

#define N 100005

template <class T> void chkmax(T &a, T b) { if (a < b) a = b; }
template <class T> void chkmin(T &a, T b) { if (a > b) a = b; }

int n, k;
char s[N];
char mn, mx;

bool vis[N];

int main() {
    scanf("%d %d ", &n, &k);
    gets(s);
    mn = 'z' + 1;
    mx = 'a' - 1;
    for (int i = 0; i < n; i ++) {
        chkmin(mn, s[i]);
        chkmax(mx, s[i]);
        vis[s[i]-'a'] = 1;
    }
    if (n < k) {
        printf("%s", s);
        for (int i = 0; i < k - n; i ++) putchar(mn);
    }
    else {
        int i = k - 1;
        while (s[i] == mx) i --;
        char t = s[i];
        t ++;
        while (!vis[t-'a']) t ++;
        s[i] = t;
        for (int j = i + 1; j < k; j ++) s[j] = mn;
        for (int i = 0; i < k; i ++) putchar(s[i]);
    }
	return 0;
}