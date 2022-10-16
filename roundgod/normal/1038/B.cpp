/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 23:37:07
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
    int sum=(1+n)*n/2;
    for(int i=2;i*i<=sum;i++)
    {
        if(sum%i==0)
        {
            puts("Yes");
            printf("%d %d\n",1,i);
            printf("%d",n-1);
            for(int j=1;j<=n;j++)
                if(j==i) continue; else printf(" %d",j);
            puts("");
            return 0;
        }
    }
    puts("No");
    return 0;
}