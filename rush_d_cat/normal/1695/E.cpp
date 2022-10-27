#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <set>
#include <assert.h>
using namespace std;
const int N = (300000+10)*4;
const int MAXN=(300000+10)*4,MAXM=(300000+10)*4;
struct Edge{
    int from,to,nxt;
}e[MAXM];
int head[MAXN],edgeCnt=1;
void addEdge(int u,int v){
    e[++edgeCnt].from=u;
    e[edgeCnt].to=v;
    e[edgeCnt].nxt=head[u];
    head[u]=edgeCnt;
}
set<int> st;
int stack[MAXN], ans[MAXN]; // 
bool vis[MAXN];
bool f[MAXN];
int top,t;
bool gg = 0;


char s1[2][N], s2[2][N];
int res[2][N];
int las = 0;
void euler(int src) {
    if (! st.count(src)) return;
    if (f[src]) return;
    top = 0; t = 0;
    stack[++top] = src;
    while (top) {
        int x = stack[top], i = head[x];
        while (i && vis[i]) i = e[i].nxt;
        if (i) {
            stack[++top] = e[i].to;
            head[x] = e[i].nxt;
            vis[i]=vis[i^1]=1;
        }else{
            top--;
            ans[++t] = x;
        }
    }
    if (t == 3) {
        gg = 1; return;
    }
    t --;
    
    assert(t % 2 == 0);
    int pos=0;
    for (int i = 1; i <= t/2; i ++) {
        res[0][i + las] = ans[++pos];
    }
    for (int i = t / 2; i >= 1; i --) {
        res[1][i + las] = ans[++pos];
    }

    for (int i = 1; i<=t; i++) {
        f[ans[i]] = 1;
        //printf("%d ", ans[i]);
    }
    //printf("\n");
    int k = t / 2;
    if (k % 2 == 0) {
        for (int i = 1; i <= k; i ++) {
            s1[0][i + las] = i%2?'L':'R';
            s1[1][i + las] = i%2?'L':'R';
            s2[0][i + las] = i%2?'R':'L';
            s2[1][i + las] = i%2?'R':'L';
        }
        s2[0][1 + las] = 'U';
        s2[1][1 + las] = 'D';
        s2[0][k + las] = 'U';
        s2[1][k + las] = 'D';
    } else {
        for (int i = 1; i <= k; i ++) {
            s1[0][i + las] = i%2?'L':'R';
            s1[1][i + las] = i%2?'L':'R';
            s2[0][i + las] = i%2?'R':'L';
            s2[1][i + las] = i%2?'R':'L';
        }
        s2[0][1 + las] = 'U';
        s2[1][1 + las] = 'D';
        s1[0][k + las] = 'U';
        s1[1][k + las] = 'D';                
    }
    las += t / 2;
}
int main() {
    int n,m;
    scanf("%d",&n);
    m=n; n*=2;
    for (int i = 1; i <= m; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        st.insert(u); st.insert(v);
        addEdge(u,v);
        addEdge(v,u);
        addEdge(u,v);
        addEdge(v,u);
    }
    for (int i = 1; i <= 2 * n; i ++) {
        euler(i);
    }
    if (gg) {
        printf("-1\n"); 
    } else {
        printf("%d %d\n", 2, n/2);
        for (int i = 0; i < 2; i ++) {
            for (int j = 1; j <= n / 2; j ++) {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < 2; i ++) {
            for (int j = 1; j <= n / 2; j ++) {
                printf("%c", s1[i][j]);
            }
            printf("\n");
        }     
        for (int i = 0; i < 2; i ++) {
            for (int j = 1; j <= n / 2; j ++) {
                printf("%c", s2[i][j]);
            }
            printf("\n");
        }   
    }

    return 0;
}