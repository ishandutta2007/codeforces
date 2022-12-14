#include <bits/stdc++.h>

using namespace std;

char s[100005];
int ans , c1 , c2 , n;

int main(){
    scanf("%d%s" , &n , s + 1);
    for (int i = 1 ; i <= n ; i ++) {
        if (i & 1) {
            if (s[i] != 'r') c1 ++ ;
        }
        else if (s[i] != 'b') c2 ++;
    }
    ans = abs(c1 - c2) + min(c1 , c2);
    c1 = c2 = 0;
    for (int i = 1 ; i <= n ; i ++) {
        if (i & 1) {
            if (s[i] != 'b') c1 ++ ;
        }
        else if (s[i] != 'r') c2 ++;
    }
    ans = min(ans , abs(c1 - c2) + min(c1 , c2));
    printf("%d\n", ans);
    return 0;
}