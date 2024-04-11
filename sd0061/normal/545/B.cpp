#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
char s[N] , t[N] , p[N];
void work() {
    scanf("%s%s" , s , t);
    int cnt = 0;
    for (int i = 0 ; s[i] ; ++ i) {
        if (s[i] == t[i])
            p[i] = s[i];
        else {
            ++ cnt;
            p[i] = s[i] ^ (cnt & 1);
        }
    }
    if (cnt & 1)
        puts("impossible");
    else
        puts(p);
}
int main() {
    work();
    return 0;
}