/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-11 22:17:37
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
int n,x,y;
int main()
{
    scanf("%d",&n);
    int d=n/2;
    printf("? %d\n",1);
    fflush(stdout);
    scanf("%d",&x);
    printf("? %d\n",1+d);
    fflush(stdout);
    scanf("%d",&y);
    if(x==y) {printf("! %d\n",1); return 0;}
    int l=0,r=d;
    int dd=y-x;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        printf("? %d\n",1+mid);
        fflush(stdout);
        scanf("%d",&x);
        printf("? %d\n",1+d+mid);
        fflush(stdout);
        scanf("%d",&y);
        if(x==y) {printf("! %d\n",1+mid); return 0;}
        if((y-x)*dd>0) l=mid; else r=mid;
    }
    printf("! -1");
    return 0;
}