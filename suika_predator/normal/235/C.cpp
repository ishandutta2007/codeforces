#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	node *next[26],*link;
	int vis,d,siz,minlen,maxlen,isend;
}*root,pool[2333333],*ed;
int top;
inline void add(int x)
{
//	cout<<"add "<<(char)(x+'a')<<endl;
	node *p=ed,*np=&pool[top++];
	ed=np;np->maxlen=p->maxlen+1;np->siz=1;
	while(p&&!p->next[x])p->next[x]=np,p=p->link;
	if(p)
	{
		node *q=p->next[x];
		if(q->maxlen==p->maxlen+1)
			np->link=q,q->d++;
		else
		{
			node *nq=&pool[top++];
			nq->maxlen=p->maxlen+1;
			for(int i=0;i<26;i++)nq->next[i]=q->next[i];
			nq->link=q->link;
			q->link=nq,nq->d++;np->link=nq,nq->d++;
			while(p&&p->next[x]==q)p->next[x]=nq,p=p->link;
		}
	}
	else np->link=root,root->d++;
}
char buf[2333333];
queue<node*> q;
inline int match(int l)
{
//	cout<<"match "<<buf+1<<endl;
	node *cur=root;
	int ret=0,curlen=0;
	for(int i=1;i<l;i++)
	{
//		cout<<buf[i]<<' '<<cur-root+1<<endl;
		while(cur->link&&!cur->next[buf[i]-'a'])cur=cur->link,curlen=cur->maxlen;
		if(cur->next[buf[i]-'a'])cur=cur->next[buf[i]-'a'],curlen++;
//		cout<<buf[i]<<' '<<cur-root+1<<endl;
	}
	for(int i=0;i<l;i++)
	{
//		cout<<buf[i]<<' '<<cur-root+1<<endl;
		while(cur->link&&!cur->next[buf[i]-'a'])cur=cur->link,curlen=cur->maxlen;
		if(cur->next[buf[i]-'a'])cur=cur->next[buf[i]-'a'],curlen++;
		while(cur->link&&cur->minlen>l)cur=cur->link,curlen=cur->maxlen;
		if(curlen>=l&&!cur->vis)ret+=cur->siz,cur->vis=1,q.push(cur);
//		cout<<buf[i]<<' '<<cur-root+1<<endl;
	}
	while(!q.empty())q.front()->vis=0,q.pop();
	return ret;
}
int n,l;
int main()
{
	scanf("%s",buf+1);l=strlen(buf+1);
	ed=root=&pool[top++];
	for(int i=1;i<=l;i++)add(buf[i]-'a');
	node *cur=ed;
	while(cur)cur->isend=1,cur=cur->link;
	for(int i=0;i<=top;i++)
	{
		if(pool[i].d==0)q.push(&pool[i]);
		if(pool[i].link)pool[i].minlen=pool[i].link->maxlen+1;
	}
	while(!q.empty())
	{
		node *u=q.front();q.pop();
		if(u->link)
		{
			u->link->siz+=u->siz;
			u->link->d--;
			if(u->link->d==0)q.push(u->link);
		}
	}
//	for(int i=0;i<=top;i++)cout<<pool[i].siz<<' ';cout<<endl;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",buf+1);
		l=strlen(buf+1);
		buf[0]=buf[l];
		int ans=match(l);
		printf("%d\n",ans);
	}
	return 0;
}