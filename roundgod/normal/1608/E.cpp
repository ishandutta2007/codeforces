#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<P> v[3];
int p[3];
bool cmp(P x,P y)
{
    return x.S<y.S;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        v[c-1].push_back(P(x,y));
    }
    for(int i=0;i<3;i++) p[i]=i;
    int ans=0;
    do
    {
        for(int dir=0;dir<4;dir++)
        {
            for(int j=0;j<3;j++) for(auto &p:v[j]) p=P(-p.S,p.F); 
            sort(v[p[0]].begin(),v[p[0]].end());
            sort(v[p[1]].begin(),v[p[1]].end());
            int l=0,r=n/3+1;
            while(r-l>1)
            {
                int mid=(l+r)/2,pos;
                if(v[p[0]].size()<mid) {r=mid; continue;} else pos=v[p[0]][mid-1].F;
                vector<P> tmp;
                for(auto q:v[p[1]]) if(q.F>pos) tmp.push_back(q);
                if(tmp.size()<mid) {r=mid; continue;} else pos=tmp[mid-1].F;
                int cnt=0;
                for(auto q:v[p[2]]) if(q.F>pos) cnt++;
                if(cnt>=mid) l=mid; else r=mid;
            }
            ans=max(ans,l);
            sort(v[p[1]].begin(),v[p[1]].end(),cmp);
            l=0,r=n/3+1;
            while(r-l>1)
            {
                int mid=(l+r)/2,pos1,pos2;
                if(v[p[0]].size()<mid) {r=mid; continue;} else pos1=v[p[0]][mid-1].F;
                vector<P> tmp;
                for(auto q:v[p[1]]) if(q.F>pos1) tmp.push_back(q);
                if(tmp.size()<mid) {r=mid; continue;} else pos2=tmp[mid-1].S;
                int cnt=0;
                for(auto q:v[p[2]]) if(q.F>pos1&&q.S>pos2) cnt++;
                if(cnt>=mid) l=mid; else r=mid;
            }
            ans=max(ans,l);
        }
    }while(next_permutation(p,p+3));
    printf("%d\n",3*ans);
    return 0;
}