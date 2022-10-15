#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN];
int pre[MAXN],nxt[MAXN];
bool deleted[MAXN];
int s,t;
P st[MAXN];
vector<int> ans;
void del(int x)
{
    deleted[x]=true;
    ans.push_back(x);
    pre[nxt[x]]=pre[x];
    nxt[pre[x]]=nxt[x];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) nxt[i]=(i==n?1:i+1);
        for(int i=1;i<=n;i++) pre[i]=(i==1?n:i-1);
        for(int i=1;i<=n;i++) deleted[i]=false;
        s=0; t=0;
        ans.clear();
        for(int i=1;i<=n;i++)
            if(__gcd(a[i],a[nxt[i]])==1)
                st[t++]=P(i,nxt[i]);
        while(s<t)
        {
            P p=st[s];
            if(deleted[p.F]||deleted[p.S]) {s++; continue;}
            del(p.S);
            if(__gcd(a[p.F],a[nxt[p.F]])==1) st[t++]=P(p.F,nxt[p.F]);
            s++;
        }
        printf("%d",(int)ans.size());
        for(auto x:ans) printf(" %d",x);
        puts("");
    }
    return 0;
}