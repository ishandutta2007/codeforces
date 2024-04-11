#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
#define mp make_pair
typedef pair<int,int> pii;
const int MAXN=577777;
priority_queue<pair<int,pii> > pq;//len,pos,id
int vis[MAXN];
struct node
{
	node *l,*r;
	int val,len,pos,id;
}pool[MAXN];
int top;
int n,m,ans;
int cnt[MAXN],val[MAXN];
int main()
{
	scanf("%d",&n);
	int cur=0,t,last=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t==last)cnt[cur]++;
		else
		{
			cnt[++cur]=1;
			val[cur]=t;
		}
		last=t;
	}
	for(int i=1;i<=cur;i++)
	{
		pool[i].len=cnt[i];
		pool[i].val=val[i];
		pool[i].id=i;
		pool[i].pos=MAXN-i;
		pool[i].l=&pool[i-1];
		pool[i].r=&pool[i+1];
		pq.push(mp(pool[i].len,mp(MAXN-i,i)));
	}
	pool[0].val=-1;
	pool[0].r=&pool[1];pool[cur+1].l=&pool[cur];
	top=cur+1;//new:++top;
	while(!pq.empty())
	{
		auto tmp=pq.top();pq.pop();
		//cout<<tmp.first<<' '<<tmp.second.first<<' '<<tmp.second.second<<endl;
		if(vis[tmp.second.second])continue;
		vis[tmp.second.second]=1;
		ans++;
		node *nd=&pool[tmp.second.second];
		//cout<<1<<endl;
		if(nd->l->val==nd->r->val)
		{
			//cout<<"c1"<<endl;
			node *nn=&pool[++top];
			nn->val=nd->l->val;
			nn->len=nd->l->len+nd->r->len;
			nn->l=nd->l->l;
			nn->r=nd->r->r;
			nn->l->r=nn;
			nn->r->l=nn;
			nn->id=top;
			nn->pos=nd->r->pos;
			vis[nd->l->id]=1;vis[nd->r->id]=1;
			pq.push(mp(nn->len,mp(nn->pos,nn->id)));
		}
		else
		{
			//cout<<"c2"<<endl;
			nd->l->r=nd->r;
			nd->r->l=nd->l;
		}
	}
	printf("%d\n",ans);
	return 0;
}