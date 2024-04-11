/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-24 14:24:16
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,q;
char s[MAXN];
int bit[3][2*MAXN+1];
set<int> R,P,S;
int sum(int id,int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(int id,int i,int x)
{
    while(i<MAXN)
    {
        bit[id][i]+=x;
        i+=i&-i;
    }
}
void change(int x,char ch)
{
    if(s[x]=='R') {R.erase(x); add(0,x,-1);}
    else if(s[x]=='P') {P.erase(x); add(1,x,-1);}
    else {S.erase(x); add(2,x,-1);}
    if(ch=='R') {R.insert(x); add(0,x,1);}
    else if(ch=='P') {P.insert(x); add(1,x,1);}
    else {S.insert(x); add(2,x,1);}
    s[x]=ch;
}
void find_answer()
{
    int ans=0;
    if(P.size()>0)
    {
        if(S.size()!=0) 
        {
            ans+=sum(0,n);
            int ll=*P.begin(); int rr=*S.begin(); if(ll<=rr) ans-=(sum(0,rr)-sum(0,ll-1));
            int r=*P.rbegin(); int l=*S.rbegin(); if(l<=r) ans-=(sum(0,r)-sum(0,l-1));
            if(l<=r&&ll<=rr)
            {
                l=max(l,ll);
                r=min(r,rr);
                if(l<=r) ans+=(sum(0,r)-sum(0,l-1));
            }
        }
    }
    else ans+=sum(0,n);
    if(S.size()>0)
    {
        if(R.size()!=0) 
        {
            ans+=sum(1,n);
            int l=*S.begin(); int r=*R.begin(); if(l<=r) ans-=(sum(1,r)-sum(1,l-1));
            int rr=*S.rbegin();int ll=*R.rbegin(); if(ll<=rr) ans-=(sum(1,rr)-sum(1,ll-1));
            if(l<=r&&ll<=rr)
            {
                l=max(l,ll);
                r=min(r,rr);
                if(l<=r) ans+=(sum(1,r)-sum(1,l-1));
            }
        }
    }
    else ans+=sum(1,n);
    if(R.size()>0)
    {
        if(P.size()!=0) 
        {
            ans+=sum(2,n);
            int l=*R.begin(); int r=*P.begin(); if(l<=r) ans-=(sum(2,r)-sum(2,l-1));
            int rr=*R.rbegin();int ll=*P.rbegin(); if(ll<=rr) ans-=(sum(2,rr)-sum(2,ll-1));
            if(l<=r&&ll<=rr)
            {
                l=max(l,ll);
                r=min(r,rr);
                if(l<=r) ans+=(sum(2,r)-sum(2,l-1));
            }
        }
    }
    else ans+=sum(2,n);
    printf("%d\n",ans);
}
char str[5];
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='R') {R.insert(i); add(0,i,1);}
        else if(s[i]=='P') {P.insert(i); add(1,i,1);}
        else {S.insert(i); add(2,i,1);}
    }
    find_answer();
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x); scanf("%s",str);
        change(x,str[0]);find_answer();
    }
    return 0;
}