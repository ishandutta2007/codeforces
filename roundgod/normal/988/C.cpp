/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-04 16:26:27
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,len,a[MAXN];
map<int,P> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&len);
        int s=0;
        for(int j=1;j<=len;j++)
        {
            scanf("%d",&a[j]);
            s+=a[j];
        }
        for(int j=1;j<=len;j++)
        {
            if(mp.find(s-a[j])!=mp.end())
            {
                P x=mp[s-a[j]];
                if(x.F==i) continue;
                puts("YES");
                printf("%d %d\n%d %d\n",x.F,x.S,i,j);
                return 0;
            }
            mp[s-a[j]]=P(i,j);
        }
    }
    puts("NO");
    return 0;
}