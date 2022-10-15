/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-19 00:46:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l[MAXN],r[MAXN],ans[MAXN];
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&l[i]);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    memset(used,false,sizeof(used));
    int cnt=0;
    int cur=n;
    while(cnt<n)
    {
        vector<int> v;v.clear();
        for(int j=1;j<=n;j++)
        {
            if(used[j]) continue;
            if(l[j]==0&&r[j]==0) v.push_back(j);
        }
        if(!v.size()) {puts("NO"); return 0;}
        cnt+=(int)v.size();
        for(auto it:v) used[it]=true;
        for(auto it:v) ans[it]=cur;
        cur--;
        for(auto it:v)
        {
            for(int j=1;j<it;j++)
            {
                if(!used[j]) 
                {
                    r[j]--;
                    if(r[j]<0) {puts("NO"); return 0;}
                }
            }
            for(int j=it+1;j<=n;j++)
            {
                if(!used[j])
                {
                    l[j]--;
                    if(l[j]<0) {puts("NO"); return 0;}
                }
            }
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}