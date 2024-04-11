#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("Ofast,no-stack-protector")

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct MSG
{
	int num,cnt;
	inline MSG(){num=cnt=0;}
	inline MSG(const int a,const int b){num=a,cnt=b;}
	inline void operator=(const MSG &m){num=m.num,cnt=m.cnt;}
};
struct node
{
	int l,r;
	MSG msg[5];
	node *lson,*rson;
	/*inline void disp()
	{
		cout<<l<<' '<<r<<' ';
		for(int i=1;i<=4;i++)cout<<msg[i].num<<' ';cout<<endl;
	}*/
}*root,pool[633333];
inline void upd(node *x)
{
	x->msg[1]=x->lson->msg[1];
	x->msg[2]=x->lson->msg[2];
	x->msg[3]=x->lson->msg[3];
	x->msg[4]=x->lson->msg[4];
	for(int i=1;i<=4;i++)
	{
		MSG qwq=x->rson->msg[i];
		if(qwq.cnt==0)continue;
		int minp=1;
		if(x->msg[2].cnt<x->msg[minp].cnt)minp=2;
		if(x->msg[3].cnt<x->msg[minp].cnt)minp=3;
		if(x->msg[4].cnt<x->msg[minp].cnt)minp=4;
		if(qwq.num==x->msg[1].num)
		{
			x->msg[1].cnt+=qwq.cnt;
			continue;
		}
		else if(qwq.num==x->msg[2].num)
		{
			x->msg[2].cnt+=qwq.cnt;
			continue;
		}
		else if(qwq.num==x->msg[3].num)
		{
			x->msg[3].cnt+=qwq.cnt;
			continue;
		}
		else if(qwq.num==x->msg[4].num)
		{
			x->msg[4].cnt+=qwq.cnt;
			continue;
		}
		if(qwq.cnt<=x->msg[minp].cnt)
		{
			x->msg[1].cnt-=qwq.cnt;
			x->msg[2].cnt-=qwq.cnt;
			x->msg[3].cnt-=qwq.cnt;
			x->msg[4].cnt-=qwq.cnt;
		}
		else
		{
			int tmp=x->msg[minp].cnt;
			x->msg[minp]=qwq;
			if(tmp)
			{
				x->msg[1].cnt-=tmp;
				x->msg[2].cnt-=tmp;
				x->msg[3].cnt-=tmp;
				x->msg[4].cnt-=tmp;
			}
		}
	}
}
int top;
vector<int> v[333333];
int a[333333];
node *build(int l,int r)
{
	node *tmp=&pool[top++];
	tmp->l=l;tmp->r=r;
	if(l==r)
	{
		tmp->msg[1].num=a[l];
		tmp->msg[1].cnt=1;
	}
	else
	{
		int mid=(l+r)/2;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
		upd(tmp);
	}
	return tmp;
}
MSG rett[233][5];
int topr;
MSG* query(node *cur,int l,int r)//pair:(num,cnt)
{
//	cout<<"query "<<cur->l<<' '<<cur->r<<' '<<l<<' '<<r<<endl;
	if(cur->l==l&&cur->r==r)
	{
		MSG *ret=rett[topr++];
		for(int i=1;i<=4;i++)
			ret[i]=cur->msg[i];
		return ret;
	}
	if(cur->lson->r>=r)return query(cur->lson,l,r);
	if(cur->rson->l<=l)return query(cur->rson,l,r);
	MSG *ret=query(cur->lson,l,cur->lson->r);
	MSG *rq=query(cur->rson,cur->rson->l,r);
	for(int i=1;i<=4;i++)
	{
		MSG qwq=rq[i];
		if(qwq.cnt==0)continue;
		int minp=1;
		if(ret[2].cnt<ret[minp].cnt)minp=2;
		if(ret[3].cnt<ret[minp].cnt)minp=3;
		if(ret[4].cnt<ret[minp].cnt)minp=4;
		if(qwq.num==ret[1].num)
		{
			ret[1].cnt+=qwq.cnt;
			continue;
		}
		else if(qwq.num==ret[2].num)
		{
			ret[2].cnt+=qwq.cnt;
			continue;
		}
		else if(qwq.num==ret[3].num)
		{
			ret[3].cnt+=qwq.cnt;
			continue;
		}
		else if(qwq.num==ret[4].num)
		{
			ret[4].cnt+=qwq.cnt;
			continue;
		}
		if(qwq.cnt<=ret[minp].cnt)
		{
			ret[1].cnt-=qwq.cnt;
			ret[2].cnt-=qwq.cnt;
			ret[3].cnt-=qwq.cnt;
			ret[4].cnt-=qwq.cnt;
		}
		else
		{
			int tmp=ret[minp].cnt;
			ret[minp]=qwq;
			if(tmp)
			{
				ret[1].cnt-=tmp;
				ret[2].cnt-=tmp;
				ret[3].cnt-=tmp;
				ret[4].cnt-=tmp;
			}
		}
	}
	return ret;
}
inline int count(int pos,int x)
{
//	cout<<"count "<<pos<<' '<<x<<endl;
	int l=0,r=v[x].size()-1;
	while(l<r)
	{
		int mid=(l+r+1)/2,tmp=v[x][mid];
		if(tmp>pos)r=mid-1;
		else if(tmp<pos)l=mid;
		else l=r=mid;
	}
//	cout<<"======"<<l<<endl;
	return l;
}
inline int read()
{
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
int arr[13],qaq;
inline void write(int x)
{
	qaq=0;
	while(x)arr[qaq++]=x%10,x/=10;
	while(qaq--)putchar(arr[qaq]+'0');
	putchar('\n');
}
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("dump.txt","w",stdout);
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(v[a[i]].empty())v[a[i]].push_back(0);
		v[a[i]].push_back(i);
	}
	root=build(1,n);
	int l,r,k;
	while(m--)
	{
		l=read();r=read();k=read();
		topr=0;
		MSG *ans=query(root,l,r);
		int minelem=999999;
		for(int i=1;i<=4;i++)
		{
//			cout<<ans[i].num<<' '<<ans[i].cnt<<endl;
			if(ans[i].num<minelem&&(count(r,ans[i].num)-count(l-1,ans[i].num))*k>(r-l+1))
				minelem=ans[i].num;
		}
//		cout<<"get "<<ans<<endl;
		if(minelem==999999)printf("-1\n");
		else write(minelem);
	}
	return 0;
}