#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define riterator reverse_iterator
using namespace std;
 
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
    for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
    return x*f;
}
 
const int N = 2e6;
struct Edge
{
    int v,nxt;
} e[(N<<1)+3];
int fe[N+3];
int du[N+3];
char a[N+3];
int dep[N+3];
int n,en;
 
void addedge(int u,int v)
{
    en++; e[en].v = v; du[u]++;
    e[en].nxt = fe[u]; fe[u] = en;
}
 
void dfs(int u,int tfa)
{
    for(int i=fe[u]; i; i=e[i].nxt)
    {
        int v = e[i].v; if(v==tfa) continue;
        dep[v] = dep[u]+1;
        dfs(v,u);
    }
}
 
int main()
{
    int T; scanf("%d",&T); while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<n; i++) {int u = read(),v = read(); addedge(u,v),addedge(v,u);}
        scanf("%s",a+1);
        for(int i=n; i>=1; i--)
        {
            if(a[i]=='W')
            {
                n+=3; addedge(i,n-2),addedge(n-2,i); addedge(n-2,n-1),addedge(n-1,n-2); addedge(n-2,n),addedge(n,n-2);
            }
        }
        bool flg1 = false;
        for(int i=1; i<=n; i++)
        {
            if(du[i]>=4) {flg1 = true; break;}
            int cnt2 = 0,cnt3 = 0;
            for(int o=fe[i]; o; o=e[o].nxt)
            {
                int v = e[o].v;
                if(du[v]>=2) cnt2++;
            }
            if(du[i]>=3&&cnt2>=2) {flg1 = true; break;}
        }
        if(flg1) {puts("White");}
        else
        {
            int cnt3 = 0;
            for(int i=1; i<=n; i++) if(du[i]==3) {cnt3++;}
            if(cnt3<=1) {puts("Draw");}
            else
            {
                int u = 0,v = 0;
                for(int i=1; i<=n; i++) {if(du[i]==3) {if(u==0) u = i; else v = i;}}
                dep[u] = 0; dfs(u,0);
                if(dep[v]&1) {puts("Draw");}
                else {puts("White");}
            }
        }
        for(int i=1; i<=en; i++) e[i].v = e[i].nxt = 0;
        for(int i=1; i<=n; i++) du[i] = dep[i] = fe[i] = 0;
        en = 0;
    }
    return 0;
}