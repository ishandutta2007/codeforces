#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const ll Mod = 1000*1000*1000+7;

int N, M;
char s[100005];
ll dp[2005][2][2005];

int v(char c) {
    return (c == '(' ? 1 : -1);
}
void add(ll &a, ll b) {
    a += b;
    if (a >= Mod) a -= Mod;
}

int main()
{
    scanf("%d%d %s", &N, &M, s);
    int c = 0, min = 0;
    for (int i = 0; i < M; i++) {
        c += v(s[i]);
        domin(min, c);
    }
    if (c > 2003) {
        printf("0\n");
        return 0;
    }
    
    N = N-M+1;

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2002; j++) {
            if (j) {
                add(dp[i+1][0][j-1], dp[i][0][j]);
                add(dp[i+1][1][j-1], dp[i][1][j]);
            }
            add(dp[i+1][0][j+1], dp[i][0][j]);
            add(dp[i+1][1][j+1], dp[i][1][j]);
            if (j+min >= 0) add(dp[i+1][1][j+c], dp[i][0][j]);
        }
    }
    printf("%lld\n", dp[N][1][0]);
}