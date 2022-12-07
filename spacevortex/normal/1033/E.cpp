#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> VC;
const int N=610;
int n,top,tot=0,C=0,m;
int del[N],col[N],stk[N],vis[N],ins[N],p[N],mp[N][30],vi[N][30],f[N];
vector<int> e[N];
const VC operator +(VC a,VC b)
{
	int vsi,i;
	VC c;
	c.clear();
	vsi=a.size();for(i=0;i<vsi;i++) c.pb(a[i]);
	vsi=b.size();for(i=0;i<vsi;i++) c.pb(b[i]);
	return c;
}
int qry(VC A)
{
	int K,i,ret;
	K=A.size();
	if(K==0) return 0;
	C++;
	printf("? %d\n",K);
	for(i=0;i<K;i++) printf("%d ",A[i]);
	putchar('\n');
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
int dfs(VC A,VC B,int W,int E)
{
	int tot,mid,n1,n2,i;
	VC s1,s2;
	tot=B.size();
	if(tot==1) return B[0];
	s1.clear();s2.clear();
	mid=tot>>1;
	for(i=0;i<mid;i++) s1.pb(B[i]);
	for(i=mid;i<tot;i++) s2.pb(B[i]);
	n1=qry(A+s1)-W-qry(s1);
	n2=E-n1;
	if(n1>0) return dfs(A,s1,W,n1);
	else return dfs(A,s2,W,n2);
}
void msolve(int l,int r,int X,int E)
{
	if(l==r)
	{
		e[f[l]].pb(X);e[X].pb(f[l]);
		del[X]=1;f[++m]=X;
		return ;
	}
	int p,mid,i,vl,n1,n2;
	VC s1,s3;
	for(p=0;l+(1<<p)-1<r;p++);p--;
	mid=l+(1<<p)-1;
	s1.clear();s3.clear();
	s3.pb(X);
	for(i=l;i<=mid;i++) s1.pb(f[i]);
	if(vi[l][p]) vl=mp[l][p];
	else vi[l][p]=1,vl=mp[l][p]=qry(s1);
	n1=qry(s1+s3)-vl;n2=E-n1;
	if(n1) msolve(l,mid,X,n1);
	else msolve(mid+1,r,X,n2);
}
void Solve(VC A,VC B)
{
	int W,now,X,asi,bsi,x,y;
	asi=A.size();bsi=B.size();
	if(asi==1&&bsi==1) 
	{
		x=A[0];y=B[0];
		del[x]=del[y]=1;
		e[x].pb(y);e[y].pb(x);
		return ;
	}
	W=qry(A);now=qry(A+B)-W-qry(B);
	X=dfs(A,B,W,now);
	if(m==n)
	{
		VC s;s.clear();s.pb(X);Solve(s,A);return ;
	}
	A.pb(X);
	msolve(1,m,X,qry(A)-W);
}
void srh(int x,int nf)
{
	for(int v:e[x])
	{
		if(v==nf) continue;
		col[v]=(col[x]^1);
		srh(v,x);
	}
}
void srh2(int x,int nf)
{
	int i;
	vis[x]=1;ins[x]=1;stk[++top]=x;
	for(int v:e[x])
	{
		if(v==nf||tot>0) continue;
		if(vis[v])
		{
			if(ins[v])
			{
				for(i=top;;i--)
				{ 
					p[++tot]=stk[i];
					if(stk[i]==v) break;
				}
			}
		}
		else srh2(v,x);
	}
	ins[x]=0;top--;
}
void usolve(VC A)
{
	int tot,i,mid;
	VC s1,s2;
	tot=A.size();
	if(tot==2)
	{
		e[A[0]].pb(A[1]);e[A[1]].pb(A[0]);
		return ;
	}
	mid=tot>>1;
	s1.clear();s2.clear();
	for(i=0;i<mid;i++) s1.pb(A[i]);
	for(i=mid;i<tot;i++) s2.pb(A[i]);
	if(qry(s1)) usolve(s1);
	else if(qry(s2)) usolve(s2);
	else Solve(s1,s2);
}
int main()
{
	int i,j,vsi;
	VC s1,s2;
	scanf("%d",&n);
	del[1]=1;m=1;f[1]=1;
	for(i=2;i<=n;i++)
	{
		s1.clear();s2.clear();
		for(j=1;j<=n;j++)
		{
			if(del[j]) s1.pb(j);
			else s2.pb(j);
		}
		Solve(s1,s2);
	}
	srh(1,0);
	s1.clear();s2.clear();
	for(i=1;i<=n;i++) 
	{
		if(col[i]==0) s1.pb(i);
		else s2.pb(i);
	}
	if(qry(s1)==0&&qry(s2)==0)
	{
		vsi=s1.size();
		printf("Y %d\n",vsi);
		for(i=0;i<vsi;i++) printf("%d ",s1[i]);
		fflush(stdout);
	}
	else
	{
		if(qry(s1)) usolve(s1);
		else usolve(s2);
		for(i=1;i<=n;i++) 
		{
			if(!vis[i]) srh2(i,0);
		}
		printf("N %d\n",tot);
		for(i=1;i<=tot;i++) printf("%d ",p[i]);
		fflush(stdout);
	}
	
	return 0;
}