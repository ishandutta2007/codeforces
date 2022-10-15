/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-28 23:44:52
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
int flip[MAXN];
int main()
{
    cin>>str;
    n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a')
        {
            if(i==0) flip[i]=1;
            else
            {
                flip[i-1]=1-flip[i-1];
                flip[i]=1;
            }
        }
        else continue;
    }
    for(int i=0;i<n;i++) printf("%d ",flip[i]);
    return 0;
}