#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int SHIFT=2,HMOD=998244353,MOD=1e9+7;
long long bits[233333];
struct node
{
	int l,r,hash,lazy;
	bool all1;
	node *lson,*rson;
	inline void cover(int x)
	{
		all1=x;
		lazy=x;
		if(x)hash=(bits[r-l+1]-1+HMOD)%HMOD;
		else hash=0;
	}
	inline void upd()
	{
		all1=lson->all1&&rson->all1;
		hash=(lson->hash+(rson->hash*bits[lson->r-lson->l+1]))%HMOD;
	}
	inline void cp(node *x)
	{
		l=x->l,r=x->r,hash=x->hash,lazy=x->lazy,all1=x->all1,lson=x->lson,rson=x->rson;
	}
}*root[2333333],pool[27777777];
int top,ind;
node* build(int l,int r)
{
	node *ret=&pool[top++];
	ret->l=l;ret->r=r;ret->lazy=-1;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		ret->lson=build(l,mid);
		ret->rson=build(mid+1,r);
	}
	return ret;
}
node* change(node *cur,int l,int r,int x)
{
//	cout<<"change "<<cur->l<<' '<<cur->r<<' '<<l<<' '<<r<<' '<<x<<endl;
	node *ret=&pool[top++];
	ret->cp(cur);
	if(cur->l==l&&cur->r==r)
	{
		ret->cover(x);
		return ret;
	}
	if(cur->lazy!=-1)
	{
		node *lson=&pool[top++],*rson=&pool[top++];
		lson->cp(cur->lson),rson->cp(cur->rson);
		lson->cover(cur->lazy),rson->cover(cur->lazy);
		cur->lson=lson,cur->rson=rson;
		cur->lazy=-1;
	}
	if(cur->lson->r>=r)ret->lson=change(cur->lson,l,r,x),ret->rson=cur->rson;
	else if(cur->rson->l<=l)ret->lson=cur->lson,ret->rson=change(cur->rson,l,r,x);
	else ret->lson=change(cur->lson,l,cur->lson->r,x),ret->rson=change(cur->rson,cur->rson->l,r,x);
	ret->upd();
	return ret;
}
int get0(node *cur,int pos)
{
//	cout<<"get0 "<<cur->l<<' '<<cur->r<<' '<<pos<<endl;
	if(cur->l==cur->r)
	{
		if(cur->all1)return -1;
		else return cur->l;
	}
	if(cur->lazy!=-1)
	{
		node *lson=&pool[top++],*rson=&pool[top++];
		lson->cp(cur->lson),rson->cp(cur->rson);
		lson->cover(cur->lazy),rson->cover(cur->lazy);
		cur->lson=lson,cur->rson=rson;
		cur->lazy=-1;
	}
	if(cur->rson->l<=pos)return get0(cur->rson,pos);
	else
	{
		int tmp=get0(cur->lson,pos);
		if(tmp!=-1)return tmp;
		else return get0(cur->rson,pos);
	}
}
int add(int ver,int pos)
{
//	cout<<"add "<<ver<<' '<<pos<<endl;
	int pp=get0(root[ver],pos);
	if(pp==pos)root[++ind]=change(root[ver],pp,pp,1);
	else
	{
		root[++ind]=change(root[ver],pos,pp-1,0);ver=ind;
		root[++ind]=change(root[ver],pp,pp,1);
	}
	return ind;
}
bool cmp(node *x,node *y)//x<y return 1
{
//	cout<<"cmp "<<x->l<<' '<<x->r<<' '<<x->hash<<' '<<y->hash<<endl;
	if(x->l==x->r)return x->hash<y->hash;
	if(x->lazy!=-1)
	{
		node *lson=&pool[top++],*rson=&pool[top++];
		lson->cp(x->lson),rson->cp(x->rson);
		lson->cover(x->lazy),rson->cover(x->lazy);
		x->lson=lson,x->rson=rson;
		x->lazy=-1;
	}
	if(y->lazy!=-1)
	{
		node *lson=&pool[top++],*rson=&pool[top++];
		lson->cp(y->lson),rson->cp(y->rson);
		lson->cover(y->lazy),rson->cover(y->lazy);
		y->lson=lson,y->rson=rson;
		y->lazy=-1;
	}
	if(x->rson->hash!=y->rson->hash)return cmp(x->rson,y->rson);
	return cmp(x->lson,y->lson);
}
int blu=0;
void transform(node *cur)
{
	if(cur->l==cur->r)
	{
		blu=(blu*2+cur->hash)%MOD;
		return ;
	}
	if(cur->lazy!=-1)
	{
		node *lson=&pool[top++],*rson=&pool[top++];
		lson->cp(cur->lson),rson->cp(cur->rson);
		lson->cover(cur->lazy),rson->cover(cur->lazy);
		cur->lson=lson,cur->rson=rson;
		cur->lazy=-1;
	}
	transform(cur->rson);
	transform(cur->lson);
}
struct edge
{
	int v,w;
	edge *next;
}*h[111111],epool[233333];
int etop;
inline void addedge(int u,int v,int w)
{
	edge *tmp=&epool[etop++];tmp->v=v;tmp->w=w;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&epool[etop++];pmt->v=u;pmt->w=w;pmt->next=h[v];h[v]=pmt;
}
#define mp make_pair
typedef pair<int,int> pii;
struct _cmp
{
	inline bool operator()(const pii &x,const pii &y)
	{
		return !cmp(root[x.first],root[y.first]);
	}
};
priority_queue<pii,vector<pii>,_cmp> q;
int dis[111111],inq[111111],lastu[111111];
vector<int> ans;
int main()
{
	bits[0]=1;
	for(int i=1;i<=111111;i++)bits[i]=(bits[i-1]*2)%HMOD;
	root[0]=build(0,111111);
	add(0,110000);
	int n,m,u,v,w,S,T;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	scanf("%d%d",&S,&T);
	for(int i=1;i<=n;i++)dis[i]=1;
	dis[S]=0;
	q.push(mp(dis[S],S));inq[S]=1;
	while(!q.empty())
	{
		pii _=q.top();q.pop();
		int u=_.second;
		if(dis[u]!=_.first)continue;
//		cout<<"dis["<<u<<"] = "<<root[dis[u]]->hash<<endl;
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
//			cout<<u<<"->"<<tmp->v<<endl;
			int t=add(dis[u],tmp->w);
//			cout<<"new length: "<<root[t]->hash<<endl;
			if(cmp(root[t],root[dis[tmp->v]]))
			{
//				cout<<"relax..."<<endl;
				lastu[tmp->v]=u;
				dis[tmp->v]=t;
				q.push(mp(dis[tmp->v],tmp->v));
			}
		}
	}
//	cout<<"last step"<<endl;
	if(dis[T]==1)return printf("-1\n"),0;
	transform(root[dis[T]]);
	printf("%d\n",blu);
	int cur=T;
	ans.push_back(T);
	while(lastu[cur])
	{
		cur=lastu[cur];
		ans.push_back(cur);
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto x:ans)printf("%d ",x);
	puts("");
	cerr<<top<<' '<<ind<<endl;
	return 0;
}