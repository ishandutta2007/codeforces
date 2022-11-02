#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define g() getchar()
template<class Q>void Scan(Q&x){
    char c;while(c=g(),c<48||c>57);
    for(x=0;c>47&&c<58;c=g())x=10*x+c-48; 
}

const int MAXN=2e5+5;
const int Alpha=26;

typedef struct sam;

struct edge{
    sam*to;
    edge*next;
}e[MAXN<<1];
edge*et=e;
inline void AddEdge(edge*&head,sam*to){
    et->to=to,et->next=head;
    head=et++;
}

struct sam{
    int l,L,R;
    char x;
    edge*head;
    sam*ch[Alpha],*p;
}samp[MAXN<<1];
sam*samt=samp;
sam*rt=samt++;
inline sam*Add(sam*p,int x){
    if(p->ch[x]&&p->ch[x]->l==p->l+1)return p->ch[x];
    sam*cur=samt++;
    cur->l=p->l+1;
    cur->x=x+'a';
    for(;p&&!p->ch[x];p=p->p)p->ch[x]=cur;
    if(!p)cur->p=rt;
    else{
        sam*q=p->ch[x];
        if(q->l==p->l+1)cur->p=q;
        else{
            sam*r=samt++;
            *r=*q;
            r->l=p->l+1;
            q->p=cur->p=r;
            for(;p&&p->ch[x]==q;p=p->p)p->ch[x]=r;
        }
    }
    return cur;
}

int cnt;

inline void dfs(sam*p){
    p->L=++cnt;
    for(edge*e=p->head;e;e=e->next)
        dfs(e->to);
    p->R=cnt;
}

int bit[MAXN<<1];
inline void add(int x){
    for(;x<=cnt;x+=x&-x)++bit[x];
}
inline int sum(int x){
    int res=0;
    for(;x;x-=x&-x)res+=bit[x];
    return res; 
}

char s[MAXN];

sam*last[MAXN],*pos[MAXN];

int n,Q,len[MAXN],Len;

inline void Init(){
    Scan(n),Scan(Q);
    for(int i=1;i<=n;++i){
        scanf("%s",s+Len);
        len[i]=strlen(s+Len);
        sam*p=rt;
        for(int j=Len;j<Len+len[i];++j)
            p=Add(p,s[j]-'a');
        Len+=len[i];
    }
    for(int i=1,j=0;i<=n;++i){
        sam*p=rt;
        for(int k=0;k<len[i];++k){
            p=p->ch[s[j]-'a'];
            last[j++]=p;
        }
        pos[i]=p;
    }
    for(sam*p=samp;p<samt;++p){
        if(p->p)AddEdge(p->p->head,p);
    }   
    dfs(rt);
}

struct query{
    int x,t,id,n; 
    query(int x=0,int t=0,int id=0,int n=0):
        x(x),t(t),id(id),n(n){}
}q[MAXN*5];
int head[MAXN],tot;
inline void AddQuery(int l,int r,int k,int id){
    q[++tot]=query(k,1,id,head[r]),head[r]=tot;
    if(l==1)return;
    q[++tot]=query(k,-1,id,head[l-1]),head[l-1]=tot;
}

int ans[MAXN*3];

inline void Solve(){
    for(int i=1,l,r,k;i<=Q;++i){
        Scan(l),Scan(r),Scan(k);
        AddQuery(l,r,k,i);
    }
    for(int i=1,j=0;i<=n;++i){
        for(int k=0;k<len[i];++k)add(last[j++]->L);
        for(int k=head[i];k;k=q[k].n){
            ans[q[k].id]+=(sum(pos[q[k].x]->R)-sum(pos[q[k].x]->L-1))*q[k].t;
        }
    }
    for(int i=1;i<=Q;++i){
        printf("%d\n",ans[i]);
    }
}

int main(){
    Init(); Solve(); return 0;
}