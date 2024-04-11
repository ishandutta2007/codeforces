/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-17 22:31:38
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
string s,t;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    cin>>s;cin>>t;
    if(n>m+1) {puts("NO"); return 0;}
    bool f=false;
    int now=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*')
        {
            f=true;
            now+=m-n+1;
            continue;
        }
        else
        {
            if(s[i]!=t[now]) {puts("NO"); return 0;}
            now++;
        }
    }
    if(!f&&(n!=m)) puts("NO"); else puts("YES");
    return 0;
}