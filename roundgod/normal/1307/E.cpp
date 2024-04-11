#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s[MAXN],f[MAXN],h[MAXN];
vector<int> pos[MAXN];
vector<int> has[MAXN];
int sum[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int ans,cnt;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&s[i]);
        sum[s[i]][i]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]+=sum[i][j-1];
    for(int i=1;i<=n;i++)
    {
        pos[s[i]].push_back(i);
    }
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d",&f[i],&h[i]);
        has[f[i]].push_back(h[i]);
    }
    ans=0; cnt=1;
    for(int i=1;i<=m;i++)
    {
        int c=0,way=1;
        if(h[i]<=(int)pos[f[i]].size())
        {
            c=1;
            int rem=pos[f[i]].size()-h[i];
            int id=0;
            for(auto x:has[f[i]]) if(x<=rem&&x!=h[i]) id++;
            if(id)
            {
                c++;
                way=id;
            }
            int p=pos[f[i]][h[i]-1];
            for(int j=1;j<=n;j++)
            {
                if(j==f[i]) continue;
                if(!pos[j].size()) continue;
                int l=sum[j][p],r=sum[j][n]-sum[j][p];
                int cnt1=0,cnt2=0;
                for(auto x:has[j]) if(x<=l) cnt1++;
                for(auto x:has[j]) if(x<=r) cnt2++;
                int s=1LL*cnt1*cnt2%MOD;
                for(auto x:has[j]) if(x<=l&&x<=r) s--;
                if(s)
                {
                    c+=2;
                    way=1LL*way*s%MOD;
                }
                else if(cnt1+cnt2)
                {
                    c++;
                    way=1LL*way*(cnt1+cnt2)%MOD;
                }
            }
        }
        if(c>ans)
        {
            ans=c;
            cnt=way;
        }
        else if(c&&(c==ans))
        {
            add(cnt,way);
        }
    }
    int c=0,way=1;
    for(int i=1;i<=n;i++)
    {
        int cc=0;
        for(auto x:has[i]) if(x<=(int)pos[i].size()) cc++;
        if(cc)
        {
            c++;
            way=1LL*way*cc%MOD;
        }
    }
    if(c>ans)
    {
        ans=c;
        cnt=way;
    }
    else if(c&&(c==ans))
    {
        add(cnt,way);
    }
    printf("%d %d\n",ans,cnt);
    return 0;
}