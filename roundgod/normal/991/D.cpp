/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-24 00:02:30
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
string str1,str2;
int main()
{
    cin>>str1;
    cin>>str2;
    int ans=0;
    n=str1.size();
    if(n==1)
    {
        puts("0");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(str1[i]=='X'&&str2[i]=='X') continue;
        if(i!=0)
        {
            if(str1[i]=='0'&&str2[i]=='0')
            {
                if(str1[i-1]=='0')
                {
                    str1[i-1]=str1[i]=str2[i]='X';
                    ans++;
                    continue;
                }
                if(str2[i-1]=='0')
                {
                    str2[i-1]=str2[i]=str1[i]='X';
                    ans++;
                    continue;
                }
            }
        }
        if(i==n-1) break;
        if(str1[i]=='0'&&str2[i]=='0')
        {
            if(str1[i+1]=='0')
            {
                str1[i+1]=str1[i]=str2[i]='X';
                ans++;
                continue;
            }
            if(str2[i+1]=='0')
            {
                str2[i+1]=str1[i]=str2[i]='X';
                ans++;
                continue;
            }
        }
        if(str1[i+1]=='0'&&str2[i+1]=='0')
        {
            if(str1[i]=='0')
            {
                str1[i+1]=str2[i+1]=str1[i]='X';
                ans++;
                continue;
            }
            if(str2[i]=='0')
            {
                str1[i+1]=str2[i+1]=str2[i]='X';
                ans++;
                continue;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}