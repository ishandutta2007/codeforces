#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int>mp;
int n,m,r,k,x,y,X,Y,xx[]={0,1,0,-1},yy[]={1,0,-1,0};
ll sum;
priority_queue<pair<ll,ll> >q;
pair<ll,ll>tp;
inline ll cal(int x,int y)
{return (min(x+r-1,n)-max(x-r,0)-r+1)*
(long long)(min(y+r-1,m)-max(y-r,0)-r+1);}
inline ll ccal(int x,int y)
{return ((ll)x-1)*m+y-1;}
int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&k);
	x=n+1>>1,y=m+1>>1;
	q.push({cal(x,y),ccal(x,y)});
        mp.insert({ccal(x,y),0});
	while(k--)
    {
        tp=q.top(),q.pop();
        sum+=tp.first;
        x=tp.second/m+1,y=tp.second%m+1;
        //cout<<x<<","<<y<<"("<<tp.first<<endl;
        for(int i=0;i<4;i++)
        {
            X=xx[i]+x,Y=yy[i]+y;
            if(X&&X<=n&&Y&&Y<=m&&mp.find(ccal(X,Y))==mp.end())
            q.push({cal(X,Y),ccal(X,Y)}),mp.insert({ccal(X,Y),0});
        }
    }
    printf("%.9lf",(double)sum/(n-r+1)/(m-r+1));
	//
}