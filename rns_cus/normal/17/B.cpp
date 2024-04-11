///b
#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

#define N 1010
#define inf 0x7f7f7f7f

int id[N],q[N],cost[N][N],res,n,m;

bool cmp(int i,int j){
    return q[i]>q[j];
}
int main()
{
///    freopen("in.txt","r",stdin);
    memset(cost,-1,sizeof(cost));
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",q+i),id[i]=i;
    sort(id,id+n,cmp);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(cost[a-1][b-1]==-1 || cost[a-1][b-1]>c)cost[a-1][b-1]=c;
    }
    for(int i=1;i<n;i++){
        int ii=id[i];
        int mincost=inf;
        for(int j=0;j<i;j++){
            int jj=id[j];
            if(q[jj]==q[ii])continue;
            if(cost[jj][ii]==-1)continue;
            if(mincost>cost[jj][ii]){
                mincost=cost[jj][ii];
            }
        }
        if(mincost==inf){res=-1;break;}
        res+=mincost;
    }
    printf("%d\n",res);
    return 0;
}