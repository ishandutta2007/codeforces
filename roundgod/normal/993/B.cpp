/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 01:11:13
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 12
#define MAXM 12
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int ans[MAXN][MAXM];
vector<P> x,y;
int check(P p,P q)
{
    if(p.F<p.S) swap(p.F,p.S);
    if(q.F<q.S) swap(q.F,q.S);
    if(p.F==q.F&&p.S==q.S) return 0;
    if(p.F==q.F||p.F==q.S) return p.F;
    if(p.S==q.F||p.S==q.S) return p.S;
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        P p;
        scanf("%d%d",&p.F,&p.S);
        x.push_back(p);
    }
    for(int j=0;j<m;j++)
    {
        P p;
        scanf("%d%d",&p.F,&p.S);
        y.push_back(p);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans[i][j]=check(x[i],y[j]);
    bool f=true;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(!f) break;
        for(int j=0;j<m;j++)
        {
            if((res!=0)&&(ans[i][j]!=0)&&(ans[i][j]!=res))
            {
                f=false; break;
            }
            //printf("%d %d\n",res,ans[i][j]);
            if(res==0) res=ans[i][j];
            //printf("%d\n",res);
        }
    }
    if(f)
    {
        printf("%d\n",res);
        return 0;
    }
    bool f1=true,f2=true;
    for(int i=0;i<n;i++)
    {
        int cnt=0,res=0;
        for(int j=0;j<m;j++)
        {
            if(ans[i][j]!=0&&ans[i][j]!=res)
            {
                cnt++;
                res=ans[i][j];
            }
        }
        if(cnt>=2) {f1=false; break;}
    }
    for(int i=0;i<m;i++)
    {
        int cnt=0,res=0;
        for(int j=0;j<n;j++)
        {
            if(ans[j][i]!=0&&ans[j][i]!=res)
            {
                cnt++;
                res=ans[j][i];
            }
        }
        if(cnt>=2) {f2=false; break;}
    }
    if(f1&&f2) puts("0"); else puts("-1");
    return 0;
}