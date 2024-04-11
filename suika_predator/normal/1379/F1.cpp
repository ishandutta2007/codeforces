#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r,minw,maxb,ok;
	node *lson,*rson;
	inline void upd()
	{
		if(l<r)
		{
			ok=(lson->minw>rson->maxb);
			ok&=lson->ok;ok&=rson->ok;
			minw=min(lson->minw,rson->minw);
			maxb=max(lson->maxb,rson->maxb);
		}
		else
			ok=(minw>maxb);
	}
}*root,pool[1111111];
int top;
int T,n,m,q;
node *build(int l,int r)
{
	node *tmp=&pool[top++];tmp->l=l;tmp->r=r;tmp->minw=m+1;tmp->maxb=0;tmp->ok=1;
	if(l<r)
	{
		int mid=(l+r)/2;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
	}
	return tmp;
}
void changew(node *cur,int pos,int val)
{
//	cerr<<"changew "<<cur->l<<' '<<cur->r<<' '<<pos<<' '<<val<<endl;
	if(cur->l==cur->r)
	{
		cur->minw=val;
		cur->upd();
		return;
	}
	if(pos<=cur->lson->r)changew(cur->lson,pos,val);
	else changew(cur->rson,pos,val);
	cur->upd();
}
void changeb(node *cur,int pos,int val)
{
//	cerr<<"changeb "<<cur->l<<' '<<cur->r<<' '<<pos<<' '<<val<<endl;
	if(cur->l==cur->r)
	{
		cur->maxb=val;
		cur->upd();
		return;
	}
	if(pos<=cur->lson->r)changeb(cur->lson,pos,val);
	else changeb(cur->rson,pos,val);
	cur->upd();
}

set<int> b[233333],w[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)b[i].insert(0),w[i].insert(m+1);
	root=build(1,n);
	int x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(x%2==1)
		{
			x=(x+1)/2,y=(y+1)/2;
			if(w[x].find(y)!=w[x].end())
			{
//				cerr<<"erasew "<<x<<' '<<y<<endl;
				w[x].erase(y);
			}
			else
			{
//				cerr<<"insertw "<<x<<' '<<y<<endl;
				w[x].insert(y);
			}
			changew(root,x,*w[x].begin());
		}
		else
		{
			x=x/2,y=y/2;
			if(b[x].find(y)!=b[x].end())
			{
				b[x].erase(y);
//				cerr<<"eraseb "<<x<<' '<<y<<endl;
			}
			else
			{
				b[x].insert(y);
//				cerr<<"insertb "<<x<<' '<<y<<endl;
			}
			changeb(root,x,*--b[x].end());
		}
//		for(int i=1;i<=n;i++)cerr<<"pos "<<i<<' '<<(*--b[i].end())<<' '<<(*--w[i].begin())<<endl;
		if(root->ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}