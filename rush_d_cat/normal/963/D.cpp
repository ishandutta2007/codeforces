#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 100000+10;
int fail[N],last[N],ch[N][26],id[N],size;
char t[N],s[N]; int n, len[N], l[N];
void insert(char * s, int x) {
    int now=0;
    for(int i=0;s[i];i++) {
        int c=s[i]-'a';
        if(ch[now][c]==0) {
            ch[now][c]=++size;
        }     
        now=ch[now][c];      
    }
    id[now]=x;
}

void build() {
    queue<int> q;
    for(int i=0;i<26;i++){
        if(ch[0][i]) q.push(ch[0][i]);
    }
    while(q.size()) {
        int u=q.front(); q.pop();
        for(int i=0;i<26;i++){
            if(ch[u][i]==0){
                ch[u][i]=ch[fail[u]][i]; continue;
            }
            int v=fail[u];
            while(v&&ch[v][i]==0) v=fail[v];
            fail[ch[u][i]]=ch[v][i];
            last[ch[u][i]]=id[ch[v][i]]?ch[v][i]:last[ch[v][i]];
            q.push(ch[u][i]);
        }
    }
}
queue<int> q[N]; int ans[N];
void upd(int k, int pos) {

    while (k) {
        int x = id[k];
        q[x].push(pos);
        if(q[x].size() >= len[x]) {
            if (q[x].size()>len[x]) q[x].pop();
            ans[x] = min(ans[x], pos - q[x].front() + l[x]);
        }
        k=last[k];
    }
}
void match(char * s) {
    int now=0;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        int nex=ch[now][c];
        if(id[nex]||last[nex]) upd(nex, i);
        now=ch[now][c];
    }
}

int main() {
    scanf("%s %d",t, &n);
    for(int i=1;i<=n;i++){
        scanf("%d %s",&len[i],s);
        insert(s,i);  l[i]=strlen(s);
    }
    build();
    for(int i=1;i<=n;i++) ans[i]=N;
    match(t);
    for(int i=1;i<=n;i++) printf("%d\n", ans[i]==N?-1:ans[i]);
}
/*
aaabbbbaaabababab
1
6 a
*/