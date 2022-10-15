/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-19 00:34:12
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
int x,y,z,t1,t2,t3;
int main()
{
    scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
    int cnt1=max(x-y,y-x);
    int cnt2=max(x-z,z-x);
    int stairs=cnt1*t1;
    int elevator=cnt1*t2+3*t3+cnt2*t2;
    if(elevator<=stairs) puts("YES"); else puts("NO");
    return 0;
}