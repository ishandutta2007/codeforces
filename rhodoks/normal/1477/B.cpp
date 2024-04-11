#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 2010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int tag[MAXN];
int sum[MAXN];
#define MID (l+r)/2
#define LS (pos<<1)
#define RS (pos<<1|1)
void build(int pos,int l,int r)
{
	tag[pos]=-1;
	sum[pos]=0;
	if (l==r)
	{
		return;
	}
	build(LS,l,MID);
	build(RS,MID+1,r);
}

void pushdown(int pos,int l,int r)
{
	if (tag[pos]==-1)
		return;
	tag[LS]=tag[pos];
	sum[LS]=tag[LS]*(MID-l+1);
	tag[RS]=tag[pos];
	sum[RS]=tag[RS]*(r-MID);
	tag[pos]=-1;
}

void pushup(int pos)
{
	sum[pos]=sum[LS]+sum[RS];
}

void assign(int pos,int l,int r,int L,int R,int x)
{
	if (l>R || r<L)
		return;
	if (l>=L && r<=R)
	{
		tag[pos]=x;
		sum[pos]=x*(r-l+1);
		return;
	}
	pushdown(pos,l,r);
	assign(LS,l,MID,L,R,x);
	assign(RS,MID+1,r,L,R,x);
	pushup(pos);
}

int query(int pos,int l,int r,int L,int R)
{
	if (l>R || r<L)
		return 0;
	if (l>=L && r<=R)
	{
		return sum[pos];
	}
	pushdown(pos,l,r);
	return query(LS,l,MID,L,R)+query(RS,MID+1,r,L,R);
}
int diff[MAXN];
string s,t;
int n,q,x,y;
bool ok=1;
int ql[MAXN],qr[MAXN];
void work()
{
	ok=1;
	scanf("%d%d",&n,&q);
	cin>>t>>s;
	build(1,1,n);
	for (int i=0;i<n;i++)
		assign(1,1,n,i+1,i+1,s[i]-'0');
	int ss,len;
	for (int i=1;i<=q;i++)
		scanf("%d%d",&ql[i],&qr[i]);
	for (int i=q;i>=1;i--)
	{
		x=ql[i],y=qr[i];
		ss=query(1,1,n,x,y);
		len=(y-x+1);
		//WRT(ss);
		//WRT(len);
		len=y-x+1;
		if (2*ss>=len && 2*(len-ss)>=len)
		{
			printf("NO\n");
			MRK();
			return;
		}
		if (2*ss<len)
			assign(1,1,n,x,y,0);
		else
			assign(1,1,n,x,y,1);
	}
	for (int i=1;i<=n;i++)
	{
		//WRT(query(1,1,n,i,i));
		//WRT(t[i-1])
		if (query(1,1,n,i,i)!=t[i-1]-'0')
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}