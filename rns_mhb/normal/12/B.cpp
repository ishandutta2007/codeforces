#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[20], t[20];
    scanf("%s%s", s, t);
    int len = strlen(s), i, n;
    n = atoi(s);
    if(n == 0) {
        n = atoi(t);
        if(n == 0) {
            if(strlen(t) == 1) puts("OK");
            else puts("WRONG_ANSWER");
        }
        else puts("WRONG_ANSWER");
        return 0;
    }
    sort(s, s + len);
    for(i = 0; s[i] == '0'; i ++);
    swap(s[0], s[i]);
    if(strcmp(s, t) == 0) puts("OK");
    else puts("WRONG_ANSWER");
}