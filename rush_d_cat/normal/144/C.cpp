#include <cstring>
#include <cstdio>
using namespace std;
const int NICO = 100000+10;
char s[NICO], p[NICO];
int cnt[4000], pat[4000];
int main() 
{
    scanf("%s", s+1);
    scanf("%s", p+1);
    int n = strlen(s + 1);
    int m = strlen(p + 1);

    if(m > n) {
        printf("0\n");
        return 0;
    }

    for(int i = 1; i <= m; i++) {
        pat[p[i] - 'a'] ++;
        cnt[s[i] - 'a'] ++;
    }
    
    int ans = 0;
    for(int i = 1; i <= n - m + 1; i++) {
        int ok = 1;
        for(int j = 0; j < 26; j ++) {
            if(cnt[j] > pat[j]) {
                ok = 0;
            }
        }
        if(ok) ans ++; 
        cnt[s[i] - 'a'] --;
        cnt[s[i + m] - 'a'] ++;
    }       
    printf("%d\n", ans);
}