#include<bits/stdc++.h>
using namespace std;

#define N 100010

char s[N];

int main() {
    scanf("%s", &s);
    int i = 0;
    while(s[i] == 'a') i ++;
    if(!s[i]) {
        s[i-1] = 'z';
        printf("%s\n", s);
        return 0;
    }
    for(int j = 0; j < i; j ++) putchar(s[j]);
    while(s[i] && s[i] != 'a') putchar(s[i] - 1), i ++;
    while(s[i]) putchar(s[i]), i ++;
}