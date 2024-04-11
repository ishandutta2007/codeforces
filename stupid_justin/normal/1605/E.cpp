#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int p[N],v[N],mu[N],tot;
void Init(int n)
{
	mu[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (!v[i]) {p[++tot]=i;mu[i]=-1;}
        for (int j=1;j<=tot && i*p[j]<=n;j++)
        {
            v[i*p[j]]=p[j];
            if (i%p[j]==0) {mu[i*p[j]]=0;break;}
            mu[i*p[j]]=-mu[i];
        }
    }
}
int n,q,now,res,cnt,k;
int a[N],b[N],c[N];
int ans[N];
struct query{int x,id;}Q[N],upd[N];
bool cmp(query a,query b){return a.x<b.x;}
signed main()
{
	Init(N-1);
	rd(n);for (int i=1;i<=n;i++) rd(a[i]);for (int i=1;i<=n;i++) rd(b[i]);
	for (int i=2;i<=n;i++) a[i]-=b[i];
	rd(q);for (int i=1;i<=q;i++) Q[i]={a[1]-read(),i};sort(Q+1,Q+q+1,cmp);
	for (int i=2;i<=n;i++) for (int j=1;j<=n/i;j++) c[i*j]+=mu[j]*a[i];
	for (int i=2;i<=n;i++) if (mu[i]!=0) upd[++k]={-c[i]/mu[i],i};sort(upd+1,upd+k+1,cmp);
	now=-1e9;
	for (int i=2;i<=n;i++) res+=abs(c[i]+mu[i]*now);

	for (int i=1,j=1;i<=q;i++)
	{
		int tmp=0;
		while (upd[j].x<=Q[i].x && j<=k)
		{
			int p=upd[j].id;
			res+=abs(c[p]+mu[p]*Q[i].x)-abs(c[p]+mu[p]*now);
			tmp++;j++;
		}
		res+=(Q[i].x-now)*cnt;
		res-=(Q[i].x-now)*(k-tmp-cnt);
		ans[Q[i].id]=res;now=Q[i].x;
		cnt+=tmp;
	}
	for (int i=1;i<=q;i++) ans[Q[i].id]+=abs(Q[i].x);
	for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
//