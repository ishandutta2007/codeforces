#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=2e6+10;
typedef long long LL;

int n,m,pos;
LL h,ans;
int l[maxn];
vector<LL> v[maxn];
vector<LL> s[maxn];

void calc(int p)
{
	v[p].clear();
	if (p>n) return;
	v[p].push_back(0);
	
	calc(p*2);
	calc(p*2+1);
	
	int pos1=0,pos2=0;
	while(pos1<v[p*2].size() && pos2<v[p*2+1].size())
	{
		LL tmp1=v[p*2][pos1]+l[p*2],tmp2=v[p*2+1][pos2]+l[p*2+1];
		if (tmp1<tmp2)
		{
			v[p].push_back(tmp1);
			pos1++;
		}
		else
		{
			v[p].push_back(tmp2);
			pos2++;
		}
	}
	
	while(pos1<v[p*2].size())
	{
		v[p].push_back(v[p*2][pos1]+l[p*2]);
		pos1++;
	}
	while(pos2<v[p*2+1].size())
	{
		v[p].push_back(v[p*2+1][pos2]+l[p*2+1]);
		pos2++;
	}
	
	s[p].clear();
	s[p].push_back(0);
	for(int i=1;i<v[p].size();i++)
		s[p].push_back(s[p][i-1]+v[p][i]);
	return;
}

LL getsum(int pos,LL len)
{
	int tmp=upper_bound(v[pos].begin(),v[pos].end(),len)-v[pos].begin()-1;
	if (tmp<0) return 0ll;
	return len*(tmp+1)-s[pos][tmp];
}

int bro(int p)
{
	if (p&1) return p-1;
	else return p+1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
		scanf("%d",&l[i]);
	
	calc(1);
	while(m--)
	{
		scanf("%d%I64d",&pos,&h);
		ans=getsum(pos,h);
		while(pos>1)
		{
			int other=bro(pos);
			ans+=getsum(other,h-l[pos]-l[other]);
			if (h<l[pos]) break;
			h-=l[pos];
			pos=pos>>1;
			ans+=h;
		}
		
		printf("%I64d\n",ans);
	}
	return 0;
}