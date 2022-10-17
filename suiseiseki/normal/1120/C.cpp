#include<bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=100010;
char c[maxn],s[maxn];
struct SAM{
    int ch[maxn][26],fa[maxn],maxlen[maxn],cnt,last;
    int a[maxn],b[maxn],occ[maxn];
    void init()
    {
        cnt=last=1;
        memset(ch[1],0,sizeof(ch[1]));
        memset(occ,0x3f,sizeof(occ));
    }
    int add(int x,int pos)
    {
       int np=++cnt,p=last; last=np;  occ[np]=pos;
       maxlen[np]=maxlen[p]+1;memset(ch[np],0,sizeof(ch[np]));
       while(p&&!ch[p][x]) ch[p][x]=np,p=fa[p];
       if(!p) fa[np]=1;
       else {
         int q=ch[p][x];
         if(maxlen[q]==maxlen[p]+1) fa[np]=q;
         else {
            int nq=++cnt; maxlen[nq]=maxlen[p]+1;
            fa[nq]=fa[q]; fa[q]=fa[np]=nq;
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            while(p&&ch[p][x]==q) ch[p][x]=nq,p=fa[p];
         }
       }
    }
    void Sort()
    {
        rep(i,1,cnt) a[i]=0;
        rep(i,1,cnt) a[maxlen[i]]++;
        rep(i,1,cnt) a[i]+=a[i-1];
        rep(i,1,cnt) b[a[maxlen[i]]--]=i;
        for(int i=cnt;i>=1;i--)
            occ[fa[b[i]]]=min(occ[b[i]],occ[fa[b[i]]]);
    }
}T;
int a[maxn],A,B,dp[maxn],pos[5010][5010];
int main()
{
    int N;
    scanf("%d%d%d%s",&N,&A,&B,c+1);
    T.init();
    rep(i,1,N) T.add(c[i]-'a',i);
    rep(i,1,N) {
        int now=1;
        rep(j,i,N){
            now=T.ch[now][c[j]-'a'];
            pos[i][j]=now;
        }
    }
    T.Sort();
    rep(i,1,N){
        dp[i]=dp[i-1]+A;
        rep(j,1,i-1){
            if(T.occ[pos[j+1][i]]<=j){
                dp[i]=min(dp[i],dp[j]+B);
                break;
            }
        }
    }
    printf("%d\n",dp[N]);
    return 0;
}