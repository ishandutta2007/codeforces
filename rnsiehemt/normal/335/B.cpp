#include <cstdio>
#include <cstring>
#include <algorithm>

int N;
char s[50010];
int c[30];
int dp[2605][2605];
char t[105];

int main()
{
    scanf("%s", s); N = strlen(s);
    if (N > 2600) {
        for (int i = 0; i < N; i++) c[s[i]-'a']++;
        for (int j = 0; j < 26; j++) {
            if (c[j] >= 100) {
                for (int k = 0; k < 100; k++) printf("%c", 'a'+j);
                return 0;
            }
        }
    }
    else {
        for (int b = 0; b < N; b++) dp[b][b+1] = 1; 
        for (int l = 2; l <= N; l++) {
            for (int b = 0; b+l <= N; b++) {
                dp[b][b+l] = std::max(dp[b+1][b+l], dp[b][b+l-1]);
                if (s[b] == s[b+l-1]) dp[b][b+l] = std::max(dp[b][b+l], dp[b+1][b+l-1]+2);
            }
        }
        t[std::min(dp[0][N], 100)] = '\0';
        int b = 0, e = N;
        int x = 0, y = std::min(dp[0][N], 100)-1;
        int c = 0;
        while (c < 100 && b < e) {
            if (b+1 == e) {
                t[x++] = s[b++];
                c++;
            }
            else if (s[b] == s[e-1]) {
                t[x++] = s[b++]; t[y--] = s[(e--)-1];
                c += 2;
            }
            else if (dp[b][e-1] > dp[b+1][e]) {
                e--;
            }
            else {
                b++;
            }
        }
        printf("%s\n", t);
    }
}