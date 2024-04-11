/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-27 22:35:52
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
map<string,int> mp;
int main()
{
    scanf("%d",&n);
    string str;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        if(mp.find(str)==mp.end()) mp[str]=1;
        else mp[str]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>str;
        if(mp.find(str)==mp.end()) mp[str]=-1;
        else mp[str]--;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
        sum+=max(it->S,-it->S);
    printf("%d\n",sum/2);
    return 0;
}