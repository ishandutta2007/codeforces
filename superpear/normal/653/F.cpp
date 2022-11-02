#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
	
#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<PII,int> PIII21;

const int maxn=1000005;
const int base1=987654323;
const int base2=3214567;
const int bigp1=100000007;
const int bigp2=1000000009;
int N;

// SA variables
int a[maxn],f1[maxn],m1[maxn],po2[maxn],rank[maxn],lca[maxn],sa[maxn];
PIII21 qll[maxn];
char st[maxn];
int nt,e,o;

void makesa()
{
	for (int i=1;i<=N;i++) f1[i]=a[i];
	sort(f1+1,f1+N+1);
	m1[0]=0;f1[0]=-maxlongint;
	for (int i=1;i<=N;i++)
		if (f1[i]!=f1[i-1]) m1[i]=m1[i-1]+1; else m1[i]=m1[i-1];
	map<int,int> lss;
	map<int,int>::iterator lst;
	for (int i=1;i<=N;i++)
		lss.insert(m_p(f1[i],m1[i]));
	for (int i=1;i<=N;i++)
	{
		lst=lss.find(a[i]);
		rank[i]=lst->second;
	}
	int e=1;
	while (e<=N)
	{
		for (int i=1;i<=N;i++)
			if (i+e<=N)
				qll[i]=m_p(m_p(rank[i],rank[i+e]),i);
			else
				qll[i]=m_p(m_p(rank[i],0),i);
		sort(qll+1,qll+N+1);
		m1[1]=1;
		for (int i=2;i<=N;i++)
			if (qll[i].first!=qll[i-1].first) m1[i]=m1[i-1]+1; else m1[i]=m1[i-1];
		for (int i=1;i<=N;i++)
			rank[qll[i].second]=m1[i];
		e*=2;
		if (m1[N]==N) break;
	}
}

LL getoverlap(int *a)
{
	makesa();
	for (int i=1;i<=N;i++) sa[rank[i]]=i;
	sa[0]=N+1;
	lca[0]=0;
	for (int i=1;i<=N;i++)
	{
		nt=max(lca[rank[i-1]]-1,0);
		while ((sa[rank[i]-1]+nt<=N)&&(sa[rank[i]]+nt<=N)&&(a[sa[rank[i]-1]+nt]==a[sa[rank[i]]+nt])) ++nt;
		lca[rank[i]]=nt;
	}
	LL ans=0;
	for (int i=1;i<=N;i++) ans+=lca[i];
	return ans;
}

vector<vector<ULL> > FC;
vector<ULL> GC;
ULL stk[maxn],E[maxn];
int top;
map<ULL,int> lsh;
map<ULL,int>::iterator lsg;

int main()
{
	//freopen("F.in","r",stdin);
	
	scanf("%d",&N);
	scanf("%s",st);
	top=0;
	for (int i=0;i<N;i++)
	{
		if (st[i]=='(')
			++top,stk[top]=1; // Push '('
		else
		{
			// Pop ')'
			int ec=top;
			while ((ec>0)&&(stk[ec]!=1)&&(stk[ec]!=2)) ec--;
			if ((ec==0)||(stk[ec]==2))
			{
				++top,stk[top]=2;
				continue;
			}
			PII tmp=m_p(1,1);
			GC.clear();
			for (int j=ec+1;j<=top;j++) 
			{
				tmp.w1=((LL)tmp.w1*base1+stk[j])%bigp1;
				tmp.w2=((LL)tmp.w2*base2+stk[j])%bigp2;
				GC.p_b(stk[j]);
			}
			FC.p_b(GC);
			tmp.w1=((LL)tmp.w1*base1+2)%bigp1;
			tmp.w2=((LL)tmp.w2*base2+2)%bigp2;
			top=ec;
			stk[top]=((LL)tmp.w1<<32)+tmp.w2;
		}
		//for (int j=1;j<=top;j++) cout<<stk[j]<<"|";cout<<endl;
	}

	if ((stk[top]!=1)&&(stk[top]!=2)) ++top,stk[top]=1;
	GC.clear();
	for (int i=1;i<=top;i++)
	{
		if ((stk[i]==1)||(stk[i]==2)) 
		{
			FC.p_b(GC);
			GC.clear();
		}
		else
			GC.p_b(stk[i]);
	}
	
	/*for (int i=0;i<FC.size();i++)
	{
		for (int j=0;j<FC[i].size();j++)
			cout<<FC[i][j]<<" ";
		cout<<endl;
	}*/
	
	LL ans=0;
	int o=0;
	for (int i=0;i<FC.size();i++)
	{
		for (int j=0;j<FC[i].size();j++) ++o,E[o]=FC[i][j];
		ans+=(LL)(FC[i].size())*(FC[i].size()+1)/2;
		++o,E[o]=3241786389461823+i;
	}
	
	//for (int i=1;i<=o;i++) cout<<E[i]<<" ";cout<<endl;
	for (int i=1;i<=o;i++) lsh.insert(m_p(E[i],0));
	int hs;
	for (lsg=lsh.begin(),hs=0;lsg!=lsh.end();lsg++,hs++) lsg->w2=hs;
	N=o;
	for (int i=1;i<=N;i++) a[i]=(lsh.l_b(E[i]))->w2;
	
	cout<<ans-getoverlap(a)<<endl;
   	
	return 0;
}