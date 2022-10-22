#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
int n;
char str[N];

void work() {
    scanf("%d%s",&n , str + 1);
    int i , j , k;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; i + j * 4 <= n ; ++ j) {
            for (k = 0 ; k <= 4 ; ++ k)
                if (str[i + k * j] == '.')
                    break;
            if (k > 4) {
                puts("yes");
                return;
            }
        }
    }
    puts("no");    
}

int main() {    
    work();    
    return 0;
}