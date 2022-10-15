/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 13:28:13
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d,a[MAXN];
set<int> s;
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        int x=a[i]-d;
        bool f=true;
        for(int j=0;j<n;j++)
            if(max(a[j]-x,x-a[j])<d) f=false;
        if(f) s.insert(x);
        x=a[i]+d;
        f=true;
        for(int j=0;j<n;j++)
            if(max(a[j]-x,x-a[j])<d) f=false;
        if(f) s.insert(x);
    }
    printf("%d\n",(int)s.size()-n);
    return 0;
}