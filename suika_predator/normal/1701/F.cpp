#include<bits/stdc++.h>
using namespace std;
struct mat
{
	long long a[6][6];
	mat()
	{
		memset(a,0,sizeof(a));
	}
	mat(int x)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<6;i++)
			a[i][i]=x;
	}
	inline bool operator!=(const mat &m)const
	{
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				if(a[i][j]!=m.a[i][j])
					return true;
		return false;
	}
	inline mat operator*(const mat &m)const
	{
		mat ret;
		for(int i=0;i<6;i++)
			for(int k=0;k<6;k++)
				for(int j=0;j<6;j++)
					ret.a[i][j]=ret.a[i][j]+1ll*a[i][k]*m.a[k][j];
		return ret;
	}
}id(1);
struct node
{
	mat lazy;
	long long sum[6];
	int l,r;
	node *lson,*rson;
	inline void mark(const mat &x)
	{
		lazy=lazy*x;
		long long tmp[6];memset(tmp,0,sizeof(tmp));
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				tmp[j]=tmp[j]+x.a[i][j]*sum[i];
		for(int i=0;i<6;i++)
			sum[i]=tmp[i];
//		cerr<<"mark "<<l<<' '<<r<<' ';
//		for(int i=0;i<6;i++)
//			cerr<<sum[i]<<' ';
//		cerr<<endl;
	}
	inline void push()
	{
		if(lazy!=id)
		{
			lson->mark(lazy);
			rson->mark(lazy);
			lazy=id;
		}
	}
	inline void upd()
	{
		for(int i=0;i<6;i++)
			sum[i]=lson->sum[i]+rson->sum[i];
		if(l>8)return;
//		cerr<<"upd "<<l<<' '<<r<<endl;
//		for(int i=0;i<6;i++)
//			cerr<<sum[i]<<' ';
//		cerr<<endl;
	}
}*root,pool[555555];
int top;
node *build(int l,int r)
{
	node *ret=&pool[top++];
	ret->l=l;ret->r=r;
	ret->lazy=id;
	if(l!=r)
	{
		int mid=(l+r)/2;
		ret->lson=build(l,mid);
		ret->rson=build(mid+1,r);
		ret->upd();
	}
	else
	{
		ret->sum[0]=0;
		ret->sum[1]=0;
		ret->sum[2]=0;
		ret->sum[3]=0;
		ret->sum[4]=0;
		ret->sum[5]=1;
	}
	return ret;
}
void change(node *cur,int l,int r,const mat &x)
{
	if(cur->l==l&&cur->r==r)
	{
		cur->mark(x);
		return;
	}
	cur->push();
	if(cur->lson->r>=r)change(cur->lson,l,r,x);
	else if(cur->rson->l<=l)change(cur->rson,l,r,x);
	else change(cur->lson,l,cur->lson->r,x),change(cur->rson,cur->rson->l,r,x);
	cur->upd();
}
void change2(node *cur,int pos)
{
	if(cur->l==cur->r)
	{
		cur->sum[2]^=1;
		int mul=cur->sum[2]*2-1;
		cur->sum[1]+=cur->sum[4]*mul;
		cur->sum[0]+=cur->sum[3]*mul;
//		cerr<<"#######flip "<<pos<<' ';
//		for(int i=0;i<6;i++)cerr<<cur->sum[i]<<' ';
//		cerr<<endl;
		return;
	}
	cur->push();
	if(cur->lson->r>=pos)change2(cur->lson,pos);
	else change2(cur->rson,pos);
	cur->upd();
}
long long query(node *cur,int l,int r)
{
	if(cur->l==l&&cur->r==r)
		return cur->sum[0];
	cur->push();
	if(cur->lson->r>=r)return query(cur->lson,l,r);
	else if(cur->rson->l<=l)return query(cur->rson,l,r);
	else return query(cur->lson,l,cur->lson->r)+query(cur->rson,cur->rson->l,r);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int q,d;
	cin>>q>>d;
	root=build(1,200000);
	vector<int> cur(200005);
	while(q--)
	{
		int pos;
		cin>>pos;
			
		mat tr(1);
		if(cur[pos]==0)
		{
			tr.a[5][4]=1;
			tr.a[4][3]=1;
			tr.a[2][1]=1;
			tr.a[1][0]=1;
		}
		else
		{
			tr.a[5][4]=-1;
			tr.a[5][3]=1;
			tr.a[4][3]=-1;
			tr.a[2][1]=-1;
			tr.a[2][0]=1;
			tr.a[1][0]=-1;
		}
		if(pos!=1)
		{
//			cerr<<"change "<<max(1,pos-d)<<' '<<pos-1<<endl;
			change(root,max(1,pos-d),pos-1,tr);
		}
//		cerr<<"flip "<<pos<<endl;
		change2(root,pos);
		cur[pos]^=1;
		
		cout<<query(root,1,200000)<<"\n";
	}
	return 0;
}