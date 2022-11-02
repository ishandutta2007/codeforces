#include <bits/stdc++.h>
using namespace std;

#define N 1010

int t;
char s[N];

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%s", s);
        int i = 0, len = strlen(s);
        for (; i < len; i ++)
            if (s[i] != s[0]) break;
        if (i == len) puts("-1");
        else swap(s[i], s[len-1]), puts(s);
    }
}