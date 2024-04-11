#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int K=20;
int n,k;

struct data
{
	int sz,mn[K],mx[K];

	bool operator < (const data &t) const
	{
		rep(i,1,k) if(mx[i]>t.mn[i]) return 0;
		return 1;
	}
} p;

set <data> st;
typedef set <data> :: iterator it;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint(),k=getint();
	rep(i,1,n)
	{
		p.sz=1;
		rep(j,1,k) p.mn[j]=p.mx[j]=getint();
		it x=st.lower_bound(p),y=st.upper_bound(p);
		while(x!=y)
		{
			rep(j,1,k) p.mn[j]=min(p.mn[j],x->mn[j]),p.mx[j]=max(p.mx[j],x->mx[j]);
			p.sz+=x->sz,st.erase(x++);
		}
		st.insert(p);
		printf("%d\n",st.rbegin()->sz);
	}
	return 0;
}