#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[20];
    while(1) {
        scanf("%s", s); assert(strcmp(s, "start") == 0 || strcmp(s, "end") == 0);
        if(s[0] == 's') {
            int X = 1;
            while(1) {
                printf("? %d %d\n", X, 2 * X); fflush(stdout);
                scanf("%s", s); assert(s[0] != 'e');
                if(s[0] == 'x') break;
                else X <<= 1;
            }
            if(X == 1) {
                printf("? %d %d\n", 2, 1); fflush(stdout);
                scanf("%s", s); assert(s[0] != 'e');
                printf("! %d\n", 1 + (s[0] == 'y')); fflush(stdout);
            }
            else {
                int P = 2 * X, xx = X;
                while(X > 1) {
                    X >>= 1;
                    int M = P - X;
                    printf("? %d %d\n", xx, M); fflush(stdout);
                    scanf("%s", s); assert(s[0] != 'e');
                    if(s[0] == 'x') P -= X;
                }
                printf("! %d\n", P); fflush(stdout);
            }
            continue;
        }
        else break;
    }
}