/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-19 21:42:31
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
int n,k,pre[MAXN],suf[MAXN][2];
string str;
int main()
{
    cin>>str;
    str=str+str;
    n=str.size();
    int ans=1,cnt=1;
    for(int i=1;i<n;i++)
    {
        if(str[i]!=str[i-1]) {cnt++; ans=max(ans,cnt);}
        else cnt=1;
    }
    ans=min(ans,n/2);
    printf("%d\n",ans);
}