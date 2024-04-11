/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 01:39:26
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
    //let's see it!
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i%3==1) printf("%d %d\n",(i-1)/3*2,0);
        else if(i%3==2) printf("%d %d\n",(i-1)/3*2+1,0);
        else printf("%d %d\n",(i-1)/3*2+1,3);
    }
    return 0;
}