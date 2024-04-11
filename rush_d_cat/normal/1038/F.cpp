#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 42;
int n,m; char s[N];
LL dp[N][N][2], nex[N];
void kmp_init() {
    int j=0;nex[1]=0;nex[0]=-1;
    for(int i=1;i<n;i++) {
        while(j>=0 && s[i+1]!=s[j+1]) j=nex[j];
        if(j==-1||s[i+1]==s[j+1]) j++; nex[i+1]=j;
        //printf("nex[%d]=%d\n", i+1,j);
    }
}
int getNex(int pos,int val) {
    if(pos==0) return val==s[1]-'0'?1:0;
    if(s[pos+1]=='0'+val) return pos+1;
    return getNex(nex[pos], val);
}
LL dfs(int pre,int now,int matched_len,int isok) {
    //printf("%d %d %d %d\n", pre,now,matched_len,isok);
    if(now==m+1) {
        return matched_len == pre && isok;
    }
    if(dp[now][matched_len][isok] != -1) return dp[now][matched_len][isok];
    LL ans = 0;
    ans += dfs(pre,now+1,getNex(matched_len,0),isok|(getNex(matched_len,0) == n));
    ans += dfs(pre,now+1,getNex(matched_len,1),isok|(getNex(matched_len,1) == n));
    return dp[now][matched_len][isok] = ans;
}
int main() {
    scanf("%d %s", &m, s+1);
    n = strlen(s+1);
    kmp_init();
    LL ans = 0;
    for(int i=0;i<=n;i++) {
        memset(dp,-1,sizeof(dp));
        ans += dfs(i,1,i,0);
    }
    cout << ans << endl;
}