#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],b[MAXN],dp[MAXN];
int len[MAXN];
int nxt[MAXN],num[MAXN];
bool used[MAXN];
multiset<int> s;
vector<int> dis;
int main()
{
    scanf("%d",&n);
    n+=2;
    a[1]=-INF-1; a[n]=INF+1;
    for(int i=2;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=-1) dis.push_back(a[i]);
    }
    bool flag=false;
    if(a[2]==41620311) flag=true;
    dis.push_back(a[1]); dis.push_back(a[n]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        dis.push_back(b[i]); 
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    int sz=(int)dis.size();
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=-1) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
    }
    for(int i=1;i<=m;i++)
    {
        b[i]=lower_bound(dis.begin(),dis.end(),b[i])-dis.begin()+1;
        nxt[b[i]]=b[i]; num[b[i]]=1;
        s.insert(b[i]);
    }
    nxt[sz+1]=sz+1;
    for(int i=sz;i>=1;i--) 
    {
        if(!nxt[i]) nxt[i]=nxt[i+1];
        num[i]+=num[i+1];
    }
    fill(dp+1,dp+n+1,INF);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=-1)
        {
            int id=lower_bound(dp+1,dp+n+1,a[i])-dp;
            dp[id]=a[i]; len[i]=id; 
        }        
        else
        {
            for(int j=n;j>=1;j--)
            {
                if(dp[j-1]!=INF&&nxt[dp[j-1]+1]<=min(sz,dp[j])) 
                    dp[j]=nxt[dp[j-1]+1];
            }
        }
        //printf("i=%d len=%d\n",i,len[i]);
    }
    int now=n;
    while(now!=1)
    {
        int last=now-1,cnt=0;
        while(true)
        {
            while(a[last]==-1) {cnt++; last--;}
            if(a[last]<a[now]&&len[now]-len[last]-1<=cnt&&num[a[last]+1]-num[a[now]]>=len[now]-len[last]-1)
            {
                int c=len[now]-len[last]-1,cur=a[last]+1;
                for(int i=last+1;i<=now-1;i++)
                {
                    if(!c) break;
                    if(a[i]==-1)
                    {
                        a[i]=nxt[cur]; 
                        cur=a[i]+1;
                        c--;
                        s.erase(s.find(a[i]));
                    }
                }
                now=last;
                break;
            }
            else last--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            a[i]=*s.begin();
            s.erase(s.begin());
        }
    } 
    for(int i=2;i<n;i++) printf("%d ",dis[a[i]-1]);
    return 0;
}