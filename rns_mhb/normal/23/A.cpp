#include<bits/stdc++.h>
using namespace std;

char s[105];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    for(int i = 0; i < n; i ++) for(int j = i + 1; j < n; j ++) {
        int d = 0;
        while(s[i+d] == s[j+d]) d ++;
        if(d > ans) ans = d;
    }
    printf("%d\n", ans);
}