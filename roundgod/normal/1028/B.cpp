/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-28 00:39:08
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
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<2229;i++) 
        if(i&1) printf("0"); else printf("9");
    puts("1");
    for(int i=1;i<2230;i++)
        if(i&1) printf("9"); else printf("0");
    return 0;
}