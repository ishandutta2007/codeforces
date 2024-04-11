#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[150];
    int i = 0, t = 0, e = 0, n = 0, j;
    scanf("%s", s);
    for(j = 0; j < strlen(s); j ++) {
        if(s[j] == 'n') n ++;
        if(s[j] == 'e') e ++;
        if(s[j] == 't') t ++;
        if(s[j] == 'i') i ++;
    }
    n --;
    int rlt = n / 2;
    rlt = min(rlt, i);
    rlt = min(rlt, t);
    rlt = min(rlt, e / 3);
    printf("%d\n", rlt);
}