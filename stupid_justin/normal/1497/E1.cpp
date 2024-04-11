#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=2e5+5;
const int M=1e7+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,k,ans,m,tot;
int a[N],b[N],pre[N];
int p[M],v[M],cnt;
map<int,int> Map;
void init()
{
	for (int i=2;i<M;i++)
	{
		if (!v[i]) p[++cnt]=i,v[i]=i;
		for (int j=1;j<=cnt;j++)
		{
			if (i*p[j]>M) break;
			v[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
}
vector<int> vec[N];
struct seg
{
	int l,r;
}c[N];
bool cmp(seg X,seg Y){return X.l==Y.l?X.r<Y.r:X.l<Y.l;}
struct treearray
{
    int a[N];
    inline void add(int i,int x){for (;i<=n;i+=i&-i) a[i]+=x;}
    inline int query(int i){int ret=0;for (;i;i^=i&-i) ret+=a[i];return ret;}
    inline int operator[](int x) {return query(x);}
}Tr;
signed main()
{
	init();
	int T;cin>>T;while (T--)
	{
		rd(n);rd(k);ans=1;
		for (int i=1;i<=n;i++) rd(a[i]);
		Map.clear();tot=0;
		for (int i=1;i<=n;i++) vec[i].clear();
		for (int i=1;i<=n;i++)
		{
			int tmp=a[i],x=a[i];
			while (x!=1)
			{
				if (tmp%(v[x]*v[x])==0) tmp/=v[x]*v[x];
				x/=v[x];
				
			}
			if (Map[tmp]==0) Map[tmp]=++tot;
			b[i]=Map[tmp];
			vec[b[i]].push_back(i);
		}
		int CNT=0;
		for (int i=1;i<=n;i++) pre[i]=0;
		for (int i=1;i<=tot;i++)
		{
			for (int j=1;j<vec[i].size();j++) pre[vec[i][j]]=vec[i][j-1];
		}

		for (int i=0;i<=n;i++) Tr.a[i]=0;
		for (int i=1;i<=n;i++)
		{
			if (pre[i])
			{
				if (Tr[i]-Tr[pre[i]]==0) ans++,Tr.add(i,1); 
			}
		}
		cout<<ans<<endl;
		
	}
}