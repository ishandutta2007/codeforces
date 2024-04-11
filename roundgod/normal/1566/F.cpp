#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define INF2 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<int> points;
int a[MAXN],l[MAXN],r[MAXN];
ll dp[MAXN][2];//dp[i][0/1]: processed all segments before ith segment, is the contribution left to ith added or not
vector<int> segments[MAXN];
vector<P> tmp,st;
bool cmp(int x,int y)
{
    return l[x]<l[y];
}
multiset<int> ms;
void upd(ll &x,ll y) {x=min(x,y);}
bool cmp2(P p,P q)
{
    if(p.F!=q.F) return p.F<q.F;
    return p.S>q.S;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        points.clear(); tmp.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n+2;i++) segments[i].clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            points.push_back(a[i]);
        }
        points.push_back(-INF-1);
        points.push_back(INF+1);
        sort(points.begin(),points.end());
        //n+2 points, 0 and n+1 is dummy point
        for(int i=1;i<=m;i++) 
        {
            scanf("%d%d",&l[i],&r[i]);
            int id=lower_bound(points.begin(),points.end(),l[i])-points.begin();
            if(points[id]<=r[i]) continue;
            else tmp.push_back(P(l[i],r[i]));
        }
        sort(tmp.begin(),tmp.end(),cmp2);
        st.clear();
        for(int i=0;i<(int)tmp.size();i++)
        {
            int x=tmp[i].F,y=tmp[i].S;
            while(st.size()&&st.back().F<=x&&st.back().S>=y) st.pop_back();
            st.push_back(tmp[i]);
        }
        swap(tmp,st);
        for(int i=0;i<(int)tmp.size();i++)
        {
            l[i]=tmp[i].F; r[i]=tmp[i].S;
            int id=upper_bound(points.begin(),points.end(),l[i])-points.begin()-1;
            segments[id].push_back(i);
        }
        for(int i=0;i<=n+2;i++)
            for(int j=0;j<2;j++)
                dp[i][j]=INF2;
        dp[0][0]=dp[0][1]=0;
        for(int i=0;i<=n;i++)
        {
            sort(segments[i].begin(),segments[i].end(),cmp);
            ms.clear();
            for(auto x:segments[i]) ms.insert(r[x]);
            int cur=0;
           // printf("i=%d\n",i);
            for(int j=0;j<=(int)segments[i].size();j++) //enumerate on the number of segments that go left
            {
                int lcost,rcost;
                if(i==0&&j>0) goto nextloop;
                if(i==n&&j!=(int)segments[i].size()) goto nextloop;
                lcost=(j==0?0:cur-points[i]),rcost=(j==(int)segments[i].size()?0:points[i+1]-*ms.begin());
                //printf("j=%d lcost=%d rcost=%d\n",j,lcost,rcost);
                upd(dp[i+1][0],dp[i][0]+2LL*lcost+rcost);
                upd(dp[i+1][1],dp[i][0]+2LL*lcost+2LL*rcost);
                upd(dp[i+1][0],dp[i][1]+lcost+rcost);
                upd(dp[i+1][1],dp[i][1]+lcost+2LL*rcost);
nextloop:       if(j!=(int)segments[i].size()) 
                {
                    cur=l[segments[i][j]];
                    ms.erase(ms.find(r[segments[i][j]]));
                }
            }
        }
        printf("%lld\n",dp[n+1][0]);
    }
    return 0;
}