/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-08 22:04:45
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
int n;
P a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a1,a2,a3,a4;
        scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
        a[i].F=-a1-a2-a3-a4;
        a[i].S=i+1;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i].S==1)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}