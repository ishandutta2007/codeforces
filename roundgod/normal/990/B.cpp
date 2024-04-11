/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 18:10:49
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    a[n]=INF;
    int cnt=n;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            int id=upper_bound(a,a+n+1,a[i]+k)-a-1;
            if(a[id]>a[i]) cnt--;
            //printf("%d %d %d\n",a[i],a[id],cnt);
        }
    }
    printf("%d\n",cnt);
    return 0;
}