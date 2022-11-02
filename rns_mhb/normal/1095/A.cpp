#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char s[100];
    scanf("%d%s", &n, s + 1);
    for(int i = 1, j = 1; i <= n; i += j ++) putchar(s[i]);
    puts("");
}