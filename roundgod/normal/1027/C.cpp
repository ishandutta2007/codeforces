/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 22:53:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
map<int,int> mp;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        scanf("%d",&n);
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            mp[x]++;
        }
        int last=-1;
        int id1=-1,id2=-1;
        double ans=1e9;
        bool f=false;
        for(auto it:mp)
        {
            if(it.S<2) continue;
            if(it.S>=4)
            {
                printf("%d %d %d %d\n",it.F,it.F,it.F,it.F);
                f=true;
                break;
            }
            if(last==-1) {last=it.F; continue;}
            if((double)it.F/last<ans)
            {
                ans=(double)it.F/last;
                id1=last;id2=it.F;
            }
            last=it.F;
        }
        if(f) continue;
        printf("%d %d %d %d\n",id1,id1,id2,id2);
    }
    return 0;
}