#include<bits/stdc++.h>
using namespace std;

char s[205];

int main() {
    scanf("%s", s);
    int last = -1;
    for(int i = 0; s[i]; i ++) {
        if(s[i] == '.') {
            printf("%d", i - last - 1);
            last = i;
        }
        if(i - last == 2) {
            putchar('2');
            last = i;
        }
    }
    return 0;
}