#include <bits/stdc++.h>
using namespace std;

char s[1000001];

int main() {
  //  freopen("1.in", "r", stdin);
    scanf("%s", s);
    int n = strlen(s);
    int i;
    for(i = 0; i < n; i ++) if(s[i] != 'a') break;
    if(i == n) {
        for(int i = 1; i < n; i ++) printf("a");puts("z");
        return 0;
    }
    for(int j = i; j < n; j ++) {
        if(s[j] == 'a') break;
        s[j] = (s[j] - 'a' + 25) % 26 + 'a';
    }
    puts(s);
}