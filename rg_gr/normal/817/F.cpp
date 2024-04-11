// Problem: CF817F MEX Queries
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF817F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#ifndef CP_EDITOR
const int LL=0,RR=400001;
#else
const int LL=0,RR=100;
#endif
struct Node{
	Node* lc=NULL,*rc=NULL;
	signed tag=1,addv=0;int sumv=0;
}*root;
inline void newNode(Node* &o)
{
	o=new Node();
}
inline void pushdown(Node*&o,int l,int r)
{
	if(o==NULL)newNode(o);
	if(l==r)
	{
		o->sumv=o->sumv*o->tag+o->addv;
		o->tag=1,o->addv=0;
		return;
	}
	if(o->lc==NULL)newNode(o->lc);
	if(o->rc==NULL)newNode(o->rc);
	o->lc->tag*=o->tag,o->lc->addv*=o->tag,o->lc->addv+=o->addv;
	o->rc->tag*=o->tag,o->rc->addv*=o->tag,o->rc->addv+=o->addv;
	o->tag=1,o->addv=0;
}
inline void maintain(Node*&o,int l,int r)
{
	if(o==NULL)newNode(o);
	if(l==r)
	{
		o->sumv=o->sumv*o->tag+o->addv;
		o->tag=1,o->addv=0;
		return;
	}
	o->sumv=o->addv*(r-l+1);
	if(o->lc)o->sumv+=o->lc->sumv*o->tag;
	if(o->rc)o->sumv+=o->rc->sumv*o->tag;
}
void add(Node*&o,int l,int r,int L,int R,int v)
{
	if(o==NULL)newNode(o);
	if(L<=l&&r<=R)
	{
		o->addv+=v;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)add(o->lc,l,m,L,R,v);else maintain(o->lc,l,m);
	if(m<R)add(o->rc,m+1,r,L,R,v);else maintain(o->rc,m+1,r);
	maintain(o,l,r);
}
void mul(Node*&o,int l,int r,int L,int R,int v)
{
	if(o==NULL)newNode(o);
	if(L<=l&&r<=R)
	{
		o->tag*=v;
		o->addv*=v;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)mul(o->lc,l,m,L,R,v);else maintain(o->lc,l,m);
	if(m<R)mul(o->rc,m+1,r,L,R,v);else maintain(o->rc,m+1,r);
	maintain(o,l,r);
}
int query(Node*&o,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		maintain(o,l,r);
		return o->sumv;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	int ans=0;
	if(L<=m)ans+=query(o->lc,l,m,L,R);else maintain(o->lc,l,m);
	if(m<R)ans+=query(o->rc,m+1,r,L,R);else maintain(o->rc,m+1,r);
	maintain(o,l,r);
	return ans;
}
inline int mex()
{
	int l=1,r=400001,ans=114514;
	while(l<=r)
	{
		int m=l+r>>1;
		if(query(root,LL,RR,0,m)==m)l=m+1;
		else r=m-1,ans=m;
	}
#define debug	//for(int i=0;i<=12;i++)printf("%lld ",query(root,LL,RR,i,i));puts("")
	return ans;
}
inline void op1(int l,int r)
{
	debug;
	mul(root,LL,RR,l,r,0);
	debug;
	add(root,LL,RR,l,r,1);
	debug;
}
inline void op2(int l,int r)
{
	mul(root,LL,RR,l,r,0);
}
inline void op3(int l,int r)
{
	mul(root,LL,RR,l,r,-1);
	add(root,LL,RR,l,r,1);
}
void del(Node*o)
{
	if(o==NULL)return;
	del(o->lc);del(o->rc);
	delete o;
}
int ope[100005],ql[100005],qr[100005];
int uni[400005],cc=0;
signed main()
{
	int T=read();
	uni[++cc]=1;
	for(int i=1;i<=T;i++)
	{
		int op=read(),l=read(),r=read();
		ope[i]=op,ql[i]=l,qr[i]=r;
		uni[++cc]=l;
		uni[++cc]=l+1;
		uni[++cc]=r;
		uni[++cc]=r+1;
	}
	std::sort(uni+1,uni+cc+1);
	int ln=std::unique(uni+1,uni+cc+1)-uni;
	for(int i=1;i<=T;i++)
	{
		int op=ope[i],l=ql[i],r=qr[i];
		l=std::lower_bound(uni+1,uni+ln+1,l)-uni;
		r=std::lower_bound(uni+1,uni+ln+1,r)-uni;
		if(op==1)op1(l,r);
		else if(op==2)op2(l,r);
		else op3(l,r);
		printf("%lld\n",uni[mex()]);
	}
	del(root);
}