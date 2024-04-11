#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
char str[N];
int n;

int main() {
    scanf("%s" , str);
    n = strlen(str);
    str[n] = 'b';
    for (int i = 0 ; i < n ; ++ i) {
        printf("%d%c" , str[i] != str[i + 1] , " \n"[i + 1 == n]);
    }
}