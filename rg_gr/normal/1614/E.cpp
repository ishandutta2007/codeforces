// Problem: E. Divan and a Cottage
// Contest: Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//MatrixCascade AFO.
//LGM when?
 
//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#include <time.h>
#include <random>
#include <assert.h>
// Problem: E. Divan and a Cottage
// Contest: Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//MatrixCascade AFO.
//LGM when?
 
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
// #define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
const int D=1e9;
struct qwq{
	struct Node{
		Node *lc,*rc;
		int val;
		Node(){lc=rc=NULL;val=0;}
	}*r;
	#define sum(k)  (k==NULL?0:k->val)
	#define test(k) (k!=NULL?0:k=new Node())
	void add(Node* &o,int l,int r,int L,int R,int v)
	{
		test(o);
		if(L<=l&&r<=R)
		{
			o->val+=v;
			return;
		}
		int m=l+r>>1;
		if(L<=m)add(o->lc,l,m,L,R,v);
		if(m<R)add(o->rc,m+1,r,L,R,v);
	}
	int que(Node* &o,int l,int r,int k)
	{
		if(o==NULL)return 0;
		int m=l+r>>1;
		if(k<=m)return o->val+que(o->lc,l,m,k);
		return o->val+que(o->rc,m+1,r,k);
	}
	int v(int t)
	{
		return que(r,0,D,t)+t;
	}
}a;
#define t a
signed main()
{
	int T=1,lla=0;
	while(T--)
	{
		int n=read();
		up(i,1,n)
		{
			int x=read();
			int l=0,r=D,ans=-1;
			while(l<=r)
			{
				int m=l+r>>1;
				if(a.v(m)<x)ans=m,l=m+1;
				else r=m-1;
			}
			if(ans!=-1)t.add(t.r,0,D,0,ans,1);
			l=0,r=D,ans=-1;
			while(l<=r)
			{
				int m=l+r>>1;
				if(a.v(m)>x)ans=m,r=m-1;
				else l=m+1;
			}
			if(ans!=-1)t.add(t.r,0,D,ans,D,-1);
			int k=read();
			while(k--)
			{
				int s=(read()+lla)%1000000001;
				printf("%d\n",lla=a.v(s));
			}
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/