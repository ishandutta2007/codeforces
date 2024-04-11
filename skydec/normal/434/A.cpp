#include<stdio.h>
#include<vector>
#include<algorithm>
#define pb push_back
#define MAXN 210000
using namespace std;
typedef long long LL;
int n,m;int data[MAXN];
vector<int>que[MAXN];
#define labs fuckit
LL labs(LL x){if(x<0)return -x;return x;}
int tmp[MAXN];
int main()
{
    scanf("%d%d",&n,&m);LL ans=0;
    for(int i=1;i<=m;i++)
    {
            scanf("%d",&data[i]);
            if(i!=1)ans+=labs(data[i]-data[i-1]);
            que[data[i]].pb(i);
            }
    LL final=ans;
    for(int i=1;i<=n;i++)
    {
            tmp[0]=0;
            for(int j=0;j<que[i].size();j++)
            {
                    if(que[i][j]-1!=0&&data[que[i][j]-1]!=data[que[i][j]])
                    tmp[++tmp[0]]=data[que[i][j]-1];
                    if(que[i][j]+1!=m+1&&data[que[i][j]+1]!=data[que[i][j]])
                    tmp[++tmp[0]]=data[que[i][j]+1];
                    }
            sort(tmp+1,tmp+1+tmp[0]);
            int u=tmp[(tmp[0]+1)/2];
            LL reu=ans;
            for(int j=1;j<=tmp[0];j++)
            reu-=labs(i-tmp[j]),reu+=labs(u-tmp[j]);
            if(reu<final)final=reu;
            }
    printf("%I64d\n",final);
    return 0;
}