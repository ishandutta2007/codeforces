#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,M;vector<set<int> > A;vector<set<pair<int,int> > >B;vector<int> d,f,F,G;vector<bool> v;
inline void upd(int&a,int b){if(d[a]>d[b])a=b;}
void ff(int x,int y)
{
	f[x]=x,v[x]=1;
	for(set<int>::iterator i=A[x].begin();i!=A[x].end();i++)
		if(v[*i]){if(*i!=y)upd(f[x],*i);}
		else d[*i]=d[x]+1,ff(*i,x),upd(f[x],f[*i]);
}
void ff(int x)
{
	f[x]=f[f[x]],v[x]=0;
	for(set<int>::iterator i=A[x].begin();i!=A[x].end();i++)if(v[*i])ff(*i);
}
bool gg(int x,int y,int fa)
{
	if(x==y)return 1;
	for(set<PII>::iterator i=B[x].begin();i!=B[x].end();i++)
		if(i->fi!=fa)if(gg(i->fi,y,x)){v[i->se]=v[i->se^1]=1;return 1;}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	A.resize(n);
	for(int i=0,x,y;i<m;i++)
		scanf("%d%d",&x,&y),--x,--y,
		A[x].insert(y),A[y].insert(x);
	if(n==2){puts("-1");return 0;}
	d.resize(n,0),f.resize(n),v.resize(n,0);
	ff(0,-1),ff(0);
	F.resize(n);
	for(int i=0;i<n;i++)if(f[i]==i)F[i]=(int)G.size(),G.pb(i);
	for(int i=0;i<n;i++)F[i]=F[f[i]];
	B.resize((int)G.size());
	for(int i=0;i<n;i++)
		for(set<int>::iterator j=A[i].begin();j!=A[i].end();j++)
			if(F[i]!=F[*j])
			{
				set<PII>::iterator p=B[F[i]].lower_bound(mp(F[*j],-1));
				if(p!=B[F[i]].end()&&p->fi==F[*j])continue;
				B[F[i]].insert(mp(F[*j],M++)),B[F[*j]].insert(mp(F[i],M++));
			}
	if((int)G.size()==1){puts("0");return 0;}
	if((int)G.size()==2)
	{
		puts("1");
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(F[i]!=F[j]&&A[i].find(j)==A[i].end()){printf("%d %d\n",i+1,j+1);return 0;}
	}
	vector<int> L;
	for(int i=0;i<(int)G.size();i++)if((int)B[i].size()==1)L.pb(i);
	printf("%d\n",((int)L.size()+1)/2);
	while(1)
	{
		random_shuffle(L.begin(),L.end());
		bool F=0,FF=1;
		if((int)L.size()&1)F=1,L.pb(L[0]);
		v.clear(),v.resize(M,0);
		for(int i=0;i<(int)L.size();i+=2)gg(L[i],L[i+1],-1);
		for(int i=0;i<M;i++)if(!v[i]){FF=0;break;}
		if(FF)
		{
			for(int i=0;i<(int)L.size();i+=2)printf("%d %d\n",G[L[i]]+1,G[L[i+1]]+1);
			return 0;
		}
		if(F)L.erase(L.end()-1);
	}
	return 0;
}