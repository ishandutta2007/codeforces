#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
const int N = 100005;
const int Q = 1e9 + 7;
typedef long long LL;
using namespace std;
int n , T;
char s[N] , t[N] , p[N];

int main() {
    scanf("%d%d%s%s" , &n , &T , s , t);
    int diff = 0;
    for (int i = 0 ; i < n ; ++ i)
        if (s[i] != t[i])
            ++ diff;  
    int same = n - diff;
    int L = (diff + 1) / 2;
    int R = same + diff;
    if (L <= T && T <= R) {
        int x = min(T , diff);
        int y = T - x;
        int a = diff - x , b = diff - x , c = x - a;
        for (int i = 0 ; i < n ; ++ i) {
            if (s[i] == t[i]) {
                if (y) {
                    -- y;
                    for (int j = 0 ; j < 26 ; ++ j)
                        if (s[i] != 'a' + j && t[i] != 'a' + j) {
                            p[i] = 'a' + j;
                            break;
                        }
                } else {
                    p[i] = s[i];
                }
            } else {
                if (a) {
                    -- a;
                    p[i] = s[i];
                } else if (b) {
                    -- b;
                    p[i] = t[i];
                } else {
                    -- c;
                    for (int j = 0 ; j < 26 ; ++ j)
                        if (s[i] != 'a' + j && t[i] != 'a' + j) {
                            p[i] = 'a' + j;
                            break;
                        }
                }

            }

        }
        puts(p);
    } else {
        puts("-1");
    }
    
    return 0;
}