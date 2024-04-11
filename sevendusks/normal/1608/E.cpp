 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int n,p[4],bx[N],wx,by[N],wy,sum[N][4];
vector <int> wh[N];
struct node
{
	int x,y,c;
}sh[N];
bool cmp(node a,node b){return a.x<b.x;}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit
{
	int sh[N];
	void init(){memset(sh,0,sizeof(sh));}
	int lowbit(int x){return x&(-x);}
	void change(int x,int v){while(x<=n)sh[x]+=v,x+=lowbit(x);}
	int query(int x){int ans=0;while(x)ans+=sh[x],x-=lowbit(x);return ans;}
	int ask(int l,int r){return query(r)-query(l-1);}
}T[4];
int g(int l,int r,int c){return sum[r][c]-sum[l-1][c];}
void init()
{
	memset(sum,0,sizeof(sum));wx=wy=0;
	for (int i=1;i<=n;i++) bx[++wx]=sh[i].x;
	sort(bx+1,bx+1+wx);wx=unique(bx+1,bx+1+wx)-bx-1;
	for (int i=1;i<=n;i++) sh[i].x=lower_bound(bx+1,bx+1+wx,sh[i].x)-bx;
	for (int i=1;i<=n;i++) by[++wy]=sh[i].y;
	sort(by+1,by+1+wy);wy=unique(by+1,by+1+wy)-by-1;
	for (int i=1;i<=n;i++) sh[i].y=lower_bound(by+1,by+1+wy,sh[i].y)-by;
	sort(sh+1,sh+1+n,cmp);
	for (int i=1;i<=n;i++) sum[sh[i].x][sh[i].c]++;
	for (int i=1;i<=wx;i++) for (int j=1;j<=3;j++) sum[i][j]+=sum[i-1][j];
}
int solve()
{
	for (int i=1;i<=wx;i++) wh[i].clear();
	for (int i=1;i<=n;i++) wh[sh[i].x].push_back(i);
	for (int i=1;i<=3;i++) p[i]=i;
	int ans=1;
	do
	{
		for (int i=2;i<=wx;i++)
		{
			int A=sum[i-1][p[1]],l=i,r=wx-1;
			while (l<r)
			{
				int mid=l+((r-l+1)>>1);
				if (g(i,mid,p[2])<=g(mid+1,wx,p[3])) l=mid;
				else r=mid-1;
			}
			ans=max(ans,min({A,g(i,l,p[2]),g(l+1,wx,p[3])}));
			l++;
			ans=max(ans,min({A,g(i,l,p[2]),g(l+1,wx,p[3])}));
		}
	}while(next_permutation(p+1,p+4));
	for (int i=1;i<=3;i++) p[i]=i;
	auto find=[](int A,int &ans)
	{
		int l=1,r=wy-1;
		while (l<r)
		{
			int mid=l+((r-l+1)>>1);
			if (T[p[2]].ask(1,mid)<=T[p[3]].ask(mid+1,wy)) l=mid;
			else r=mid-1;
		}
		ans=max(ans,min({A,T[p[2]].ask(1,l),T[p[3]].ask(l+1,wy)}));
		l++;
		ans=max(ans,min({A,T[p[2]].ask(1,l),T[p[3]].ask(l+1,wy)}));
	};
	do
	{
		T[p[2]].init();T[p[3]].init();
		for (int i=wx;i>=1;i--)
		{
			int A=g(1,i,p[1]);
			find(A,ans);
			for (int j:wh[i]) if (sh[j].c!=p[1]) T[sh[j].c].change(sh[j].y,1);
		}
	} while (next_permutation(p+1,p+4));
	for (int i=1;i<=3;i++) p[i]=i;
	do
	{
		T[p[2]].init();T[p[3]].init();
		for (int i=1;i<=wx;i++)
		{
			int A=g(i,wx,p[1]);
			find(A,ans);
			for (int j:wh[i]) if (sh[j].c!=p[1]) 
				T[sh[j].c].change(sh[j].y,1);
		}
	} while (next_permutation(p+1,p+4));
	return ans;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) sh[i]=(node){read(),read(),read()};
	init();
	int ans=solve();
	for (int i=1;i<=n;i++) swap(sh[i].x,sh[i].y);
	init();
	// for (int i=1;i<=n;i++) printf("%d %d %d\n",sh[i].x,sh[i].y,sh[i].c);
	ans=max(ans,solve());
	printf("%d\n",ans*3);
}