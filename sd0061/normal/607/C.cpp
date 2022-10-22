#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000005;
const int Q = 1e9 + 7;
typedef long long LL;

int n , f[N];
char s[N] , t[N];

int main() {
    scanf("%d" , &n); -- n;
    scanf("%s%s" , s , t);
    reverse(s , s + n);
    for (int i = 0 ; i < n ; ++ i) {
        if (s[i] == 'N') s[i] = 'S';
        else if (s[i] == 'S') s[i] = 'N';
        else if (s[i] == 'E') s[i] = 'W';
        else s[i] = 'E';
    }
    
    for (int i = 1; i < n ; ++ i) {
        int j = f[i];
        while (j && s[i] != s[j])
            j = f[j];
        f[i + 1] = (s[i] == s[j]) ? j + 1 : 0;
    }
    int j = 0;
    for (int i = 0; i < n ; ++ i) {
        while (j && s[j] != t[i])
            j = f[j];
        if (s[j] == t[i]) ++ j;
    }
    puts(j ? "NO" : "YES");
    return 0;
}