#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , K;
char t[N] , s[N];
int f[N] , pre[N] , suf[N];

void work() {
    int i , j;
    scanf("%s" , t);
    n = strlen(t);
    scanf("%d" , &K);
    int res = 0;
    while (K --) {
        scanf("%s", s);
        m = strlen(s);
        for (i = 1 ; i < m ; ++ i) {
            j = f[i];
            while (j && s[i] != s[j])
                j = f[j];
            f[i + 1] = (s[i] == s[j]) ? j + 1 : 0;
        }
        for (i = 0 ; i <= m ; ++ i) pre[i] = 1 << 30;
        for (i = 0 , j = 0 ; i < n ; ++ i) {
            while (j && t[i] != s[j])
                j = f[j];
            if (t[i] == s[j]) ++ j;
            pre[j] = min(pre[j] , i);
        }
        for (j = m ; j > 0 ; -- j)
            pre[f[j]] = min(pre[f[j]] , pre[j]);
        reverse(s , s + m);
        for (i = 1 ; i < m ; ++ i) {
            j = f[i];
            while (j && s[i] != s[j])
                j = f[j];
            f[i + 1] = (s[i] == s[j]) ? j + 1 : 0;
        }
        for (i = 0 ; i <= m ; ++ i) suf[i] = -1 << 30;
        for (i = n - 1 , j = 0 ; i >= 0 ; -- i) {
            while (j && t[i] != s[j])
                j = f[j];
            if (t[i] == s[j]) ++ j;
            suf[j] = max(suf[j] , i);
        }
        for (j = m ; j > 0 ; -- j)
            suf[f[j]] = max(suf[f[j]] , suf[j]);
        for (j = 1 ; j < m ; ++ j)
            if (pre[j] < suf[m - j]) {
                ++ res;
                break;
            }
    }
    cout << res << endl;
}


int main() {
    work();
    return 0;
}