#include <bits/stdc++.h>
using namespace std;

char s[1010];
bool fg[2];

int main() {
    scanf("%s", s);
    for (int i = 0; s[i]; i ++) {
        if (s[i] == '0') {
            if (fg[0]) puts("1 1");
            else puts("3 1");
            fg[0] ^= 1;
        }
        else {
            if (fg[1]) puts("1 1");
            else puts("1 3");
            fg[1] ^= 1;
        }
    }
}