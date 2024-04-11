/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-14 18:23:14
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
string str;
string str2;
int l,r;
int main()
{
    scanf("%d",&n);
    printf("0 1\n");
    fflush(stdout);
    n--;
    l=0,r=1e9;
    cin>>str;
    while(n--)
    {
        int mid=(l+r)/2;
        printf("%d %d\n",mid,1);
        fflush(stdout);
        cin>>str2;
        if(str2==str) l=mid;
        else r=mid;
    }
    assert(l<r);
    printf("%d %d %d %d\n",l,0,r,2);
    return 0;
}