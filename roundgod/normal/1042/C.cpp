/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-17 16:37:08
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int cnt0,cnt1;
int id1;
vector<int> zeroes;
int main()
{
    scanf("%d",&n);
    id1=-1;
    int cur=-INF-1;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]==0) {cnt0++; zeroes.push_back(i);}
        if(a[i]<0) {cnt1++; if(a[i]>cur) {id1=i; cur=a[i];}}
    }
    if(cnt0==n||(cnt0==n-1&&cnt1==1))
    {
        for(int i=n-1;i>=1;i--) printf("1 %d %d\n",i,n);
        return 0;
    }
    while(zeroes.size()>1)
    {
        int p=zeroes.back();zeroes.pop_back();
        int q=zeroes.back();zeroes.pop_back();
        printf("1 %d %d\n",q,p);
        zeroes.push_back(p);
    }
    if(zeroes.size()==0&&(cnt1&1))
    {
        printf("2 %d\n",id1);
        if(id1==n)
        {
            for(int i=n-2;i>=1;i--) printf("1 %d %d\n",i,n-1);
        }
        else
        {
            for(int i=n-1;i>=1;i--)
            {
                if(i==id1) continue;
                printf("1 %d %d\n",i,n);
            }
        }
        return 0;
    }
    if(zeroes.size()==1&&(cnt1&1))
    {
        printf("1 %d %d\n",zeroes[0],id1);
        printf("2 %d\n",id1);
        int last=-1;
        for(int i=n;i>=1;i--) if(a[i]!=0&&i!=id1) {last=i; break;}
        assert(last!=-1);
        for(int i=last-1;i>=1;i--)
        {
            if(i==id1||a[i]==0) continue;
            printf("1 %d %d\n",i,last);
        }
        return 0;
    }
    if(zeroes.size()==1)
    {
        printf("2 %d\n",zeroes[0]);
        int last=-1;
        for(int i=n;i>=1;i--) if(a[i]!=0) {last=i; break;}
        assert(last!=-1);
        for(int i=last-1;i>=1;i--)
        {
            if(a[i]==0) continue;
            printf("1 %d %d\n",i,last);
        }
        return 0;
    }
    for(int i=n-1;i>=1;i--) printf("1 %d %d\n",i,n);
    return 0;
}