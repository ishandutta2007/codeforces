#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

char s[N] , t[N];
int a[N] , b[N];

void work() {
    int i;
    scanf("%s%s" , s , t);
    for (i = 0 ; s[i] ; ++ i) {
        if (islower(s[i]))
            ++ a[s[i] - 'a'];
        else
            ++ a[s[i] - 'A' + 26];
    }
    for (i = 0 ; t[i] ; ++ i) {
        if (islower(t[i]))
            ++ b[t[i] - 'a'];
        else
            ++ b[t[i] - 'A' + 26];
    }
    int res1 = 0 , res2 = 0;
    for (i = 0 ; i < 26 ; ++ i) {
        int x = min(a[i] , b[i]);
        res1 += x;
        a[i] -= x , b[i] -= x;
        x = min(a[i + 26] , b[i + 26]);
        res1 += x;
        a[i + 26] -= x , b[i + 26] -= x;
        x = min(a[i] , b[i + 26]);
        res2 += x;
        a[i] -= x , b[i + 26] -= x;
        x = min(b[i] , a[i + 26]);
        res2 += x;
        b[i] -= x , a[i + 26] -= x;       
    }
    printf("%d %d\n" , res1 , res2);
    
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}