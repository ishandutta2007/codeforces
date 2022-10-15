/*************************************************************************
    > File Name: 2B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 01:45:13
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-12
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double x,y;
int main()
{
    scanf("%lf%lf",&x,&y);
    double tmp1=log(x),tmp2=log(y);
    double res1=y*tmp1,res2=x*tmp2;
    if(res1>res2) puts(">");
    else if(res1<res2) puts("<");
    else puts("=");
    return 0;
}