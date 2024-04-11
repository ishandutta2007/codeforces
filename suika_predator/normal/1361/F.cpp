#include<bits/stdc++.h>
using namespace std;
//-------------------------------------------
struct node
{
	int val,siz;
	node *lson,*rson,*pa;
	inline void upd(){siz=1+(lson?lson->siz:0)+(rson?rson->siz:0);}
}*root[555555],*rf,pool[11111111];
int ntop;
node* build(int w,node *p)
{
//	cerr<<"build "<<w<<endl;
	node *tmp=&pool[ntop++];
	tmp->val=w;
	tmp->siz=1;
	tmp->pa=p;
	return tmp;
}
void rot(node *x,node *&r)
{
	node *p=x->pa,*g=p->pa;
	if(x==p->lson)
	{
		p->lson=x->rson;
		if(x->rson)x->rson->pa=p;
		x->rson=p;
		p->pa=x;
		x->pa=g;
		if(g->lson==p)g->lson=x;
		else if(g->rson==p)g->rson=x;
	}
	else
	{
		p->rson=x->lson;
		if(x->lson)x->lson->pa=p;
		x->lson=p;
		p->pa=x;
		x->pa=g;
		if(g->lson==p)g->lson=x;
		else if(g->rson==p)g->rson=x;
	}
	if(r==p)r=x;
	p->upd();
	x->upd();
}
void spl(node *x,node *tar,node *&r)
{
	while(x->pa!=tar)
	{
		if(x->pa->pa==tar)
		{
			rot(x,r);
		}
		else if((x->pa->lson==x)^(x->pa->pa->lson==x->pa))
		{
			rot(x,r);rot(x,r);
		}
		else
		{
			rot(x->pa,r);rot(x,r);
		}
	}
}
void ins(node *&cur,int w,node *&r)
{
	if(!cur)
	{
		cur=build(w,rf);
		return;
	}
	cur->siz++;
	if(cur->val>w)
	{
		if(!cur->lson)
		{
			cur->lson=build(w,cur);
			spl(cur->lson,rf,r);
		}
		else
		{
			ins(cur->lson,w,r);
		}
	}
	else
	{
		if(!cur->rson)
		{
			cur->rson=build(w,cur);
			spl(cur->rson,rf,r);
		}
		else
		{
			ins(cur->rson,w,r);
		}
	}
}
node *find(node *cur,int w)
{
	if(cur->val==w)return cur;
	if(cur->val>w)return find(cur->lson,w);
	else return find(cur->rson,w);
}
long long get(node *cur,int w)
{
	if(!cur)return 0;
	if(cur->val==w)return cur->lson?cur->lson->siz:0;
	if(cur->val>w)return get(cur->lson,w);
	return (cur->lson?cur->lson->siz:0)+1+get(cur->rson,w);
}
void del(node *&r,int w)
{
	node *cur=find(r,w),*pre,*suc;
	spl(cur,rf,r);
	if(cur->lson==0)
	{
		r=cur->rson;
		if(cur->rson)cur->rson->pa=rf;
		return;
	}
	if(cur->rson==0)
	{
		r=cur->lson;
		if(cur->lson)cur->lson->pa=rf;
		return;
	}
	pre=cur->lson;
	while(pre->rson)pre=pre->rson;
	suc=cur->rson;
	while(suc->lson)suc=suc->lson;
	spl(pre,rf,r);
	spl(suc,r,r);
	suc->lson->pa=0;
	suc->lson=0;
	suc->upd();
	pre->upd();
}
//-----------------------------------------------
int n,m,q,k;
int p[555555],w[555555];
int L[555555],R[555555],pa[555555],dep[555555];
long long add[555555],siz[555555];
int top;
int solve(int l,int r,int d)
{
//	cerr<<"solve "<<l<<' '<<r<<' '<<d<<endl;
	if(l==r)
	{
		dep[l]=d;
		siz[l]=1;
		ins(root[l],p[l],root[l]);
		return l;
	}
	int minn=233333,pos=0;
	for(int i=l;i<r;i++)
	{
		if(minn>w[i])minn=w[i],pos=i;
	}
	int ll=solve(l,pos,d+1),rr=solve(pos+1,r,d+1);
	top++;
	L[top]=ll;R[top]=rr;pa[ll]=top;pa[rr]=top;dep[top]=d;siz[top]=r-l+1;
	for(int i=l;i<=r;i++)
	{
		ins(root[top],p[i],root[top]);
	}
	for(int i=pos+1;i<=r;i++)
	{
		add[top]+=get(root[L[top]],p[i]);
	}
	return top;
}
int main()
{
	ios_base::sync_with_stdio(false);
	rf=&pool[ntop++];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>w[i];
	}
	top=n;
	solve(1,n,1);
	long long ans=0;
	for(int i=n+1;i<=top;i++)
	{
//		cerr<<i<<' '<<L[i]<<' '<<R[i]<<' '<<add[i]<<endl;
		ans+=min(add[i],siz[L[i]]*siz[R[i]]-add[i]);
	}
