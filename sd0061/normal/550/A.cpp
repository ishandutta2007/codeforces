#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;

char s[N];
int n;
void work() {
    int i , L , R;
    scanf("%s" , s);
    n = strlen(s);
    L = R = -1;
    for (i = 1 ; i < n ; ++ i)
        if (s[i - 1] == 'A' && s[i] == 'B') {
            L = i;
            break;
        }
    for (i = 1 ; i < n ; ++ i)
        if (s[i - 1] == 'B' && s[i] == 'A') {
            R = i;
        }
    if (~L && ~R && abs(L - R) > 1) {       
        puts("YES");
        return;
    }
    L = R = -1;
    for (i = 1 ; i < n ; ++ i)
        if (s[i - 1] == 'B' && s[i] == 'A') {
            L = i;
            break;
        }
    for (i = 1 ; i < n ; ++ i)
        if (s[i - 1] == 'A' && s[i] == 'B') {
            R = i;
        }
    if (~L && ~R && abs(L - R) > 1) {       
        puts("YES");
        return;
    }
    puts("NO");
}

int main() {
    work();
    return 0;
}