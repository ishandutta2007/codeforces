#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , p[N];
bool f[N];
vector< pair<int , int> > res;

int main() {
    int n;
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &p[i]);
    }
    for (int i = 1 ; i <= n ; ++ i)
        if (i == p[i]) {
            puts("YES");
            for (int j = 1 ; j <= n ; ++ j)
                if (i != j)
                    printf("%d %d\n" , i , j);
            return 0;            
        }
    int x = -1 , y = -1;
    for (int i = 1 ; i <= n ; ++ i) {
        if (!f[i]) {
            int w = i;
            int len = 0;
            while (!f[w]) {
                ++ len;
                f[w] = 1;
                w = p[w];
            }
            if (len == 2) {
                x = w;
                y = p[w];
            } else if (len & 1) {
                puts("NO");
                return 0;
            }
        }
    }
    if (!~x) {
        puts("NO");
        return 0;
    }
    memset(f , 0 , sizeof(f));
    puts("YES");
    printf("%d %d\n" , x , y);
    f[x] = f[y] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        if (!f[i]) {
            int w = i;
            while (!f[w]) {
                printf("%d %d\n" , x  ,w);
                f[w] = 1;
                w = p[w];
                swap(x , y);
            }
        }
    }
    return 0;
}