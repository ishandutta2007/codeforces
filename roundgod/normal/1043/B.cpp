/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-28 23:38:01
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
int n,k,a[MAXN],d[MAXN];
vector<int> ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n-1;i++) d[i]=a[i+1]-a[i];
    for(int k=1;k<=n;k++)
    {
        bool f=true;
        for(int j=0;j+k<=n-1;j++)
            if(d[j]!=d[j+k]) f=false;
        if(f) ans.push_back(k);
    }
    printf("%d\n",(int)ans.size());
    for(auto it:ans) printf("%d ",it);
    return 0;
}