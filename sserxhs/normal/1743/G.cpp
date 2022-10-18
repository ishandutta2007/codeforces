//114514min
//ACM 
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt","sse3","sse2","sse","avx","sse4","sse4.1","sse4.2","ssse3","f16c","fma","avx2","xop","fma4")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=3e3+3,M=1e3+3,B=35;
const ui p=998244353;
void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
char s[N*M];
char *_s;
int len[N];
int main()
{
	_s=s;
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	// vector<string> F={"0","1"};
	// while (F.back().size()<N) F.push_back(F.back()+F[F.size()-2]);
	// dbg(F[9],F[10]);
	vector<int> fib={1,1};
	while (fib.back()<3'000'000) fib.push_back(fib.back()+fib[fib.size()-2]);
	fib.pop_back();
	function<bool(char *,int)> check=[&](char *s,int cs) -> bool
	{
		// cerr<<s-_s<<' '<<cs<<": \n";
		while (cs>2)
		{
			int i,n=fib[cs-2];
			char *t=s+fib[cs-1];
			for (i=0; i<n; i++) if (s[i]!=t[i]) return 0;
			--cs;
		}
		// cerr<<(cs==2?(s[0]=='1'&&s[1]=='0'):(s[0]=='0'+cs))<<'\n';
		return cs==2?(s[0]=='1'&&s[1]=='0'):(s[0]=='0'+cs);
	};
	int n,m=1,i,j,k;
	cin>>n;
	for (i=0; i<n; i++)
	{
		string t;
		cin>>t;
		int q=t.size();
		for (j=0; j<q; j++) s[j+m]=t[j];
		m+=q;
		len[i]=m-1;
	}
	vector<vector<int>> pos(fib.size());
	for (i=0; i<fib.size()&&fib[i]<=B; i++);
	for (j=m; j; j--) if (j+fib[i]-1<=m&&check(s+j,i)) pos[i].push_back(j);
	pos[i].shrink_to_fit();
	int L=i;
	auto find=[&](const vector<int> &v,int p)
	{
		auto it=lower_bound(all(v),p,greater<int>());
		return it!=v.end()&&*it==p;
	};
	for (k=i+1; k<fib.size(); k++)
	{
		if (k==i+1) { for (int x:pos[k-1]) if (check(s+x,k)) pos[k].push_back(x); }
		else
		{
			for (int x:pos[k-1]) if (find(pos[k-2],x+fib[k-1])) pos[k].push_back(x);
		}
		pos[k].shrink_to_fit();
		// cerr<<":: ";
		// cerr<<pos[4][0]+fib[4]<<endl;
	}
	// dbg(fib[3]);
	// dbg(fib[4]);
	k=5;
	// for (int x:pos[k-1]) dbg(find(pos[k-2],x+fib[k-1]));
	// dbg(pos[3],find(pos[3],6));
	// dbg(pos[5].size());
	map<int,ui> oth;
	--m;
	int id=0;
	ll S=1;
	deque<int> q;
	q.push_back(1);
	int shift=0;
	for (i=0; i<=m; i++)
	{
		ll cur=S+(ll)p*p;
		if (oth.size()&&oth.begin()->first==i)
		{
			cur-=oth.begin()->second;
			oth.erase(oth.begin());
		}
		j=0;
		for (int x:fib)
		{
			if (x<=B&&i>=x&&check(s+i-x+1,j)) cur-=q[i-x-shift];
			++j;
		}
		cur%=p;
		if (i)
		{
			(S+=cur)%=p;
			q.push_back(cur);
		}
		if (q.size()>B+2)
		{
			q.pop_front();
			++shift;
		}
		for (j=L; j<fib.size(); j++)
		{
			auto &v=pos[j];
			while (v.size()&&v.back()==i+1)
			{
				inc(oth[i+fib[j]],cur);
				v.pop_back();
			}
		}
		if (i==len[id])
		{
			++id;
			cout<<cur<<'\n';
		}
	}
}