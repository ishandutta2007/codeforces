//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int K = 10, mod = 1e9 + 7;
inline void upd(int &a, int b) {a = (a + b) % mod;}
inline int read()
{
    register char ch;
    while(!isdigit(ch=getchar()));
    register int x = ch ^ '0';
    while(isdigit(ch=getchar())) x = (x << 3) + (x << 1) + (ch ^ '0');
    return x;
}

int dp[2][(1<<K)+1];

int main()
{
    int n = read(), k = read() - 1;
    for(int i=dp[0][0]=1;i<=n;i++)
	{
        int x = read();
        fill(&dp[i&1][0], &dp[i&1][1<<k]+1, 0);
        for(int j=0;j<=(1<<k);j++)
		{
            if(x != 2) upd(dp[i&1][j&1?2:min(j+2,1<<k)], dp[(i&1)^1][j]);
            if(x != 4) upd(dp[i&1][min(j+1, 1<<k)], dp[(i&1)^1][j]);
        }
    }
    printf("%d\n", dp[n&1][1<<k]);
    return 0;
}