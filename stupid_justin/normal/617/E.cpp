
#include<bits/stdc++.h>
#define rd(x) x=read()
#define int long long
using namespace std;
const int N=1048580;
const int maxn=1e7+5;
const int inf=0x3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while (ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,q,k,ans;
int app[N];
int a[N];
int sum[N];
int pos[N];
int ANS[N];
struct Query{int l,r,id;}Q[N];
inline bool cmp(Query a,Query b){return pos[a.l]^pos[b.l]?pos[a.l]<pos[b.l]:(pos[a.l]&1)?a.r<b.r:a.r>b.r;}
inline bool CMP(Query a,Query b){return a.id<b.id;}
inline void add(int &x){ans-=app[x]*app[x^k];app[x]++;ans+=app[x]*app[x^k];}
inline void del(int &x){ans-=app[x]*app[x^k];app[x]--;ans+=app[x]*app[x^k];}
signed main()
{
    rd(n);rd(q);rd(k);
    for (int i=1;i<=n;i++) rd(a[i]);
	for (int i=1;i<=n;i++) sum[i]=a[i]^sum[i-1];
	//for (int i=1;i<=n;i++) printf("sum[%lld]=%lld ",i,sum[i]);cout<<endl;
    for (int i=1;i<=n;i++) pos[i]=i/1800;
    for (int i=1;i<=q;i++)
    {
        rd(Q[i].l);rd(Q[i].r);Q[i].l--;
        Q[i].id=i;
    }
    sort(Q+1,Q+q+1,cmp);
    //for (int i=1;i<=n;i++) app[i]=0;
    for (int i=1,l=1,r=0;i<=q;i++)
    {
        while (r<Q[i].r) add(sum[++r]);
        while (r>Q[i].r) del(sum[r--]);
        while (l<Q[i].l) del(sum[l++]);
        while (l>Q[i].l) add(sum[--l]);

        ANS[Q[i].id]=ans;
		if (k==0) {ANS[Q[i].id]-=r-l+1;ANS[Q[i].id]/=2;}
		//printf("%lld:",Q[i].id);
		//for (int i=0;i<=10;i++) printf("%lld ",app[i]);cout<<endl;
    }
    for (int i=1;i<=q;i++) cout<<ANS[i]<<"\n";
}