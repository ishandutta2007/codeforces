#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int m,k;
vector<int> coord[MAXN];
int sum[MAXN];
ll sum2[MAXN];
bool flag[MAXN];
//v^2+2xv
//4v^2+4xv
//9v^2+6xv
//16v^2+8xv
int main()
{
    scanf("%d%d",&m,&k);
    memset(flag,true,sizeof(flag));
    P p=P(-1,0);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            coord[i].push_back(x);
            sum[i]+=x;
            sum2[i]+=1LL*x*x;
        }
        sort(coord[i].begin(),coord[i].end());
        if(i>0) 
        {
            sum[i]-=sum[0];
            if(sum[i]%i) flag[i]=false;
            else
            {
                if(sum[i]/i==p.F) p.S++;
                else if(p.S==0) p=P(sum[i]/i,1);
                else p.S--;
            } 
        }
        if(i>0) sum2[i]-=sum2[0];
    }
    for(int i=1;i<k;i++) if(flag[i]&&sum[i]/i!=p.F) flag[i]=false;
    ll v2,xv;
    if(flag[1]&&flag[2])
    {
        v2=(sum2[2]-2*sum2[1])/2;
        xv=(sum2[1]-v2)/2;
    }
    else if(!flag[1])
    {
        v2=(sum2[3]*2-sum2[2]*3)/6;
        xv=(sum2[2]-4*v2)/4;
    }
    else
    {
        v2=(sum2[3]-sum2[1]*3)/6;
        xv=(sum2[1]-v2)/2;
    }
    for(int i=1;i<k;i++)
    {
        if(flag[i]) continue;
        int delta=p.F*i-sum[i];
        for(auto x:coord[i])
        {
            if(sum2[i]-1LL*x*x+1LL*(x+delta)*(x+delta)==1LL*i*i*v2+2LL*i*xv)
            {
                printf("%d %d\n",i,x+delta);
                fflush(stdout);
                return 0;
            }
        }
    }
    assert(0);
    return 0;
}