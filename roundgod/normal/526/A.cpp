/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 10:56:17
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
int main()
{
    scanf("%d",&n);
    cin>>str;
    bool f=false;
    for(int len=1;len*4<n;len++)
    {
        for(int i=0;i+4*len<n;i++)
        {
            if(str[i]=='*'&&str[i+len]=='*'&&str[i+2*len]=='*'&&str[i+3*len]=='*'&&str[i+4*len]=='*')
            {
                f=true;
                break;
            }
        }
    }
    if(f) puts("yes"); else puts("no");
    return 0;
}