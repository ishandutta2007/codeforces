/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-08 22:18:23
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
vector<int> res;
int main()
{
    scanf("%d",&n);
    int ans=INF,id=-1;
    for(int i=1;i<=n;i++)
    {
        if((n-1)/i+1+i<=ans)
        {
            ans=(n-1)/i+1+i;
            id=i;
        }
    }
    for(int i=1;i<=(n-1)/id+1;i++)
        for(int j=min(n,i*id);j>=(i-1)*id+1;j--)
            res.push_back(j);
    for(auto x:res) printf("%d ",x);
    return 0;
}