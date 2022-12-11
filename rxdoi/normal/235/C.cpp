#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1e6+19;
//SAM
struct node
{
	node *Par,*go[26];
	int val,vis,R;
} Nd[2*N],*Q[2*N],*cur=Nd,*rt,*Last,*x;
char s[N],t[N];
int cnt[N],Qc,Len,Time,L;
long long Ans;

node *New(int v) {return cur->val=v,cur++;}
void Extend(int x)
{
	node *p=Last,*np=New(p->val+1);
	np->R=1;
	for (;p&&!p->go[x];p=p->Par) p->go[x]=np;
	if (!p) np->Par=rt;else
	{
		node *t=p->go[x];
		if (t->val==p->val+1) np->Par=t;else
		{
			node *nt=New(p->val+1);
			nt->Par=t->Par,t->Par=np->Par=nt;
			memcpy(nt->go,t->go,sizeof(t->go));
			for (;p&&p->go[x]==t;p=p->Par) p->go[x]=nt;
		}
	}
	Last=np;
}

int main()
{
	rt=Last=New(0);
	scanf("%s",s);Len=strlen(s);
	For(i,0,Len) Extend(s[i]-'a');
	for (node *i=Nd;i<cur;i++) cnt[i->val]++;
	For(i,1,Len+1) cnt[i]+=cnt[i-1];
	for (node *i=Nd;i<cur;i++) Q[cnt[i->val]--]=i;
	for (node **i=Q+(cur-Nd);i>Q+1;i--) (*i)->Par->R+=(*i)->R;

	for (scanf("%d",&Qc);Qc--;)
	{
		scanf("%s",t);Len=strlen(t);
		x=rt,L=0,Time++,Ans=0;
		For(i,0,2*Len-1)
		{
			int c=t[i<Len?i:i-Len]-'a';
			if (x->go[c]) x=x->go[c],L++;else
			{
				for (;x&&!x->go[c];x=x->Par);
				if (!x) x=rt,L=0;else L=x->val+1,x=x->go[c];
			}
			if (L>=Len)
			{
				for (;x->Par&&x->Par->val>=Len;x=x->Par);
				if (x->vis!=Time) x->vis=Time,Ans+=x->R;
			}
		}
		printf("%I64d\n",Ans);
	}
}