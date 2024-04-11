#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

char s[102],t[102];
void chk(int n) {
    for(int i=1;i<=n;i++){
        //s[i]=rand()%3+'a';
    }
    printf("%s ", s+1);
    for(int i=1;i<=n;i++)t[i]=s[i];
    sort(t+1,t+1+n);
    do {
        int c[30]={0},cc[30]={0};
        bool ok=1;
        for(int i=1;i<n;i++){
            c[s[i]-'a']++, cc[t[i]-'a']++;
            bool fg=0;
            for(int j=0;j<26;j++){
                if(c[j]!=cc[j]){
                    fg=1;
                }
            }
            ok&=fg;
        }
        if(ok){
            //printf("%s\n", t+1);
            printf("NO %d\n", s[1]==s[n]);return;
        }
    } while(next_permutation(t+1,t+1+n));
    set<int> st;
    printf("YES %d\n", s[1]==s[n]);
    for(int i=1;i<=n;i++){
        st.insert(s[i]);
    }
    if(st.size()>=3) while(1);
    return;
}

int n;
void dfs(int now) {
    if(now==n+1){
        chk(n);
        return;
    }
    for(char i='a';i<='b';i++){
        s[now]=i;
        dfs(now+1);
    }
}

char str[200000+10];
int q,nex[200000+10][26];
int main() {
    //n=10; dfs(1);
    scanf("%s", str+1);
    int n=strlen(str+1);
    for(int i=0;i<26;i++)nex[n+1][i]=n+1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<26;j++)nex[i][j]=nex[i+1][j];
        nex[i][str[i]-'a']=i;
    }
    scanf("%d",&q);
    while(q--){
        int x,y; scanf("%d%d",&x,&y);
        int cnt=0;
        for(int i=0;i<26;i++){
            if(nex[x][i]<=y) cnt++;
        }
        if(x==y) {
            printf("Yes\n"); continue;
        }
        //printf("cnt=%d\n", cnt);
        if(cnt>=3) {
            printf("Yes\n");
        } else if(cnt==2) {
            printf("%s\n", str[x]==str[y]?"No":"Yes");   
        } else if(cnt==1) {
            printf("No\n");
        }
    }
}