#include <iostream>
using namespace std;
const int N = 100000+10;
int n, k;
char s[N];
int a[30];
int main() {
    scanf("%d %d %s", &n, &k, s+1);
    for (int i = 1; i <= n; i ++) 
        a[s[i]-'a'] = 1;
    
    int fi = -1;
    for (int i = 25; i >= 0; i --) 
        if (a[i]) fi = i;
    
    if (k > n) {
        for (int i = n+1; i <= k; i ++)
            s[i] = 'a'+fi;
        s[k+1] = '\0';
        printf("%s\n", s+1);
        return 0;
    }
    for (int i = min(n, k); i >= 1; i --) {
        for (int j = s[i]-'a'+1; j < 26; j ++) {
            if (a[j]) {
                //printf("%d %d\n", i, j);
                s[i] = 'a'+j;
                for (int t = i+1; t <= k; t ++) s[t] = 'a'+fi;
                s[k+1] = '\0';
                printf("%s\n", s+1);return 0;
            }
        }
    }
}