//	for(int i=1;i<=top;i++)cerr<<i<<' '<<dep[i]<<' '<<pa[i]<<' '<<siz[i]<<endl;
	cin>>q;
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		if(x==y)
		{
			cout<<ans<<endl;
			continue;
		}
		int px=p[x],py=p[y];
		swap(p[x],p[y]);
		while(pa[x]!=pa[y])
		{
//			cerr<<"lca "<<x<<' '<<y<<endl;
			if(dep[x]<dep[y])swap(x,y),swap(px,py);
			int f=pa[x];
			ans-=min(add[f],siz[L[f]]*siz[R[f]]-add[f]);
//			cerr<<"gao "<<f<<endl;
			if(x==R[f])
			{
				add[f]-=get(root[L[f]],px);
//				cerr<<"del "<<R[f]<<' '<<px<<endl;
				del(root[R[f]],px);
//				cerr<<"ins "<<R[f]<<' '<<py<<endl;
				ins(root[R[f]],py,root[R[f]]);
				add[f]+=get(root[L[f]],py);
			}
			else
			{
				add[f]-=siz[R[f]]-get(root[R[f]],px);
//				cerr<<"del "<<L[f]<<' '<<px<<endl;
				del(root[L[f]],px);
//				cerr<<"ins "<<L[f]<<' '<<py<<endl;
				ins(root[L[f]],py,root[L[f]]);
				add[f]+=siz[R[f]]-get(root[R[f]],py);
			}
			ans+=min(add[f],siz[L[f]]*siz[R[f]]-add[f]);
			x=f;
		}
		int f=pa[x];
		if(x==R[f])swap(x,y),swap(px,py);
		ans-=min(add[f],siz[L[f]]*siz[R[f]]-add[f]);
		add[f]-=get(root[L[f]],py);
//		cerr<<"del "<<R[f]<<' '<<py<<endl;
		del(root[R[f]],py);
		add[f]-=siz[R[f]]-get(root[R[f]],px);
//		cerr<<"del "<<L[f]<<' '<<px<<endl;
		del(root[L[f]],px);
		add[f]+=siz[R[f]]-get(root[R[f]],py);
//		cerr<<"ins "<<L[f]<<' '<<py<<endl;
		ins(root[L[f]],py,root[L[f]]);
		add[f]+=get(root[L[f]],px);
//		cerr<<"ins "<<R[f]<<' '<<px<<endl;
		ins(root[R[f]],px,root[R[f]]);
		ans+=min(add[f],siz[L[f]]*siz[R[f]]-add[f]);
//		for(int i=n+1;i<=top;i++)cerr<<i<<' '<<add[i]<<endl;
		cout<<ans<<endl;
	}
	return 0;
}