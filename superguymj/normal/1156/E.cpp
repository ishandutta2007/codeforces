#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
typedef set <int> :: iterator it;
int n,ans,a[N],p[20][N],bin[N],id[N];
set <int> st[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int cmp(int x,int y) {return a[x]>a[y]?x:y;}

int merge(int x,int y,int mx)
{
	if(st[x].size()<st[y].size()) swap(x,y);
	for(it p=st[y].begin(); p!=st[y].end(); ++p)
		if(st[x].count(mx-*p)) ++ans;
	for(it p=st[y].begin(); p!=st[y].end(); ++p)
		st[x].insert(*p);
	st[x].insert(mx);
	return x;
}

int query(int l,int r)
{
	int B=bin[r-l+1];
	return cmp(p[B][l],p[B][r-(1<<B)+1]);
}

int dfs(int l,int r)
{
	if(l>r) return 0;
	if(l==r)
	{
		st[id[l]=l].insert(a[l]);
		return l;
	}
	int mid=query(l,r);
	return id[mid]=merge(dfs(l,mid-1),dfs(mid+1,r),a[mid]);
}

int main()
{
	n=getint();
	rep(i,1,n) p[0][i]=i,a[i]=getint();
	rep(i,2,n) bin[i]=bin[i>>1]+1;
	rep(i,1,bin[n]) rep(j,1,n-(1<<i)+1) p[i][j]=cmp(p[i-1][j],p[i-1][j+(1<<i-1)]);
	dfs(1,n);
	printf("%d\n",ans);
	return 0;
}