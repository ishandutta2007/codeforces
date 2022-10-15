#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int blocks=1200;
int tot,tcnt,qid;
struct query
{
    int l,r,ti,id;
}Q[MAXN];
int n,q,cnt[MAXM],ccnt[MAXN],ans,a[MAXN];
P change[MAXN];
int res[MAXN],st[MAXN],sl[MAXN],sr[MAXN];
bool cmp(query x,query y)
{
    if(x.l/blocks!=y.l/blocks) return x.l/blocks<y.l/blocks;
    if(x.r/blocks!=y.r/blocks) return x.r/blocks<y.r/blocks;
    if(x.r/blocks&1) return x.ti>y.ti; else return x.ti<y.ti;
}
void add(int pos)
{
	ccnt[cnt[a[pos]]]--;
    cnt[a[pos]]++;
	ccnt[cnt[a[pos]]]++;
    for(int i=1;;i++) if(!ccnt[i]) {ans=i; break;}
}
void del(int pos)
{
    ccnt[cnt[a[pos]]]--;
    cnt[a[pos]]--;
	ccnt[cnt[a[pos]]]++;
    for(int i=1;;i++) if(!ccnt[i]) {ans=i; break;}
}
void modify(int ti,int num)
{
    if(change[ti].F>=Q[num].l&&change[ti].F<=Q[num].r)
    {
		ccnt[cnt[a[change[ti].F]]]--;
        cnt[a[change[ti].F]]--;
		ccnt[cnt[a[change[ti].F]]]++;
		ccnt[cnt[change[ti].S]]--;
        cnt[change[ti].S]++;
		ccnt[cnt[change[ti].S]]++;
		for(int i=1;;i++) if(!ccnt[i]) {ans=i; break;}
    }
    swap(a[change[ti].F],change[ti].S);
}
vector<int> dis;
int main()
{
    scanf("%d%d",&n,&q);
	memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) dis.push_back(a[i]);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&st[i],&sl[i],&sr[i]);
		if(st[i]==2) dis.push_back(sr[i]);
    }
	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(),dis.end()),dis.end());
	for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
	for(int i=1;i<=q;i++) if(st[i]==2) sr[i]=lower_bound(dis.begin(),dis.end(),sr[i])-dis.begin()+1;
	for(int i=1;i<=q;i++)
    {
        if(st[i]==1) Q[++tot]=(query){sl[i],sr[i],tcnt,++qid};
        else change[++tcnt]=P(sl[i],sr[i]);
    }
    sort(Q+1,Q+tot+1,cmp);
    int l=1,r=0,ti=0;
    for(int i=1;i<=tot;i++)
    {
        while(l>Q[i].l) add(--l);
        while(r<Q[i].r) add(++r);
        while(l<Q[i].l) del(l++);
        while(r>Q[i].r) del(r--);
        while(ti<Q[i].ti) modify(++ti,i);
        while(ti>Q[i].ti) modify(ti--,i);
        res[Q[i].id]=ans;
    }
    for(int i=1;i<=qid;i++) printf("%d\n",res[i]);
    return 0;
}