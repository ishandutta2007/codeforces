#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mp make_pair
#define pb push_back

using namespace std;
const int N=200005,mod=998244353,B=19260817;
typedef long long LL;
typedef map<pair<int,int>,vector <int>>::iterator it;
char s[N];
int n,ans;
LL bin[N],hsh[N],val[N];
map<pair<int,int>,vector <int>> f[N];

LL get(int l,int r)
{
	return (hsh[r]-hsh[l-1]*bin[r-l+1]%mod+mod)%mod;
}

int main()
{
	scanf("%d%s",&n,s+1);
	bin[0]=1;
	rep(i,1,n) bin[i]=bin[i-1]*B%mod,hsh[i]=(hsh[i-1]*B+s[i])%mod;
	rep(i,1,n) f[1][mp(s[i],1)].pb(i);
	rep(i,1,n) if(!f[i].empty())
	{
		ans=i;
		for(it p=f[i].begin(); p!=f[i].end(); ++p)
		{
			vector <int> a=p->second;
			int len=p->first.second,sz=a.size();
			rep(j,0,sz-2)
				val[j]=get(a[j]+len,a[j+1]-1);
			for(int l=0,r=1; l<sz-1; l=r,++r)
			{
				while(r<sz-1 && val[r-1]==val[r]) ++r;
				f[i+r-l][mp(get(a[l],a[r]+len-1),a[r]-a[l]+len)].pb(a[l]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}