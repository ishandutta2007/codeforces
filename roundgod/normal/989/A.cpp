/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-12 19:24:24
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
string str;
int main()
{
    cin>>str;
    bool f=false;
    for(int i=1;i<str.size();i++)
    {
        if(str[i]=='A'&&str[i-1]=='B'&&str[i+1]=='C') f=true;
        if(str[i]=='A'&&str[i-1]=='C'&&str[i+1]=='B') f=true;
        if(str[i]=='B'&&str[i-1]=='A'&&str[i+1]=='C') f=true;
        if(str[i]=='B'&&str[i-1]=='C'&&str[i+1]=='A') f=true;
        if(str[i]=='C'&&str[i-1]=='A'&&str[i+1]=='B') f=true;
        if(str[i]=='C'&&str[i-1]=='B'&&str[i+1]=='A') f=true;
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}