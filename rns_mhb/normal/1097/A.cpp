#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[20], t[20];
    scanf("%s", s);
    bool flag = 0;
    for(int i = 1; i <= 5; i ++) {
        scanf("%s", t);
        if(t[0] == s[0] || t[1] == s[1]) flag = 1;
    }
    if(flag) puts("YES");
    else puts("NO");
}