#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int mod=1e9+7, maxn=1e6+10;
struct PAM{
    int s[maxn],now;
    int nxt[maxn][26],fail[maxn],l[maxn],last,tot;
    int diff[maxn],anc[maxn];
    int id[maxn],f[maxn],g[maxn];
    void init(){
        //1root 0root
        s[0] = l[1] = -1;
        fail[0] = tot = now =1;
        last = l[0] = anc[0] = anc[1] = diff[0] = diff[1] = 0;
        memset(nxt[0],0,sizeof nxt[0]);
        memset(nxt[1],0,sizeof nxt[1]);
    }
    PAM(){init();}
    int newnode(int len){
        tot++;
        memset(nxt[tot],0,sizeof nxt[tot]);
        diff[tot]=anc[tot]=fail[tot]=0;l[tot]=len;
        return tot;
    }
    int get_fail(int x){
        while (s[now-l[x]-2]!=s[now-1])x = fail[x];
        return x;
    }
    void add(int ch){
        s[now++] = ch;
        int cur = get_fail(last);
        if(!nxt[cur][ch]){
            int tt = newnode(l[cur]+2);
            fail[tt] = nxt[get_fail(fail[cur])][ch];
            nxt[cur][ch] = tt;
            diff[tt] = l[tt] - l[fail[tt]];
            anc[tt] = diff[tt] == diff[fail[tt]]? anc[fail[tt]] : fail[tt];
        }
        last = nxt[cur][ch];
    }
    void trans(int i){
        for (int p = last;p>1;p = anc[p]){
            g[p] = f[i - l[anc[p]] - diff[p]];
            if (diff[p] == diff[fail[p]]){
                (g[p] += g[fail[p]]) %= mod;
            }
            (f[i] += (i % 2 == 0) *g[p]) %= mod;
        }
    }
    int sol(char* s){
        f[0] = 1;
        int n = strlen(s + 1);
        for (int i=1;i<=n;i++){
            add(s[i] - 'a');
            trans(i);
        }
        return f[n];
    }
}pam;
char t[maxn],s[maxn];
int n;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    rep(i,n>>1){
        t[2*i-1]=s[i];
        t[2*i]=s[n-i+1];
    }
    pam.init();
    printf("%d\n",pam.sol(t));
    return 0;
}