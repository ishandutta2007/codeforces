#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
template<typename typC,int N> struct bit
{
	typC a[N];
	int n;
	bit()
	{
		memset(a,0,sizeof a);
	}
	void init(int nn)
	{
		n=nn;
		memset(a+1,0,n*sizeof a[0]);
	}
	void mdf(int x,typC y)
	{
		++x;
		//cout<<x<<' '<<y<<endl;
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		++x;
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
bit<int,100005> s1;
vector<int> ps[26];
int tot[26];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,i,j;
		ll ans=1e18,now=0;
		string s,t,sss;
		cin>>n>>s>>t;sss=s;s1.init(n+1);
		//if (s<t) {cout<<"0\n";continue;}
		sort(all(sss));
		if (sss>=t) {cout<<"-1\n";continue;}
		for (i=0;i<26;i++) ps[i].clear();
		for (i=0;i<n;i++) ps[s[i]-='a'].push_back(i),t[i]-='a';
		memset(tot,0,sizeof tot);
		for (i=0;i<n;i++)
		{
			for (j=0;j<t[i];j++) if (ps[j].size()>tot[j])
			{
				int x=s1.sum(ps[j][tot[j]]);
				//if (i>ps[j][tot[j]]+x) cout<<i<<' '<<j<<endl;
				assert(i<=ps[j][tot[j]]+x);
				ans=min(ans,now+ps[j][tot[j]]+x-i);
			}
			++tot[j=t[i]];
			if (ps[j].size()>=tot[j])
			{
				int x=s1.sum(ps[j][tot[j]-1]);
				assert(i<=ps[j][tot[j]-1]+x&&ps[j][tot[j]-1]+x<n);
				now+=ps[j][tot[j]-1]+x-i;
				s1.mdf(0,1);s1.mdf(ps[j][tot[j]-1]+1,-1);
			}
			else break;
			//cout<<now<<'\n';
		}
		cout<<ans<<'\n';
	}
}