#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

char colors[]={'R', 'G', 'B'};
char s[sz];

int dp[sz][4];
char ans[sz][4];

int rec(int pos, char pre, int n)
{
    if(pos==n) return 0;
    int x;
    for(x=0; x<3; x++) if(colors[x]==pre) break;
    if(dp[pos][x]!=-1) return dp[pos][x];
    int now=sz;
    for(int i=0; i<3; i++) {
        if(colors[i]==pre) continue;
        int z=rec(pos+1,colors[i],n);
        if(colors[i]!=s[pos]) z++;
        if(z<now) {
            now=z;
            ans[pos][x]=colors[i];
        }
    }
    return dp[pos][x]=now;
}

void trav(int pos, int x, int n)
{
    if(pos==n) return;
    printf("%c", ans[pos][x]);
    int z;
    for(z=0; colors[z]!=ans[pos][x]; z++) {}
    trav(pos+1,z,n);
}

int main()
{
    int i,j,n;
    cin >> n;
    scanf("%s", s);
    memset(dp, -1, sizeof(dp));
    int ans=rec(0,'x',n);
    printf("%d\n", ans);
    trav(0,3,n);
    puts("");
    return 0;
}