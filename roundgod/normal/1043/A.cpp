/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-28 23:33:49
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
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    int s=0,mx=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);s+=a[i];
        mx=max(mx,a[i]);
    }
    for(int i=mx;i<=300;i++)
    {
        if(i*n-s>s) 
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}