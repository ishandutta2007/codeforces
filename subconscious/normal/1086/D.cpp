#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck
#define y0 fuxk
#define x1 fxck
#define y1 fxxk
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e5+100,MOD=1e9+7;
const ld eps=1e-9;
int n,q;char to[N];
set<int>st[3];
int t[3][N];
void add(int t[],int p,int x){
    ++p;
    for(;p<N;p+=p&-p)t[p]+=x;
}
int que(int t[],int p){
    ++p;
    int s=0;
    for(;p;p-=p&-p)s+=t[p];
    return s;
}
char s[N];
int a[N];
int sol(){
    int ret=0;
    for(int i=0;i<3;++i){
        //printf("%d\n",ret);
        int x=(i+2)%3,y=i,z=(i+1)%3;
        int x0,y0;
        if(st[z].size()==0)x0=n+1;else x0=*(st[z].begin());
        if(st[x].size()==0)y0=n+1;else y0=*(st[x].begin());
        //[x0,y0]
        int x1,y1;
        if(st[z].size()==0)x1=0;else x1=*(st[z].rbegin());
        if(st[x].size()==0)y1=0;else y1=*(st[x].rbegin());
        //[y1,x1]
        ret+=que(t[y],n);
        if(x0<=y0)ret-=que(t[y],y0)-que(t[y],x0);
        if(y1<=x1)ret-=que(t[y],x1)-que(t[y],y1);
        if(x0<=y0&&y1<=x1){
            int x2=max(x0,y1),y2=min(y0,x1);
            if(x2<=y2)ret+=que(t[y],y2)-que(t[y],x2);
        }
    }
    return ret;
}
int main(){
    to['R']=0,to['P']=1,to['S']=2;
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    rep(i,n)a[i]=to[s[i]];
    rep(i,n)add(t[a[i]],i,1),st[a[i]].insert(i);
    printf("%d\n",sol());
    rep(i,q){
        int x;char w[10];
        scanf("%d%s",&x,w+1);
        add(t[a[x]],x,-1);
        st[a[x]].erase(x);
        a[x]=to[w[1]];
        add(t[a[x]],x,1);
        st[a[x]].insert(x);
        printf("%d\n",sol());
    }
    return 0;
}