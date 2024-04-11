/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 22:39:39
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
int T,n;
string str;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cin>>str;
        bool f=true;
        for(int i=0;i<n/2;i++)
        {
            int x=max(str[i]-str[n-1-i],str[n-1-i]-str[i]);
            if(x!=2&&x!=0) f=false;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}