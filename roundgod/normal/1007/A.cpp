/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-13 22:23:41
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
multiset<int> s;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int ans=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(s.size()==0) s.insert(a[i]);
        else 
        {
            auto it=s.begin();
            //printf("%d %d\n",*it,a[i]);
            if(*it<a[i])
            {
                ans++;
                s.erase(it);
            }
            s.insert(a[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}