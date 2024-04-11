#include <cstdio>
#include <cstring>

const int MAXN = 104;
char p[MAXN];
char h[MAXN];
int s[26];

int main(){
    int T;
    int i0 = 0;
    scanf("%d", &T);
    for(i0 = 0; i0 < T; i0++){
        int i, j, k;
        int n, m;
        bool ans = false;
        scanf("%s%s", p, h);
        n = strlen(p);
        m = strlen(h);
        if(n <= m) {
            memset(s, 0, sizeof s);
            for(i = 0; i < n; i++)
                s[p[i]-'a']++;
            
            for(i = 0; i < n; i++)
                s[h[i]-'a']--;
            for(i = n; i <= m; i++) {
                for(j = 0; j < 26; j++)
                    if(s[j])
                        break;
                if(j == 26) {
                    ans = true;
                    break;
                }
                if(i == m)
                    break;
                s[h[i]-'a']--;
                s[h[i-n]-'a']++;
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}