#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x7f7f7f7f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

#define int LL
int n,m,p;
int nn,mm;

int a[MAXN],ca[MAXN];
int b[MAXN],cb[MAXN];
int x[MAXN],y[MAXN],z[MAXN];
int ord[MAXN];
typedef pair<int,int> pii;
vector<pii> v;
int mx[MAXM<<3],tag[MAXM<<3];

bool cmp(int i,int j)
{
	return x[i]<x[j];
}

bool cmp1(pii p1,pii p2)
{
	if (p1.first==p2.first)
		return p1.second>p2.second;
	return p1.first<p2.first;
}

void init()
{
	cin>>n>>m>>p;
	for (int i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i],&ca[i]);
		a[i]--;
	}
	for (int i=0;i<m;i++)
	{
		scanf("%lld%lld",&b[i],&cb[i]);
		b[i]--;
	}
	for (int i=1;i<=p;i++)
	{
		scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		ord[i]=i;
	}
	
	v.clear();
	for (int i=0;i<n;i++)
		v.push_back({a[i],ca[i]});
	sort(v.begin(),v.end());
	for (int i=0;i<n;i++)
		{
			a[nn]=v[i].first;
			ca[nn++]=v[i].second;
		}
		
		
	v.clear();
	for (int i=0;i<m;i++)
		v.push_back({b[i],cb[i]});
	sort(v.begin(),v.end(),cmp1);
	for (int i=m-1;i>=0;i--)
		if (i==m-1 || v[i].second<cb[mm-1])
		{
			b[mm]=v[i].first;
			cb[mm++]=v[i].second;
			//cout<<b[mm-1]<<' '<<cb[mm-1]<<endl;
		}
		
	sort(ord+1,ord+p+1,cmp);
}

#define MID (l+r)/2
#define LS (pos<<1)
#define RS (pos<<1|1)
const int N=1000010;
void pushdown(int pos)
{
	mx[LS]+=tag[pos];
	mx[RS]+=tag[pos];
	tag[LS]+=tag[pos];
	tag[RS]+=tag[pos];
	tag[pos]=0;
}

void pushup(int pos)
{
	mx[pos]=max(mx[LS],mx[RS])+tag[pos];
}

void add(int pos,int l,int r,int L,int R,int x)
{
	if (L>r || R<l)
		return;
	if (r<=R && l>=L)
	{
		tag[pos]+=x;
		mx[pos]+=x;
		return;
	}
	pushdown(pos);
	add(LS,l,MID,L,R,x);
	add(RS,MID+1,r,L,R,x);
	pushup(pos);
}

int query()
{
	return mx[1];
}

LL ans=-LLINF;
void work()
{
	add(1,0,N,b[0]+1,N,-INF);
	for (int i=0;i<mm-1;i++)
		add(1,0,N,b[i+1]+1,b[i],-cb[i]);
	add(1,0,N,0,b[mm-1],-cb[mm-1]);
	int ptr=0;
	for (int i=0;i<nn;i++)
	{
		//WRT(query());
		while (ptr<p && x[ord[ptr+1]]<=a[i])
		{
			ptr++;
			add(1,0,N,y[ord[ptr]],N,z[ord[ptr]]);
			//WRT(y[ptr]);
			//WRT(z[ptr]);
		}
		//WRT(query());
		//WRT(ca[i]);
		ans=max(ans,-(LL)ca[i]+query());
	}
}

signed main()
{
	init();
	work();
	cout<<ans;
	return ~~(0^_^0);
}