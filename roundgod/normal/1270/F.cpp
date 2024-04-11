#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int threshold=200;
char str[MAXN];
int n,s[MAXN];
vector<int> pos;
vector<ll> vv;
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    pos.push_back(0);
    for(int i=1;i<=n;i++) 
    {
        s[i]=s[i-1]+(str[i]=='1');
        if(str[i]=='1') pos.push_back(i);
    }
    pos.push_back(n+1);
    ll ans=0;
    for(int k=1;k<=threshold;k++)
    {
        vv.clear();
        for(int i=0;i<=n;i++) vv.push_back(i-1LL*k*s[i]);
        sort(vv.begin(),vv.end());
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(vv[i]==vv[i-1]) cnt++;
            else
            {
                ans+=1LL*cnt*(cnt-1)/2;
                cnt=1;
            }
        }
        ans+=1LL*cnt*(cnt-1)/2;
    }
    for(int k=1;k*threshold<=n;k++)
    {
        if(pos.size()<k) break;
        for(int st=1;st+k-1<=(int)pos.size()-2;st++)
        {
            int ed=st+k-1;
            for(int lx=0;lx<=pos[st]-pos[st-1]-1;lx++)
            {
                int len=pos[ed]-pos[st]+1+lx;
                int rlen=len+(pos[ed+1]-pos[ed]-1);
                int lb=len/k+(len%k?1:0),rb=rlen/k;
                lb=max(lb,threshold+1);
                if(lb<=rb) ans+=rb-lb+1;
            }
            
        }
    }
    printf("%lld\n",ans);
    return 0;
}