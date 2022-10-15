#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,L;
ll T;
int X[MAXN];
vector<pair<int,P> > v;
int W[MAXN],d[MAXN],ans[MAXN];
map<int,int> mp;
vector<int> dest;
string str;
int get_lab(int id)
{
    int lab;
    if(W[id]==1)
    {
        ll cnt=0;
        bool f=false;
        for(int i=1;i<=N;i++)
        {
            if(i==id) continue;
            if(W[i]==2)
            {
                int dist=X[i]-X[id];
                if(dist<0) dist+=L;
                if(2*T>=dist) 
                {
                    cnt+=(2*T-dist+L-1)/L;
                    if((2*T-dist)%L==0) f=true;
                }
            }
        }
        lab=(id+cnt)%N;
        if(lab==0) lab=N;
    }
    else
    {
        ll cnt=0;
        bool f=false;
        for(int i=1;i<=N;i++)
        {
            if(i==id) continue;
            if(W[i]==1)
            {
                int dist=X[id]-X[i];
                if(dist<0) dist+=L;
                if(2*T>=dist) 
                {
                    cnt+=(2*T-dist+L)/L;
                    if((2*T-dist)%L==0) f=true;
                }
            }
        }
        lab=((id-cnt%N)+N)%N;
        if(lab==0) lab=N;
    }
    return lab;
}
int main()
{
    scanf("%d%d%lld",&N,&L,&T);
    for(int i=1;i<=N;i++)
    {
        int x,w;
        scanf("%d",&x); x--;
        cin>>str;
        w=(str[0]=='L'?2:1);
        v.push_back(make_pair(x,P(i,w)));
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=N;i++) 
    {
        X[i]=v[i-1].F;
        W[i]=v[i-1].S.S;
        if(W[i]==1)
        {
            d[i]=(X[i]+T)%L;
            dest.push_back(d[i]);
        }
        else
        {
            d[i]=((X[i]-T)%L+L)%L;
            dest.push_back(d[i]);
        }
    }  
    sort(dest.begin(),dest.end());
    int lab=get_lab(1);
    int p=lower_bound(dest.begin(),dest.end(),d[1])-dest.begin();
    for(int i=1;i<=N;i++)
    {
        ans[v[lab-1].S.F]=dest[p];
        lab++; if(lab>N) lab-=N;
        p++; if(p>=N) p-=N;
    }
    for(int i=1;i<=N;i++) printf("%d ",ans[i]+1);
    return 0;
}