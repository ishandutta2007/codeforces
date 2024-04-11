#include<bits/stdc++.h>
#define MAXN 10005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int n;
P a[MAXN];
set<P> s;
void solve(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	int midx=a[mid].F;
	for(int i=l;i<=r;i++)
		s.insert((P){midx,a[i].S});
	solve(l,mid);
	solve(mid+1,r);
	return;
}
int main()
{
	scanf("%d",&n);
	s.clear();
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].F,&a[i].S);
		s.insert(a[i]);
	}
	sort(a,a+n);
	solve(0,n-1);
	printf("%d\n",s.size());
	for(auto i=s.begin();i!=s.end();i++)
		printf("%d %d\n",(*i).F,(*i).S);
	return 0;
}