#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 405;
const int M = 20005;

char s[N] , t[N];

void work() {
    scanf("%s%s" , s , t);
    int n = strlen(s);
    reverse(s , s + n);
    ++ s[0]; int i = 0;
    while (s[i] > 'z') {
        s[i] -= 26;
        ++ s[i + 1];
        ++ i;
    }
    reverse(s , s + n);
    if (strcmp(s , t) >= 0)
        puts("No such string");
    else
        puts(s);
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}