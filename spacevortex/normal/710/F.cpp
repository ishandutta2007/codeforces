#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef string str;
typedef long long ll;
const int N=3e6+50,pn=3e6+5,Log=22,C=30;
int Q,top=0,tp1=0,tp2=0;
int nxt[N][C],fail[N],cnt[N],stk[N],ins[N];
inline int newnode()
{
	ins[stk[top]]=1;
	//printf("new %d\n",top);
	//if(stk[top]==599832)  //puts("NEW---------------------------------------");
	return stk[top--];
}
inline void delnode(int x)
{
	//printf("del %d\n",top);
	//if(x==599832)
	//{
		//puts("DEL---------------------------------------");
		//exit(0);
	//}
	int i;
	for(i=0;i<26;i++) nxt[x][i]=0;
	cnt[x]=fail[x]=ins[x]=0;
	stk[++top]=x;
}
struct AC_automaton
{
	int rt;
	vector<str> V;
	queue<int> que;
	inline void mdel(int x)
	{
		//printf("del%d\n",x);
		int i;
		ins[x]=0;
		for(i=0;i<26;i++)
		{
			if(ins[nxt[x][i]]) mdel(nxt[x][i]);
		}
		delnode(x);
	}
	inline void clear()
	{
		if(rt) mdel(rt);
		V.clear();
		rt=0;
	}
	inline void insert(str s)
	{
		V.pb(s);
	}
	inline void build()
	{
		//printf("start\n");
		int vsi,x,i,j,now,len,c;
		rt=newnode();
		while(!que.empty()) que.pop();
		vsi=V.size();
		for(i=0;i<vsi;i++)
		{
			len=V[i].size();
			for(j=0,now=rt;j<len;j++)
			{
				c=V[i][j]-'a';
				if(!nxt[now][c]) nxt[now][c]=newnode();
				now=nxt[now][c];
			}
			cnt[now]++;
		}
		for(i=0;i<26;i++)
		{
			if(nxt[rt][i])
			{
				fail[nxt[rt][i]]=rt;
				que.push(nxt[rt][i]);
			}
			else nxt[rt][i]=rt;
		}
		//int zcs=0;
		while(!que.empty())
		{
			x=que.front();que.pop();
			//printf("%d\n",x);
			///if((++zcs)>=500) exit(0);
			for(i=0;i<26;i++)
			{
				if(!nxt[x][i]) nxt[x][i]=nxt[fail[x]][i];
				else
				{
					que.push(nxt[x][i]);
					fail[nxt[x][i]]=nxt[fail[x]][i];
					cnt[nxt[x][i]]+=cnt[fail[nxt[x][i]]];
				}
			}
		}
		//printf("en\n");
	}
	inline ll query(string s)
	{
		int now,len,i,c;
		ll ras=0;
		len=s.size();
		now=rt;
		for(i=0;i<len;i++)
		{
			c=s[i]-'a';
			now=nxt[now][c];
			ras+=cnt[now];
		}
		return ras;
	}
}A[Log+3],B[Log+3];
inline void Add(str s)
{
	int vsi1,vsi2,mt,i;
	tp1++;mt=tp1;
	A[tp1].V.pb(s);
	while(tp1>1&&(vsi1=A[tp1].V.size())==(vsi2=A[tp1-1].V.size())) 
	{
		//printf("!!! %d %d\n",tp1,vsi1);
		for(i=0;i<vsi1;i++) A[tp1-1].insert(A[tp1].V[i]);
		A[tp1].clear();
		tp1--;
	}
	A[tp1].build();
}
inline void Del(str s)
{
	int vsi1,vsi2,mt,i;
	tp2++;mt=tp2;
	B[tp2].V.pb(s);
	while(tp2>1&&(vsi1=B[tp2].V.size())==(vsi2=B[tp2-1].V.size())) 
	{
		for(i=0;i<vsi1;i++) B[tp2-1].insert(B[tp2].V[i]);
		B[tp2].clear();
		tp2--;
	}
	B[tp2].build();
}
inline ll Query(str s)
{
	int i;
	ll ras=0;
	for(i=1;i<=tp1;i++) ras+=A[i].query(s);
	for(i=1;i<=tp2;i++) ras-=B[i].query(s);
	return ras;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	int i,op;
	str s;
	for(i=1;i<=pn;i++) stk[++top]=i;
	ios::sync_with_stdio(false);
	cin>>Q;
	while(Q--)
	{
		cin>>op>>s;
		if(op==1) Add(s);
		if(op==2) Del(s);
		if(op==3)
		{
			printf("%I64d\n",Query(s));
		}
		fflush(stdout);
	}
	return 0;
}