#include <bits/stdc++.h>

using namespace std;


#define Not(x) (-x-1)
#define True(x) (x>=0 ? 2*x+1:2*Not(x))
#define False(x) (x>=0 ? 2*x:2*Not(x)+1)
#define Flip(x) (x^1)

struct TwoSAT
{
	typedef pair<int,int> pii;
	vector<pii> record;
	vector<vector<int>> g;
	vector<int> col,dfn,low,vis;
	int n=0,tim=0,sccCnt=0;
	stack<int> stk;


	void setn(int _n)
	{
		n=2*_n;
	}

	void init()
	{
		if (n==0)
		{
			for (auto p:record)
			{
				n=max(n,p.first+1);
				n=max(n,p.second+1);
			}
			n=(n+1)/2*2;
		}
		g.resize(n);vis.resize(n);dfn.resize(n);low.resize(n);col.resize(n);
		for (auto p:record)
		{
			g[p.first].push_back(p.second);
		}
	}

	void tarjan(int u) 
	{
    	low[u] = dfn[u] = ++tim;
    	stk.push(u); vis[u] = true;
    	for (auto v : g[u]) 
        	if (!dfn[v]) 
        		tarjan(v), low[u] = min(low[u], low[v]);
        	else if (vis[v]) 
        		low[u] = min(low[u], dfn[v]);
    	if (low[u] == dfn[u]) 
    	{
      		++sccCnt;
       		do {
            	col[u] = sccCnt;
           		u = stk.top(); stk.pop(); vis[u] = false;
        	} while (low[u] != dfn[u]);
    	}
	}

	bool check()
	{
		init();
		for (int i = 0; i < n; ++i) 
			if (!dfn[i]) 
				tarjan(i);
		for (int i=0;i<n/2;i++)
			if (col[True(i)]==col[False(i)])
				return false;
		return true;
	}


	vector<int> build()
	{
		vector<int> ans;
		ans.resize(n/2);
		for (int i=0;i<n/2;i++)
			ans[i]=(col[True(i)]<col[False(i)]);
		return ans;
	}

	string trans(int x)
	{
		if (x&1)
			return "  "+to_string(x/2);
		else
			return "~ "+to_string(x/2);
	}

	void output()
	{
		//cout<<2<<endl;
		for (auto p:record)
			cout<<trans(p.first)<<" -> "<<trans(p.second)<<endl;
	}

	void Add(int x,int y){record.push_back({x,y});}

	void AddTrue(int x){Add(False(x),True(x));}
	void AddFalse(int x){Add(True(x),False(x));}

	void AddAnd(int x,int y){AddTrue(x);AddTrue(y);}
	void AddOr(int x,int y){Add(False(x),True(y));Add(False(y),True(x));}
	void AddXor(int x,int y){Add(True(x),False(y));Add(False(y),True(x));
							 Add(True(y),False(x));Add(False(x),True(y));}

	void AddNotAnd(int x,int y){AddOr(Not(x),Not(y));}
	void AddNotOr(int x,int y){AddAnd(Not(x),Not(y));}
	void AddNotXor(int x,int y){AddXor(Not(x),y);}

};

int n,m;
int l[110],r[110];
int inside(int pos,int id)
{
	if (l[id]<=r[id])
		return l[id]<pos && pos<r[id];
	return pos<r[id] || pos>l[id];
}
int main()
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		cin>>l[i]>>r[i];
		if (l[i]>r[i])
			swap(l[i],r[i]);
	}
	TwoSAT twoSAT;
	twoSAT.setn(m);
	for (int i=0;i<m;i++)
		for (int j=i+1;j<m;j++)
		{
			//cout<<i<<' '<<j<<endl;
			if ((inside(l[i],j) || inside(r[i],j))
				&& (inside(l[j],i) || inside(r[j],i)))
				twoSAT.AddXor(i,j);
		}
	//twoSAT.output();
	bool ok=twoSAT.check();
	if (!ok)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	auto ans=twoSAT.build();
	for (int i=0;i<m;i++)
		putchar(ans[i] ? 'i':'o');
}