//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<typC,typD> &a)
{
	for (auto &x:a) cout<<x<<'\n';
	return cout;
}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	if (!n) return cout;
	cout<<a[0];
	for (i=1;i<n;i++) cout<<' '<<a[i];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+5;
int a[N],s[N],suf[N],b[N];
mt19937 rnd(time(0));
string ori;
vector<pair<int,int>> tp;
int flg;
void dfs(string s,int res)
{
	if (res==0) return;
	int n=s.size(),i=1,j=0;
	for (auto c:s) if ((j+=c=='('?1:-1)<0)
	{
		i=0;break;
	}
	if (i)
	{
		for (auto [x,y]:tp) dbg(x,y);
		dbg(ori);
		//flg=1;
		exit(0);
	}
	for (i=0;i<n;i++) for (j=i+2;j<=n;j++)
	{
		auto t=s;
		reverse(t.begin()+i,t.begin()+j);
		tp.push_back({i,j});
		dfs(t,res-1);
		tp.pop_back();
		//if (flg) return;
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string S;
		cin>>n>>S;
//n=rnd()%12+1;flg=0;
//S=string(n*2,'(');
//for (i=1;i<=n;i++)
//{
//	j=rnd()%(n*2);
//	while (S[j]==')') j=rnd()%(n*2);
//	S[j]=')';
//}
//ori=S;
		for (i=1;i<=n*2;i++) a[i]=S[i-1]=='('?1:-1;
		vector<pair<int,int>> ans;
		n<<=1;
		//for (i=1;i<=n;i++) cerr<<a[i]<<" \n"[i==n];
		for (i=1;i<=n;i++) b[i]=a[i];
		int cc=2;
		while (cc--)
		{
			for (i=1;i<=n;i++) s[i]=s[i-1]+a[i];
			suf[n+1]=0;
			for (i=n;i;i--) suf[i]=suf[i+1]+a[i];
			for (i=1;i<=n;i++) if (s[i]<0) break;
			if (i>n) break;
			for (j=n;j;j--) if (suf[j]>0) break;
			assert(j);
			int l=max_element(s,s+i+1)-s+1,r=min_element(suf+j,suf+n+2)-suf-1;
			assert(l<=i&&r>=j);
			ans.push_back({l,r});
			//dbgn(l,r);
			reverse(a+l,a+r+1);
			//for (i=1;i<=n;i++) cerr<<a[i]<<" \n"[i==n];
		}
		if (cc>=0)
		{	
			cout<<ans.size()<<'\n';
			for (auto [l,r]:ans) cout<<l<<' '<<r<<'\n';
			continue;
		}
		ans.clear();
		for (i=1;i<=n;i++) a[i]=b[i];
		for (i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		suf[n+1]=0;
		for (i=n;i;i--) suf[i]=suf[i+1]+a[i];
		i=min_element(suf+1,suf+n+2)-suf-1;
		ans.push_back({1,i});
		reverse(a+1,a+i+1);
		//for (i=1;i<=n;i++) cerr<<a[i]<<" \n"[i==n];
		for (i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		suf[n+1]=0;
		for (i=n;i;i--) suf[i]=suf[i+1]+a[i];
		i=max_element(s,s+n+1)-s+1;
		ans.push_back({i,n});
		reverse(a+i,a+n+1);
		for (i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		//for (i=1;i<=n;i++) cerr<<a[i]<<" \n"[i==n];
		assert(*min_element(s+1,s+n+1)>=0);
		cout<<ans.size()<<'\n';
		for (auto [l,r]:ans) cout<<l<<' '<<r<<'\n';
		//cout.flush();
//dfs(S,ans.size());
	}
}