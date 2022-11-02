#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[20];
    scanf("%s%s%s", s, s + 3, s + 6);
    for(int i = 0; i < 5; i ++) if(s[i] != s[8 - i]) {puts("NO"); return 0;}
    puts("YES");
}