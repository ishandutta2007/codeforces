#include <cstdio>

int N, K;
char s[200005];
int next = 1;
int child[200005][30];
bool end[200005];
bool seen[200005][2][2];
bool dp[200005][2][2];

bool win(int i, int p, bool aim) {
    if (!seen[i][p][aim]) seen[i][p][aim] = true;
    else return dp[i][p][aim];
    if (p == 0) {
        if (end[i]) return dp[i][p][aim] = !aim;
        else {
            for (int j = 0; j < 26; j++) {
                if (child[i][j] && win(child[i][j], 1, aim))
                    return dp[i][p][aim] = true;
            }
            return dp[i][p][aim] = false;
        }
    }
    else {
        if (end[i]) return dp[i][p][aim] = aim;
        else {
            for (int j = 0; j < 26; j++) {
                if (child[i][j] && !win(child[i][j], 0, aim))
                    return dp[i][p][aim] = false;
            }
            return dp[i][p][aim] = true;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf(" %s", s);
        int cur = 0;
        for (int j = 0; s[j]; j++) {
            if (!child[cur][s[j]-'a'])
                child[cur][s[j]-'a'] = next++;
            cur = child[cur][s[j]-'a'];
        }
    }
    for (int i = 0; i < 100003; i++) {
        end[i] = true;
        for (int j = 0; j < 26; j++)
            if (child[i][j])
                end[i] = false;
    }

    if (!win(0, 0, true)) printf("Second\n");
    else if (win(0, 0, false)) printf("First\n");
    else if (K%2 == 0) printf("Second\n");
    else printf("First\n");
}