#include <bits/stdc++.h>
#define MAXN 310000
using namespace std;
/*  									*/ 

//Segment_Tree1  
//Segment_Tree1(int _l=0,int _r=MAXN)		  
//void Clear()	 							 
//void Build(DataType *a)					a 
//void Add(int L,int R,DataType x) 			 
//DataType Qmin(int L,int R) 				 
//DataType Qmax(int L,int R) 				 
//DataType Qsum(int L,int R) 				 


typedef int DataType;
#define MID ((l+r)>>1)
#define LS (pos<<1)
#define RS (pos<<1|1)
class Segment_Tree1 
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
	
	Segment_Tree1(int _l=0,int _r=MAXN)
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
	
	~Segment_Tree1()
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
typedef Segment_Tree1 SGT;


/*  									*/ 

int n;
int p[MAXN];
int pos[MAXN];
int q[MAXN];
int ans; 
int main()
{
	cin>>n;
	SGT sgt(0,n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	ans=n;
	cout<<ans<<' ';
	sgt.Add(1,pos[n],1);
	for (int i=1;i<n;i++)
	{
		scanf("%d",&q[i]);
		sgt.Add(1,q[i],-1);
		while (sgt.Qmax(1,n)<=0)
		{
			ans--;
			sgt.Add(1,pos[ans],1);
		}
		printf("%d ",ans);
	}
	return 0;
}