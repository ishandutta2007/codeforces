#include <bits/stdc++.h>
using namespace std;

#define N 2020

char s[N];

int main() {
    scanf("%s", s);
    printf("%s", s);
    reverse(s, s + strlen(s));
    puts(s);

    return 0;
}