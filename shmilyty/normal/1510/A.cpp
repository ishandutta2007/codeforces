#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
struct node
{
	vector<string> v;
	int n,m;
};
void cob(node &res,node x)
{
	res.v[0].resize(res.m,' ');
	res.v[0]+=x.v[0];
	res.v[1]+=x.v[1];
	for(int i=res.n;i<x.n;i++)
		res.v.push_back("");
	for(int i=2;i<x.n;i++)
	{
		res.v[i].resize(res.m,' ');
		res.v[i]+=x.v[i];
	}
	res.n=max(res.n,x.n);
	res.m+=x.m;
}
node at(string s)
{
	node x;
	x.n=3;
	x.v.resize(3);
	x.v[0]="  +";	
	x.v[0].resize(s.size()+5,'-');
	x.v[0]+="+";
	x.m=x.v[0].size();
	x.v[1]="->+ ";
	x.v[1]+=s;
	x.v[1]+=" +";
	x.v[2]=x.v[0];
	return x;
}
node add(node x,char c)
{
	node res;
	res.m=x.m+6;
	x.v[1]+="->+";
	res.v.push_back("   ");
	res.v.push_back("->+");
	if(c=='+')
	{
		res.n=x.n+2;
		for(int i=2;i<=x.n;i++)
			res.v.push_back("  |");
		for(int i=0;i<x.n;i++)
			res.v[i]+=x.v[i];
		for(int i=2;i<=x.n;i++)
		{
			res.v[i].resize(res.m-1,' ');
			res.v[i]+="|";
		}
		res.v.push_back("  +<");
		res.v[x.n+1].resize(res.m-1,'-');
		res.v[x.n+1]+='+';
	}
	if(c=='?')
	{
		res.n=x.n+3;
		res.v[1].resize(res.m-2,'-');
		res.v[1]+=">+";
		for(int i=1;i<=2;i++)
			res.v.push_back("  |");
		res.v[3]+=x.v[0];
		for(int i=2;i<=3;i++)
		{
			res.v[i].resize(res.m-1,' ');
			res.v[i]+="|";
		}
		res.v.push_back("  +");
		for(int i=5;i<res.n;i++)
			res.v.push_back("   ");
		for(int i=1;i<x.n;i++)
			res.v[i+3]+=x.v[i];
	}
	if(c=='*')
	{
		res.n=x.n+5;
		res.v[1].resize(res.m-2,'-');
		res.v[1]+=">+";
		for(int i=1;i<=2;i++)
			res.v.push_back("  |");
		res.v[3]+=x.v[0];
		for(int i=2;i<=3;i++)
		{
			res.v[i].resize(res.m-1,' ');
			res.v[i]+="|";
		}
		res.v.push_back("  +");
		for(int i=5;i<res.n-1;i++)
			res.v.push_back("  |");
		for(int i=1;i<x.n;i++)
			res.v[i+3]+=x.v[i];
		for(int i=5;i<res.n-1;i++)
		{
			res.v[i].resize(res.m-1,' ');
			res.v[i]+='|';
		}
		res.v.push_back("  +<");
		res.v.back().resize(res.m-1,'-');
		res.v.back()+='+';
	}
	return res;
}
void print(node x)
{
	cout<<x.n<<" "<<x.m<<endl;
	for(string i:x.v)
		cout<<i<<endl;
	cout<<"--------------"<<endl;
}
node solve(string s)
{
	int cnt=0,ok=0;
	if(s[0]=='(')
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
				cnt++;
			if(s[i]==')')
				cnt--;
			if(!cnt)
			{
				if(i==s.size()-1)
					return solve(s.substr(1,s.size()-2));
				break;
			}
		}
	}
	string ss;
	node res;
	res.n=res.m=0;
	vector<int> pos;
	for(int i=0;i<s.size();i++)
		if(s[i]=='|'&&!cnt)
		{
			node x=solve(ss);
			if(ok)
			{
				res.v.push_back("  |"+x.v[0]);
				res.v.push_back("  +"+x.v[1]);
				pos.push_back(res.v.size());
			}
			else
			{
				res.v.push_back("   "+x.v[0]);
				res.v.push_back("->+"+x.v[1]);
				pos.push_back(res.v.size());
			}
			for(int i=2;i<x.n;i++)
				res.v.push_back("  |"+x.v[i]);
			res.n+=x.n+1;
			res.v.push_back("  |");
			res.m=max(res.m,x.m+6);
			ok=1;
			ss="";
		}
		else
		{
			ss+=s[i];
			if(s[i]=='(')
				cnt++;
			if(s[i]==')')
				cnt--;
		}
	// cout<<s<<" "<<ok<<endl;
	// print(res);
	if(!ss.empty()&&ok)
	{
		node x=solve(ss);
		res.v.push_back("  |"+x.v[0]);
		res.v.push_back("  +"+x.v[1]);
		pos.push_back(res.v.size());
		for(int i=2;i<x.n;i++)
			res.v.push_back("   "+x.v[i]);
		res.n+=x.n;
		res.m=max(res.m,x.m+6);
	}
	if(ok)
	{
		for(int i:pos)
		{
			res.v[i-1].resize(res.m-2,'-');
			res.v[i-1]+=">+";
		}
		for(int i=2;i<pos.back()-1;i++)
			if(res.v[i].size()!=res.m)
			{
				res.v[i].resize(res.m-1,' ');
				res.v[i]+="|";
			}
		return res;
	}
	res.n=2;
	res.v.resize(2);
	ss="";
	for(int i=0;i<s.size();i++)
		if(s[i]=='(')
		{
			cnt=1;
			ss="(";
			for(i++;cnt;i++)
			{
				ss+=s[i];
				if(s[i]=='(')
					cnt++;
				if(s[i]==')')
					cnt--;
			}
			// cout<<ss<<endl;
			node x=solve(ss);
			for(;i<s.size();i++)
				if((s[i]>='A'&&s[i]<='Z')||s[i]=='(')
				{
					i--;
					break;
				}
				else
					x=add(x,s[i]);
			// print(x);
			cob(res,x);
			// cout<<"kuhao"<<endl;
			// print(res);
			ss="";
		}
		else
		{
			for(;i<s.size()&&s[i]>='A'&&s[i]<='Z';i++)
				ss+=s[i];
			// cout<<"ss: "<<ss<<endl;
			// cout<<s<<endl;
			if(i==s.size()||s[i]=='(')
			{
				node x=at(ss);
				// puts("114514");
				cob(res,x);
				i--;
			}
			else
			{
				node x=at(ss.substr(0,ss.size()-1)),y=at(ss.substr(ss.size()-1));
				for(;i<s.size();i++)
					if((s[i]>='A'&&s[i]<='Z')||s[i]=='(')
					{
						i--;
						break;
					}
					else
						y=add(y,s[i]);
				if(ss.size()==1)
					cob(res,y);
				else
				{
					cob(x,y);
					cob(res,x);
				}
			}
			// print(res);
			ss="";
		}
	// cout<<s<<endl;
	// print(res);
	return res;
}
signed main()
{
	string s;
	cin>>s;
	node x=solve(s);
	x.m+=3;
	cout<<x.n<<" "<<x.m+1<<'\n';
	for(int i=0;i<x.n;i++)
	{
		if(i==1)
			cout<<"S"<<x.v[i]<<"->F"<<'\n';
		else
		{
			x.v[i].resize(x.m,' ');
			cout<<" "<<x.v[i]<<'\n';
		}
	}
	// print(solve("NE?(ER)C++|(IS)*?|(CHA((LL))ENGING)"));
	// print(solve("(IS)*?"));
	// print(solve("(CHA((LL))ENGING)"));
	// print(solve("(IS)*?|(CHA((LL))ENGING)"));
/*
	node y=at("123");
	node z=add(y,'?');
	print(add(z,'*'));*/
	/*print(y);
	print(add(y,'+'));
	print(z);
	print(add(z,'?'));
	print(add(add(y,'+'),'?'));*/
	/*string s;
	cin>>s;
	solve(s);*/
	return 0;
}