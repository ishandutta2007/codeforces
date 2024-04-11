#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
char s[N];
int n;
vector <int> shift;

void solve()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	shift.clear();
	int tp=0;
	rep(i,1,n)
	{
		int x=i*2-1,y=i*2;
		if(s[x]==s[y]) continue;
		if(s[x]-48==tp) shift.push_back(x);
		else shift.push_back(y);
		tp^=1;
	}
	if(shift.size()&1) {puts("-1"); return;}
	printf("%d\n",(int)shift.size());
	for(auto x:shift) printf("%d ",x);
	puts("");
	rep(i,1,n) printf("%d ",i*2);
	puts("");
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}