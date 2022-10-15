/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-01 22:04:41
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
string str;
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    cin>>str;
    int cnt=0;
    bool f=false;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')
        {
            if(!f) {cnt++; f=true;}
        }
        else f=false;
    }
    if(cnt==0) puts("0");
    else printf("%lld\n",y+1LL*(cnt-1)*min(x,y));
    return 0;
}