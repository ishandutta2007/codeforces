#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;
struct node{
    int num,x;
}p[10005];
const ll INF=1ll<<60;
int n,x,l[10005][2],pos[10005],q[10005],tot;
ll ans=INF,dp[2][10005];
inline bool cmp(node a,node b){
    return a.x<b.x;
}

int main(){
    scanf("%d%d",&n,&x);
    l[0][0]=l[0][1]=x;
    p[0].x=x;p[0].num=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i][0],&l[i][1]);
        p[i*2-1].x=l[i][0];p[i*2].x=l[i][1];
        p[i*2-1].num=i*2-1;p[i*2].num=i*2;
    }
    sort(p,p+n*2+1,cmp);int last=0;
    for(int i=0;i<=n*2;i++)
    {
        if(p[i].x!=last) tot++;
        last=p[i].x;
        int pp=(p[i].num+1)/2,g=(p[i].num+1)&1;
        pos[tot]=p[i].x;
        l[pp][g]=tot;q[i]=tot;
    }
//  printf("%d\n",l[0][1]);
//  for(int i=1;i<=n;i++) printf("%d %d\n",l[i][0],l[i][1]);
//  for(int i=1;i<=tot;i++) printf("%d ",pos[i]);puts("");
    for(int i=1;i<=tot;i++)
        dp[0][i]=INF;
    dp[0][l[0][1]]=0;int k=0;
    for(int i=1;i<=n;i++)
    {
        k^=1;
        for(int j=1;j<=tot;j++)
            dp[k][j]=INF;
        ll now=INF;
        for(int j=1;j<=tot;j++){
            now=min(now,dp[k^1][j]-pos[j]);
            ll tmp=min(fabs(pos[j]-pos[l[i][0]]),fabs(pos[j]-pos[l[i][1]]));
            if(j>=l[i][0]&&j<=l[i][1]) tmp=0;
            tmp+=pos[j]+now;dp[k][j]=min(dp[k][j],tmp);
        }
        now=INF;
        for(int j=tot;j>=1;j--){
            now=min(now,dp[k^1][j]+pos[j]);
            ll tmp=min(fabs(pos[j]-pos[l[i][0]]),fabs(pos[j]-pos[l[i][1]]));
            if(j>=l[i][0]&&j<=l[i][1]) tmp=0;
            tmp+=now-pos[j];dp[k][j]=min(dp[k][j],tmp);
        }
    //  for(int j=1;j<=tot;j++) printf("%I64d ",dp[k][j]);
//      puts("");
    }
    for(int i=1;i<=tot;i++)
        ans=min(ans,dp[k][i]);
    printf("%I64d\n",ans);
    return 0;
}