#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , s[N] , w;

int main() {
    cin >> n;
    while (n --) {
        s[++ w] = 1;
        while (w > 1 && s[w] == s[w - 1]) {
            -- w;
            ++ s[w];
        }
    }
    for (int i = 1 ; i <= w ; ++ i)
        printf("%d%c" , s[i] , " \n"[i == w]);
    return 0;
}