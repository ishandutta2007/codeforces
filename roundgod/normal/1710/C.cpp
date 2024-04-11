#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int dp[MAXN][8][8];
int solve(int now,int smask,int mask)
{
    if(now==n)
    {
        if(mask==7) return 1;
        else return 0;
    }
    if(dp[now][smask][mask]!=-1) return dp[now][smask][mask];
    int res=0,x=str[now]-'0';
    for(int a=0;a<2;a++)
    {
        if(((smask&1)==0)&&(a>x)) continue;
        for(int b=0;b<2;b++)
        {
            if(((smask&2)==0)&&(b>x)) continue;
            for(int c=0;c<2;c++)
            {
                if(((smask&4)==0)&&(c>x)) continue;
                int nmask=smask;
                if(a<x) nmask|=1;
                if(b<x) nmask|=2;
                if(c<x) nmask|=4;
                int tmp=(a^b)*4+(a^c)*2+(b^c),nnmask=mask;
                if(tmp==3) nnmask|=1; else if(tmp==6) nnmask|=2; else if(tmp==5) nnmask|=4;
                add(res,solve(now+1,nmask,nnmask));
            }
        }
    }
    //printf("%d %d %d %d\n",now,smask,mask,res);
    return dp[now][smask][mask]=res;
}
int main()
{
    cin>>str; n=(int)str.size();
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(0,0,0));
    return 0;
}