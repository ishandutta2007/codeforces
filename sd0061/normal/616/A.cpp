#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;
char a[N] , b[N];
void work() {
    scanf("%s%s" , a , b);
    char *A = a , *B = b;
    while (*A == '0')
        ++ A;
    while (*B == '0')
        ++ B;
    int n = strlen(A) , m = strlen(B);
    if (n != m) {
        putchar("<>"[n > m]);
    } else {
        int t = strcmp(A , B);
        if (t < 0) putchar('<');
        if (t == 0) putchar('=');
        if (t > 0) putchar('>');        
    }
}

int main() {
    work();
    return 0;
}