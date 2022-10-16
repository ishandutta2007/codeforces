#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
struct node
{
	node* ch[26];
	int id,end;
}*root,pool[233];
int top;
char s[23];
void insert(node *&cur,int dep,int id)
{
	if(!cur)cur=&pool[++top],cur->id=top;
	if(s[dep]==0)cur->end=id;
	else insert(cur->ch[s[dep]-'a'],dep+1,id);
}
int id[233][233],ind;
int fi[333],se[333];
struct mat
{
	vector<vector<long long> > a;
	mat(){a.resize(ind+1);for(auto &x:a)x.resize(ind+1);}
	mat operator=(const mat &m)
	{
		a.resize(ind+1);for(auto &x:a)x.resize(ind+1);
		for(int i=1;i<=ind;i++)
			for(int j=1;j<=ind;j++)
				a[i][j]=m.a[i][j];
		return *this;
	}
	mat operator*(const mat &m)const
	{
		mat ret;
		for(int i=1;i<=ind;i++)
			for(int j=1;j<=ind;j++)
			{
				for(int k=1;k<=ind;k++)
				{
					ret.a[i][j]+=a[i][k]*m.a[k][j]%MOD;
				}
				ret.a[i][j]%=MOD;
			}
		return ret;
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>(s+1);
		insert(root,1,i);
	}
	queue<pair<int,int> > q;
	auto upd=[&](int u,int v){++ind;id[u][v]=ind;fi[ind]=u;se[ind]=v;q.emplace(u,v);};
	upd(1,1);
	while(!q.empty())
	{
		auto _=q.front();q.pop();
		int u=_.first,v=_.second;
//		cerr<<u<<' '<<v<<endl;
		for(int c=0;c<26;c++)
		{
			if(pool[u].ch[c]&&pool[v].ch[c])
			{
				int tu=pool[u].ch[c]->id,tv=pool[v].ch[c]->id;
//				cerr<<u<<' '<<v<<" -> "<<tu<<' '<<tv<<endl;
				if(pool[u].ch[c]->end&&!id[1][tv])
					upd(1,tv);
				if(pool[v].ch[c]->end&&!id[1][tu])
					upd(1,tu);
				if(tu>tv)swap(tu,tv);
				if(!id[tu][tv])
					upd(tu,tv);
			}
		}
	}
//	cerr<<ind<<endl;
	mat ans,mul;
	for(int i=1;i<=ind;i++)
		ans.a[i][i]=1;
	for(int i=1;i<=ind;i++)
	{
		int u=fi[i],v=se[i];
		for(int c=0;c<26;c++)
		{
			if(pool[u].ch[c]&&pool[v].ch[c])
			{
				int tu=pool[u].ch[c]->id,tv=pool[v].ch[c]->id;
//				cerr<<u<<' '<<v<<" -> "<<tu<<' '<<tv<<endl;
				if(pool[u].ch[c]->end)
				{
					mul.a[i][id[1][tv]]++;
//					cerr<<u<<' '<<v<<" -> "<<1<<' '<<tv<<' '<<id[1][tv]<<endl;
				}
				if(pool[v].ch[c]->end)
				{
					mul.a[i][id[1][tu]]++;
//					cerr<<u<<' '<<v<<" -> "<<1<<' '<<tu<<' '<<id[1][tu]<<endl;
				}
				if(pool[u].ch[c]->end&&pool[v].ch[c]->end)
				{
					mul.a[i][id[1][1]]++;
//					cerr<<u<<' '<<v<<" -> "<<1<<' '<<1<<' '<<id[1][1]<<endl;
				}
				if(tu>tv)swap(tu,tv);
//				cerr<<u<<' '<<v<<" -> "<<tu<<' '<<tv<<' '<<id[tu][tv]<<endl;
				mul.a[i][id[tu][tv]]++;
			}
		}
	}
	while(m)
	{
		if(m&1)ans=ans*mul;
		mul=mul*mul;
		m>>=1;
	}
	cout<<ans.a[1][1]<<endl;
	return 0;
}