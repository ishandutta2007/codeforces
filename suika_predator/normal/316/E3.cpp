#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000000;
struct fib
{
	long long a,b,c;
	inline fib(){a=b=c=0;}
	inline fib(long long x,long long y,long long z){a=x%MOD,b=y%MOD,c=z%MOD;}
	inline fib operator+(const fib &x)const{return fib(a+x.a,b+x.b,c+x.c);}
	inline fib operator*(const fib &x)const{return fib(a*x.a+b*x.b,a*x.b+b*x.c,b*x.b+c*x.c);}
	inline fib operator*(const long long x)const{return fib(a*x,b*x,c*x);}
	inline fib operator+=(const fib &x){return *this=*this+x;}
	inline fib operator*=(const fib &x){return *this=*this*x;}
	inline fib operator*=(const long long x){return *this=*this*x;}
}base(0,1,1),pw[233333];
struct node
{
	int l,r;
	long long lazy;
	fib val,par;
	node *lson,*rson;
	inline void upd2(){par=rson->par*pw[lson->r-lson->l]+lson->par;}
	inline void upd(){val=rson->val*pw[lson->r-lson->l]+lson->val;}
	inline void mark(long long x){lazy+=x;lazy%=MOD;val+=par*x;}
	inline void fa_lazy(){if(lazy){lson->mark(lazy);rson->mark(lazy);lazy=0;}}
}*root,pool[555555];
int n,m,top;
int v[233333];
node* build(int l,int r)
{
	node *tmp=&pool[top++];
	tmp->l=l;tmp->r=r;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
		tmp->upd2();tmp->upd();
	}
	else
	{
		tmp->par=base;
		tmp->val=tmp->par*v[l];
	}
	return tmp;
}
void change(node *cur,int pos,int x)
{
	if(cur->l==cur->r)
	{
		cur->val=cur->par*x;
		return;
	}
	cur->fa_lazy();
	if(pos<=cur->lson->r)change(cur->lson,pos,x);
	else change(cur->rson,pos,x);
	cur->upd();
}
void add(node *cur,int l,int r,int x)
{
	if(cur->l==l&&cur->r==r)
	{
		cur->mark(x);
		return;
	}
	cur->fa_lazy();
	if(cur->lson->r>=r)add(cur->lson,l,r,x);
	else if(cur->rson->l<=l)add(cur->rson,l,r,x);
	else add(cur->lson,l,cur->lson->r,x),add(cur->rson,cur->rson->l,r,x);
	cur->upd();
}
fib query(node *cur,int l,int r)
{
	if(cur->l==l&&cur->r==r)
		return cur->val;
	cur->fa_lazy();
	if(cur->lson->r>=r)return query(cur->lson,l,r);
	else if(cur->rson->l<=l)return query(cur->rson,l,r);
	else return query(cur->lson,l,cur->lson->r)+query(cur->rson,cur->rson->l,r)*pw[cur->lson->r-l];
}
int main()
{
	scanf("%d%d",&n,&m);
	pw[0]=base;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	root=build(1,n);
	int ty,a,b,c;
	while(m--)
	{
		scanf("%d%d%d",&ty,&a,&b);
		if(ty==1)
		{
			change(root,a,b);
		}
		else if(ty==2)
		{
			fib tmp=query(root,a,b);
//			cout<<tmp.a<<' '<<tmp.b<<' '<<tmp.c<<endl;
			printf("%lld\n",tmp.b);
		}
		else
		{
			scanf("%d",&c);
			add(root,a,b,c);
		}
	}
	return 0;
}