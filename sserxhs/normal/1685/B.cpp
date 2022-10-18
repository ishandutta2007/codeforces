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
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		vector<int> cnt(4),cc(2);
		vector<vector<int>> tp(3);
		for (int &x:cnt) cin>>x;
		for (i=0;i<2;i++) cc[i]=cnt[i]+cnt[2]+cnt[3];
		string s;
		cin>>s;
		for (auto c:s) --cc[c-'A'];
		if (cc[0]||cc[1]) {cout<<"NO\n";continue;}
		n=s.size();
		for (i=j=0;i<n;i=j)
		{
			while (j<n&&(j-i&1)==(s[j]-s[i]&1)) ++j;
			int sz=j-i;
			if (sz&1) tp[2].push_back(sz); else tp[s[i]-'A'].push_back(sz);
		}
		//for (i=0;i<=2;i++) dbg(tp[i]);
		for (i=0;i<2;i++)
		{
			cnt[i]=cnt[i+2];
			sort(all(tp[i]));reverse(all(tp[i]));
			auto &v=tp[i];
			while (cnt[i]>0&&v.size())
			{
				int dt=min((int)v.back()>>1,cnt[i]);
				if (dt==cnt[i])
				{
					cnt[i]=0;
					v.back()-=dt*2;
					if (!v.back()) v.pop_back();
					break;
				}
				else cnt[i]-=dt,v.pop_back();
			}
			for (int &x:v) x=x-2>>1;
		}
		for (int &x:tp[2]) x>>=1;
		for (i=0;i<2;i++) if (cnt[i])
		{
			for (int &v:tp[i^1])
			{
				int dt=min(v,cnt[i]);
				cnt[i]-=dt;v-=dt;
			}
			for (int &v:tp[2])
			{
				int dt=min(v,cnt[i]);
				cnt[i]-=dt;v-=dt;
			}
			if (cnt[i]) break;
		}
		if (i==2) cout<<"YES\n"; else cout<<"NO\n";
	}
}