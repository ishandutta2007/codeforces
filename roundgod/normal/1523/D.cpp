#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p;
mt19937 wcy(time(NULL));
int cnt[(1<<15)];
string str[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++) cin>>str[i];
    int ans=-1;
    ll nmask=0;
    for(int trials=0;trials<15;trials++)
    {
        int x=wcy()%n;
        vector<int> v; v.clear();
        for(int i=0;i<m;i++) if(str[x][i]=='1') v.push_back(i);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            int mask=0;
            for(int j=0;j<(int)v.size();j++) if(str[i][v[j]]=='1') mask|=(1<<j);
            cnt[mask]++;
        }
        int sz=(int)v.size();
        for(int i=0;i<sz;i++) 
        {
            for(int mask=0;mask<(1<<sz);mask++)
                if(!(mask&(1<<i)))
                    cnt[mask]+=cnt[mask^(1<<i)];
        }
        bool changed=false;
        for(int mask=0;mask<(1<<sz);mask++)
        {
            if(cnt[mask]>=(n+1)/2&&__builtin_popcount(mask)>ans)
            {
                ans=__builtin_popcount(mask);
                nmask=mask;
                changed=true;
            }
        }
        if(changed)
        {
            ll tmp=0;
            for(int i=0;i<sz;i++) if(nmask&(1<<i)) tmp|=(1LL<<v[i]);
            nmask=tmp;
        }
    }
    for(int i=0;i<m;i++) if(nmask&(1LL<<i)) printf("1"); else printf("0");
    puts("");
    return 0;
}