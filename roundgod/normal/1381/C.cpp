#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,y,a[MAXN];
int cnt[MAXN],ans[MAXN];
vector<int> pos[MAXN];
vector<int> tmp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&y);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n+1;i++) {cnt[i]=0; pos[i].clear();}
        for(int i=1;i<=n;i++) 
        {
            cnt[a[i]]++;
            pos[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) ans[i]=0;
        int c=-1;
        for(int i=1;i<=n+1;i++) if(!cnt[i]) {c=i; break;}
        priority_queue<P,vector<P> > pque;
        while(pque.size()) pque.pop();
        for(int i=1;i<=n+1;i++) if(cnt[i]) pque.push(P(cnt[i],i));
        for(int i=0;i<x;i++)
        {
            P p=pque.top(); pque.pop();
            ans[pos[p.S].back()]=p.S; pos[p.S].pop_back();
            p.F--; if(p.F) pque.push(p);
        }
        tmp.clear();
        while(pque.size())
        {
            P p=pque.top(); pque.pop();
            for(int i=0;i<p.F;i++) tmp.push_back(pos[p.S].back()),pos[p.S].pop_back();
        }
        int sz=(int)tmp.size();
        int need=y-x;
        for(int i=0;i<sz;i++)
        {
            if(!need) break;
            int x=tmp[i],y=tmp[(i+sz/2)%sz];
            if(a[x]!=a[y]) {ans[x]=a[y],need--;}
        }
        if(need) {puts("NO"); continue;}
        puts("YES");
        for(int i=1;i<=n;i++) if(ans[i]==0) ans[i]=c;
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}