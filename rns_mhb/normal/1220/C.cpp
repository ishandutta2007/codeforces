#include<bits/stdc++.h>
using namespace std;

#define N 500010

char s[N];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    puts("Mike");
    char mn = s[1];
    for(int i = 2; i <= n; i ++) {
        if(mn < s[i]) puts("Ann");
        else puts("Mike");
        mn = min(mn, s[i]);
    }
}