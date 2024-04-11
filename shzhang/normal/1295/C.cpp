#include <cstdio>
#include <cstring>

using namespace std;

char s[100005];
char t[100005];
int nxt[100005][26];
int tcur;

int work(void)
{
    scanf("%s", s + 1);
    int slen = strlen(s + 1);
    scanf("%s", t + 1);
    for (int i = 0; i < 26; i++) nxt[slen+1][i] = -1;
    for (int i = slen; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (s[i+1] == 'a' + j) {
                nxt[i][j] = i+1;
            } else {
                nxt[i][j] = nxt[i+1][j];
            }
        }
    }
    tcur = 1;
    int ans = 0;
    while (t[tcur]) {
        int chars = 0;
        int scur = 0;
        while (1) {
            scur = nxt[scur][t[tcur] - 'a'];
            if (scur == -1) break;
            chars++; tcur++;
            if (!t[tcur]) break;
        }
        if (!chars) return -1;
        ans++;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("%d\n", work());
    }
    return 0;
}