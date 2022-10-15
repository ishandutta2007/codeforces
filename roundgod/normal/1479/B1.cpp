#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
vector<P> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int c=-1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(c==-1)
        {
            c=a[i];
            cnt=1;
        }
        else if(c!=a[i])
        {
            v.push_back(P(c,cnt));
            c=a[i]; cnt=1;
        }
        else cnt++;
    }
    v.push_back(P(c,cnt));
    int ans=0,now=0;
    while(now<(int)v.size())
    {
        if(v[now].S>1) {ans+=2; now++; continue;}
        int nxt=now;
        while(nxt+1<(int)v.size()&&v[nxt+1].S==1) nxt++;
        int c1=(now==0?0:v[now-1].F);
        int c2=(nxt==(int)v.size()-1?-1:v[nxt+1].F);
        if(now==nxt)
        {
            if(c1!=c2) ans++;
        }
        else if(c1==c2) 
        {
            bool f=false;
            if(now+1==nxt) f=true;
            for(int j=now;j<=nxt;j++) if(v[j].F!=c1&&(j==now?c1:v[j-1].F)!=(j==nxt?c2:v[j+1].F)) {f=true; break;}
            if(f) ans+=nxt-now+1; else ans+=nxt-now;
        }
        else ans+=nxt-now+1;
        now=nxt+1;
    }
    printf("%d\n",ans);
    return 0;
}