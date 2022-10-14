#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510000
#define MAXM 410000
#define MOD 998244353
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
	DataType *mx,*mi,*sum,*tag;
	DataType inf;
	
	void pushdown(int pos,int l,int r)
	{
		mx[LS]+=tag[pos];
		mx[RS]+=tag[pos];
		mi[LS]+=tag[pos];
		mi[RS]+=tag[pos];
		sum[LS]+=tag[pos]*(MID-l+1);
		sum[RS]+=tag[pos]*(r-MID);
		tag[LS]+=tag[pos];
		tag[RS]+=tag[pos];
		tag[pos]=0;
	}
	
	void pushup(int pos,int l,int r)
	{
		mi[pos]=min(mi[LS],mi[RS])+tag[pos];
		mx[pos]=max(mx[LS],mx[RS])+tag[pos];
		sum[pos]=sum[LS]+sum[RS]+tag[pos]*(r-l+1);
	}
	
	void build(int pos,int l,int r,DataType *a)
	{
		if (l==r)
		{
			mx[pos]=mi[pos]=sum[pos]=a[l];
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
			mi[pos]+=k;
			sum[pos]+=k*(r-l+1);
			return;
		}
		pushdown(pos,l,r);
		modify(LS,l,MID,L,R,k);
		modify(RS,MID+1,r,L,R,k);
		pushup(pos,l,r);
	}
	
	DataType querymi(int pos,int l,int r,int L,int R)
	{
		if (r<L || l>R)
			return inf;
		if (l>=L && r<=R)
			return mi[pos];
		pushdown(pos,l,r);
		return min(querymi(LS,l,MID,L,R),querymi(RS,MID+1,r,L,R));
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
	
	DataType querysum(int pos,int l,int r,int L,int R)
	{
		if (r<L || l>R)
			return 0;
		if (l>=L && r<=R)
			return sum[pos];
		pushdown(pos,l,r);
		return querysum(LS,l,MID,L,R)+querysum(RS,MID+1,r,L,R);
	}
	
	public:
	void Clear()
	{
		for (int i=0;i<(r-l+5)<<2;i++)
			mx[i]=mi[i]=sum[i]=tag[i]=0;
	}
	
	Segment_Tree(int _l=0,int _r=MAXN)
	{
		memset(&inf,0x3f,sizeof(DataType));
		l=_l;
		r=_r;
		mx=new DataType[(r-l+5)<<2];
		mi=new DataType[(r-l+5)<<2];
		sum=new DataType[(r-l+5)<<2];
		tag=new DataType[(r-l+5)<<2];
		Clear();
	}
	
	~Segment_Tree()
	{
		delete mx;
		delete mi;
		delete sum;
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
	
	DataType Qmin(int L,int R)
	{
		return querymi(1,l,r,L,R);
	}
	
	DataType Qmax(int L,int R)
	{
		return querymx(1,l,r,L,R);
	}
	
	DataType Qsum(int L,int R)
	{
		return querysum(1,l,r,L,R);
	}
};

int n,m;
int a[MAXN],p[MAXN];
int b[MAXN];
int main()
{
	b[0]=-INF;
	cin>>n;
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&p[i]);
	cin>>m;
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	Segment_Tree<LL> sgt(0,m);
	sgt.Add(1,m,(LL)1e17);
	for (int i=0;i<n;i++)
	{
		int pos=upper_bound(b,b+1+m,a[i])-b-1;
		//WRT(pos);
		if (b[pos]==a[i])
		{
			LL t1=sgt.Qmax(pos-1,pos-1);
			if (p[i]<0)
				sgt.Add(pos,pos,p[i]);
			LL t2=sgt.Qmax(pos,pos);
			//cout<<t1<<" "<<t2<<endl;
			//cout<<sgt.Qmax(pos,pos)<<endl;
			if (t2>t1)
				sgt.Add(pos,pos,t1-t2);
		}
		//WRT(pos);
		if (b[pos]==a[i])
			sgt.Add(0,pos-1,p[i]);
		else
			sgt.Add(0,pos,p[i]);
		if (p[i]<0 && pos+1<=m)
			sgt.Add(pos+1,m,p[i]);
		//for (int i=0;i<=m;i++)
		//{
		//	cout<<sgt.Qmax(i,i)<<' ';
		//}
		//cout<<endl;
	}
	if (sgt.Qmax(m,m)>1e16)
		cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		cout<<sgt.Qmax(m,m);
	}
	return ~~(0^_^0);
}