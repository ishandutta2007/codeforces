#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

typedef pair<int,LL> pil;
vector<pil> g[MAXN];
int depth[MAXN];
LL visit[MAXN],val[MAXN];
LL bitcnt[64][2];
LL p[64];
LL msk=0;
const LL inv2=(MOD+1)/2;
int basecnt=0;
int cnt=0; 
void insert(LL x)
{
	//WRT(x);
	//if (x)
	msk|=x;
	for (LL i=60;i>=0;i--)
	{
		if ((x>>i)&1)
		{
			if (p[i])
				x^=p[i];
			else
			{
				p[i]=x;
				basecnt++;
				return;
			}
		}
	}
}

void dfs(int pos,int f)
{
	depth[pos]=depth[f]+1;
	cnt++;
	for (int i=0;i<60;i++)
		bitcnt[i][(val[pos]>>i)&1]++;
	visit[pos]=1;
	for (auto p:g[pos])
	{
		if (p.first==f)
			continue;
		if (visit[p.first])
		{
			if (depth[pos]>depth[p.first])
				insert(val[p.first]^val[pos]^p.second);
		}
		else
		{
			val[p.first]=val[pos]^p.second;
			dfs(p.first,pos);
		}
	}
}

int n,m;
LL pow2[MAXN];

int main()
{
	LL ans=0;
	pow2[0]=1;
	for (int i=1;i<MAXN;i++)
		pow2[i]=pow2[i-1]*2%MOD; 
	int x,y;
	LL w;
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&x,&y,&w); 
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	for (int i=1;i<=n;i++)
	{
		if (visit[i])
			continue;
		for (int i=0;i<60;i++)
			bitcnt[i][0]=bitcnt[i][1]=p[i]=0;
		msk=basecnt=cnt=0;
		
		dfs(i,i);
		//cout<<cnt<<' '<<basecnt<<endl;
		LL tmp=pow2[basecnt];
		//cout<<cnt<<' '<<basecnt-1<<endl;
		LL res=0;
		for (int i=0;i<60;i++)
			if ((msk>>i)&1) 
			{
				LL c=0;
				c+=(LL)bitcnt[i][0]*(bitcnt[i][0]-1)/2%MOD;
				c+=(LL)bitcnt[i][1]*(bitcnt[i][1]-1)/2%MOD;
				c+=(LL)bitcnt[i][0]*bitcnt[i][1]%MOD;
				c=c*pow2[i]%MOD;
				c=c*inv2%MOD;
				res+=c;
			}
			else
			{
				res+=(LL)bitcnt[i][0]*bitcnt[i][1]%MOD*pow2[i]%MOD;
			}
		//WRT(res)
		//WRT(tmp);
		res%=MOD;
		res=res*tmp%MOD;
		ans+=res;
	}
	cout<<ans%MOD;
	return ~~(0^_^0);
}