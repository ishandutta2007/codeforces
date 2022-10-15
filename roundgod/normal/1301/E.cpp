#include<bits/stdc++.h>
#define MAXN 505
#define MAXQ 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,sum[5][MAXN][MAXN];
char str[MAXN][MAXN];
char s[100]="RGYB";
int r1[MAXQ],c1[MAXQ],r2[MAXQ],c2[MAXQ];
int ans[MAXQ];
int query(int id,int r1,int c1,int r2,int c2)
{
    return sum[id][r2][c2]+sum[id][r1-1][c1-1]-sum[id][r2][c1-1]-sum[id][r1-1][c2];
}
void compute_prefix_sum(int id)
{
     for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                sum[id][i][j]+=sum[id][i-1][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                sum[id][i][j]+=sum[id][i][j-1];
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=0;i<q;i++) scanf("%d%d%d%d",&r1[i],&c1[i],&r2[i],&c2[i]);
    for(int k=0;k<4;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(str[i][j]==s[k]) sum[k][i][j]=1;
       compute_prefix_sum(k);
    }
    for(int len=1;len<=250;len++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                sum[4][i][j]=0;
        for(int i=1;i+2*len-1<=n;i++)
            for(int j=1;j+2*len-1<=m;j++)
            {
                if(query(0,i,j,i+len-1,j+len-1)==len*len&&
                    query(1,i,j+len,i+len-1,j+2*len-1)==len*len&&
                    query(2,i+len,j,i+2*len-1,j+len-1)==len*len&&
                    query(3,i+len,j+len,i+2*len-1,j+2*len-1)==len*len
                ) sum[4][i][j]++;

            }
        compute_prefix_sum(4);
        for(int i=0;i<q;i++)
        {
            if(r2[i]-r1[i]+1>=2*len&&c2[i]-c1[i]+1>=2*len&&query(4,r1[i],c1[i],r2[i]-2*len+1,c2[i]-2*len+1)>0) ans[i]=len;
        }
    }
    for(int i=0;i<q;i++) printf("%d\n",4*ans[i]*ans[i]);
    return 0;
}