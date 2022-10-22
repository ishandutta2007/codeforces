#include <bits/stdc++.h>
using namespace std;

char str[10101];

int main() {
    int i;
    scanf("%s", str);
    for (i=0; str[i]!=0; i++) printf("%c", str[i]);
    for (i--; i>=0; i--) printf("%c", str[i]);
    return 0;
}