#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
int n , m;
char str[N];
int s[N][26];
int main() {
    scanf("%d%s%d" , &n , str , &m);
    for (int i = 0 ; i < n ; ++ i) {
        memcpy(s[i + 1] , s[i] , sizeof(s[i]));
        ++ s[i + 1][str[i] - 'a'];
    }
    for (int i = 0 ; i < m ; ++ i) {
        char com[2];
        int w;
        scanf("%d%s" , &w , com);
        int id = *com - 'a' , res = w;
        for (int i = 1 , j = 0 ; i <= n ; ++ i) {
            while (i - j - (s[i][id] - s[j][id]) > w) {
                ++ j;
            }
            res = max(res , i - j);
        }
        printf("%d\n" , res);
    }
}