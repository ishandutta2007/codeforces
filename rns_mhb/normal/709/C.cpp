#include<bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
    scanf("%s", s);
    int len = strlen(s), i;
    for(i = 0; i < len && s[i] == 'a'; i ++);
    if(i == len) {
        s[len - 1] = 'z';
        puts(s);
        return 0;
    }
    for(; i < len && s[i] > 'a'; i ++) s[i] -= 1;
    puts(s);
    return 0;
}