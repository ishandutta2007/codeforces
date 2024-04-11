#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n;
char str[N];

void work() {
    scanf("%s" , str);
    n = strlen(str);
    int i , l = -1 , r;
    for (i = 0 ; i < n ; ++ i) {
        if (~(str[i] - '0') & 1) {
            l = i;
            break;
        }
    }
    for (i = 0 ; i < n ; ++ i) {
        if (~(str[i] - '0') & 1) {
            r = i;
        }
    }
    if (!~l)
        puts("-1");
    else {
        for (i = 0 ; i < n ; ++ i) {
            if (~(str[i] - '0') & 1) {
                if (str[n - 1] > str[i]) {
                    swap(str[n - 1] , str[i]);
                    break;
                }
            }
        }
        if (i >= n)
            swap(str[n - 1] , str[r]);
        puts(str);
    }
}
int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}