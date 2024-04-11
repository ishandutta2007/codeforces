#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int n,m;

char s[102][102];
double dp[1<<21];

int mask=0; 
int nod[102],ch[2002][1002],sz[100002],tot;
int id(char c) {
    return c;
}

void insert(int now,char c) {
    if (ch[now][id(c)] == 0) {
        ch[now][id(c)] = ++ tot; sz[tot] ++;
    } else {
        sz[ch[now][id(c)]] ++;
    }
}
void erase(int now,char c) {
    sz[ch[now][id(c)]] --; 
    if(sz[ch[now][id(c)]] == 0) ch[now][id(c)] = 0; 
}

void dfs(int dep) {
    if(dep == m+1) {
        int tot=0;
        for(int i=1;i<=n;i++) {
            if(sz[nod[i]] == 1) ++tot;
        }
        dp[mask] = 1.0 * tot / n;
        return;
    }
   
    int g[102],tmp;

    tmp = tot; 
    for(int i=1;i<=n;i++) {
        g[i] = nod[i]; 
        insert(nod[i], s[i][dep]);  
        nod[i] = ch[nod[i]][id(s[i][dep])];
    }
    mask ^= 1<<(dep-1);
   
    dfs(dep+1);
    
    mask ^= 1<<(dep-1);
    tot = tmp;

    for(int i=1;i<=n;i++) {
        nod[i] = g[i]; 
        erase(nod[i], s[i][dep]);
    }

    dfs(dep+1);
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%s", s[i]+1);
        //for(int j=1;j<=20;j++) s[i][j] = rand()%2 + 'a';
    }
    if (n == 1) {
        return !printf("0\n");
    }
    m = strlen(s[1] + 1);
    dfs(1);

    int v[102]={0};
    for(int i=0;i<1<<m;i++) {
        int c=0; for(int j=0;j<m;j++) if(i>>j&1) c++;
        v[c]++;
    }
    double ans = 0;
    for(int i=0;i<1<<m;i++) {
        int c=0; for(int j=0;j<m;j++) if(i>>j&1) c++;
        ans += (1-dp[i]) / v[c];
    }
    printf("%.12f\n", ans);

}