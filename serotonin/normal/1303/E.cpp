#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=405;

int ns, nt, m;
char s[sz], t[sz];

bool vis[sz][sz];
int last[sz][30], dp[sz][sz];

int fnc(int x, int y)
{
    if(x<0 && y<m) return 0;
    if(x<0-1 || y<m-1) return -1;

    if(!vis[x+1][y+1]) {
        int one = fnc(x-1, y);
        if(one>=0) one = last[one][t[x]-'a'];
        int two = fnc(x, y-1);
        if(two>=0) two = last[two][t[y]-'a'];

        int now;
        if(one<0 && two<0) now=-1;
        else if(one<0) now=two+1;
        else if(two<0) now=one+1;
        else now=min(one,two)+1;

        dp[x+1][y+1]=now;
        vis[x+1][y+1]=1;
    }
    return dp[x+1][y+1];
}

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        scanf("%s %s", s, t);
        ns=strlen(s);
        nt=strlen(t);

        for(int i=ns; i>=0; i--) {
            for(int j=0; j<30; j++) {
                if(i==ns) last[i][j]=-1;
                else if(s[i]=='a'+j) last[i][j]=i;
                else last[i][j]=last[i+1][j];
            }
        }

        bool yes=0;
        for(int i=1; i<nt && !yes; i++) {
            m=i;
            memset(vis, 0, sizeof(vis));
            int got = fnc(i-1, nt-1);
            if(got>0) yes=1;
        }

        if(nt==1 && last[0][t[0]-'a']>=0) yes=1;

        if(yes) puts("YES");
        else puts("NO");
    }
}