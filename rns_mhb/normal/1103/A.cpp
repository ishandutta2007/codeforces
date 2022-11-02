#include<bits/stdc++.h>
using namespace std;

char s[1010];

int main() {
    scanf("%s", s);
    int x = 1, y = 0;
    for(int i = 0; s[i]; i ++) {
        if(s[i] == '0') {
            y ++;
            printf("2 %d\n", y);
            y %= 4;
        }
        else {
            printf("1 %d\n", x);
            x = (x + 2) % 4;
        }
    }
}