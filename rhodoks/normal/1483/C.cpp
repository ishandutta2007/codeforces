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

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;




#define MID ((l+r)>>1)
#define LS (pos<<1)
#define RS (pos<<1|1)
template <class DataType> 
class Segment_Tree
{
	int l,r;
	DataType *mx,*tag;
	DataType inf;
	
	void pushdown(int pos,int l,int r)
	{
		mx[LS]+=tag[pos];
		mx[RS]+=tag[pos];
		tag[LS]+=tag[pos];
		tag[RS]+=tag[pos];
		tag[pos]=0;
	}
	
	void pushup(int pos,int l,int r)
	{
		mx[pos]=max(mx[LS],mx[RS])+tag[pos];
	}
	
	void build(int pos,int l,int r,DataType *a)
	{
		if (l==r)
		{
			mx[pos]=a[l];
			return;
		}
		build(LS,l,MID,a);
		build(RS,MID+1,r,a);
		pushup(pos,l,r);
	}
	
	void modify(int pos,int l,int r,int L,int R,DataType k)
	{
		if (r<L || l>R)
			return;
		if (l>=L && r<=R)
		{
			tag[pos]+=k;
			mx[pos]+=k;
			return;
		}
		pushdown(pos,l,r);
		modify(LS,l,MID,L,R,k);
		modify(RS,MID+1,r,L,R,k);
		pushup(pos,l,r);
	}
	
	DataType querymx(int pos,int l,int r,int L,int R)
	{
		if (r<L || l>R)
			return -inf;
		if (l>=L && r<=R)
			return mx[pos];
		pushdown(pos,l,r);
		return max(querymx(LS,l,MID,L,R),querymx(RS,MID+1,r,L,R));
	}
	
	
	void output(int pos,int l,int r)
	{
		if (l==r)
		{
			cout<<mx[pos]<<' ';
			return;
		}
		pushdown(pos,l,r);
		output(LS,l,MID);
		output(RS,MID+1,r);
	}
	
	public:
	void Clear()
	{
		for (int i=0;i<(r-l+5)<<2;i++)
			mx[i]=tag[i]=0;
	}
	
	Segment_Tree(int _l=0,int _r=MAXN)
	{
		memset(&inf,0x3f,sizeof(DataType));
		l=_l;
		r=_r;
		mx=new DataType[(r-l+5)<<2];
		tag=new DataType[(r-l+5)<<2];
		Clear();
	}
	
	~Segment_Tree()
	{
		delete mx;
		delete tag;
	}
	
	void Build(DataType *a)
	{
		build(1,l,r,a);
	}
	
	void Add(int L,int R,DataType x)
	{
		modify(1,l,r,L,R,x);
	}
	
	DataType Qmax(int L,int R)
	{
		return querymx(1,l,r,L,R);
	}
	
	void Output()
	{
		output(1,l,r);
	}
};


typedef pair<int,int> pii;
int n;
int b[MAXN],h[MAXN];
set<int> st;


multiset<LL,greater<LL> > val;
int stak[MAXN];
int stakptr;
void init()
{

}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&h[i]); 
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]); 
	Segment_Tree<LL> dp(0,n+1);
	val.insert(-LLINF);
	//dp.Add(1,n+1,-LLINF);
	stak[++stakptr]=0;
	for (int i=1;i<=n;i++)
	{
		int id=0;
		while (h[i]<h[stak[stakptr]])
		{
			id=stak[stakptr];
			//WRT(dp.Qmax(h[stak[stakptr-1]],id-1)+b[id])
			val.erase(val.find(dp.Qmax(stak[stakptr-1],id-1)+b[id]));
			stakptr--;
		}
		id=stak[stakptr];
		LL dpval=dp.Qmax(id,i-1)+b[i];
		dpval=max(dpval,*val.begin());
		dp.Add(i,i,dpval);
		stak[++stakptr]=i;
		val.insert(dp.Qmax(stak[stakptr-1],i-1)+b[i]);
		//WRT(dp.Qmax(h[stak[stakptr-1]],i-1)+b[i])
	}
	cout<<dp.Qmax(n,n)<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}