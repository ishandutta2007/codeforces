/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-28 01:21:39
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
set<int> s;
char str[10];
int sl,sr,bl,br,ul,ur,x;
int main()
{
    sl=sr=INF;bl=br=0;
    scanf("%d",&n);
    s.insert(0);s.insert(INF);
    int ans=1;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        scanf("%d",&x);
        if(str[1]=='D') s.insert(x);
        else
        {
            auto it=s.find(x);
            int res=*it;
            if(res>=sl&&res<=sr&&res!=sl)
            {
                flag=false;
                continue;
            }
            if(res>=bl&&res<=br&&res!=br)
            {
                flag=false;
                continue;
            }
            bool f=false;
            if(res>=bl&&res<=br) f=true;
            if(res>=sl&&res<=sr) f=true;
            if(!f) ans=2LL*ans%MOD;
            br=0;sl=INF;
            it--; br=max(br,*it);
            it++;it++; sl=min(sl,*it);
            it--;s.erase(it);
        }
    }
    if(!flag) {puts("0"); return 0;}
    assert(br<=sl);
    auto it1=s.find(br);auto it2=s.find(sl);
    int cnt=0;
    while(it1!=it2) {cnt++; it1++;}
    ans=1LL*ans*(cnt)%MOD;
    printf("%d\n",ans);
    return 0;
}