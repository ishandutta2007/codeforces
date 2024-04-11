#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
set<int> s;
map<pair<int,int>,int> ss;
struct query
{
	int pos,l,r;
}qu[233333];
int top;
int ans[233333];
struct node
{
	int l,r;
	vector<int> vec;
	node *lson,*rson;
}*root,pool[555555];
int ntop;
node *build(int l,int r)
{
	node *tmp=&pool[ntop++];tmp->l=l;tmp->r=r;
	if(l!=r)
	{
		int mid=(l+r)/2;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
	}
	return tmp;
}
void change(node *cur,int l,int r,int pos)
{
	if(cur->l==l&&cur->r==r)
	{
		cur->vec.push_back(pos);
		return;
	}
	if(cur->lson->r>=r)change(cur->lson,l,r,pos);
	else if(cur->rson->l<=l)change(cur->rson,l,r,pos);
	else change(cur->lson,l,cur->lson->r,pos),change(cur->rson,cur->rson->l,r,pos);
}
void gao(node *cur,int maxx)
{
//	cerr<<"gao "<<cur->l<<' '<<cur->r<<' '<<maxx<<endl;
	vector<int> tmp;
	for(auto x:cur->vec)
	{
//		cerr<<"find "<<x<<endl;
		auto it=s.lower_bound(x);
		tmp.push_back(*it);
		maxx=max(maxx,*it);
//		cerr<<"del "<<*it<<endl;
		s.erase(it);
	}
	if(cur->l==cur->r)
	{
		ans[cur->l]=maxx;
	}
	else{gao(cur->lson,maxx);gao(cur->rson,maxx);}
	for(auto x:tmp)
	{
//		cerr<<"add "<<x<<endl;
		s.insert(x);
	}
//	cerr<<"endgao "<<cur->l<<' '<<cur->r<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(ss.find(make_pair(x,y))!=ss.end())
		{
			int t=ss[make_pair(x,y)];
			qu[t].r=i-1;
			ss.erase(make_pair(x,y));
		}
		else
		{
			++top;
			qu[top].pos=y+abs(x-k);
			qu[top].l=i;
			qu[top].r=m;
			ss[make_pair(x,y)]=top;
		}
	}
	root=build(1,m);
	for(int i=1;i<=top;i++)
	{
//		cerr<<qu[i].l<<' '<<qu[i].r<<' '<<qu[i].pos<<endl;
		change(root,qu[i].l,qu[i].r,qu[i].pos);
	}
	for(int i=1;i<=700000;i++)
	{
		s.insert(i);
	}
	gao(root,0);
	for(int i=1;i<=m;i++)
	{
		cout<<max(ans[i]-n,0)<<endl;
	}
	return 0;
}