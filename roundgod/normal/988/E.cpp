/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-04 16:56:33
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
    cin>>str;
    int ans=INF;
    int id1=-1,id2=-1;
    int n=str.size();
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='0'&&id1==-1) id1=i;
        else if(str[i]=='0'&&id1!=-1&&id2==-1) id2=i;
    }
    if(id1!=-1&&id2!=-1) ans=min(ans,2*(n-1)-id1-id2-1);
    id1=-1,id2=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='0'&&id1==-1) id1=i;
        if(str[i]=='5'&&id2==-1) id2=i;
    }
    if(id1!=-1&&id2!=-1) ans=min(ans,2*(n-1)-id1-id2-1+(id1>id2?0:1));
    id1=-1,id2=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='2'&&id1==-1) id1=i;
        if(str[i]=='5'&&id2==-1) id2=i;
    }
    if(id1!=-1&&id2!=-1) 
    {
        if(id1==0)
        {
            int cnt=id1+1,res=0;
            while(str[cnt]=='0') cnt++;
            if(cnt==id2&&id2==n-1)
            {
                if(n==2) ans=0;
            }
            else
            {
                res=cnt-id1-1;
                ans=min(ans,2*(n-1)-id1-id2-1+res);
            }
        }
        else if(id2==0)
        {
            int cnt=id2+1,res=0;
            while(str[cnt]=='0') cnt++;
            if(cnt==id1&&id1==n-1)
            {
                if(n==2) ans=1;
            }
            else
            {
                res=cnt-id2-1;
                ans=min(ans,2*(n-1)-id1-id2+res);
            }
        }
        else ans=min(ans,2*(n-1)-id1-id2-1+(id1>id2?1:0));
    }
    id1=-1,id2=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='7'&&id1==-1) id1=i;
        if(str[i]=='5'&&id2==-1) id2=i;
    }
    if(id1!=-1&&id2!=-1) 
    {
        if(id1==0)
        {
            int cnt=id1+1,res=0;
            while(str[cnt]=='0') cnt++;
            if(cnt==id2&&id2==n-1)
            {
                if(n==2) ans=0;
            }
            else
            {
                res=cnt-id1-1;
                ans=min(ans,2*(n-1)-id1-id2-1+res);
            }
        }
        else if(id2==0)
        {
            int cnt=id2+1,res=0;
            while(str[cnt]=='0') cnt++;
            if(cnt==id1&&id1==n-1)
            {
                if(n==2) ans=1;
            }
            else
            {
                res=cnt-id2-1;
                ans=min(ans,2*(n-1)-id1-id2+res);
            }
        }
        else ans=min(ans,2*(n-1)-id1-id2-1+(id1>id2?1:0));
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}