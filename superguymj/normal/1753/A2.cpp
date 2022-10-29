#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back
#define mp make_pair

using namespace std;
const int N=200005;
int n,a[N];
bool jdg;
vector <pair <int,int>> ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		ans.clear();
		int tot=0;
		rep(i,1,n) tot+=a[i];
		if(tot&1)
		{
			puts("-1");
			continue;
		}
	
		for(int l=1,r; l<=n; l=r+1)
		{
			r=l;
			if(!a[l]) ans.pb(mp(l,l));
			else
			{
				++r;
				while(!a[r]) ++r;
				if(a[l]!=a[r]) ans.pb(mp(l,r-1)),ans.pb(mp(r,r));
				else if((r-l)&1) ans.pb(mp(l,r));
				else ans.pb(mp(l,l)),ans.pb(mp(l+1,r));
			}
		}
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d %d\n",x.first,x.second);
	}
	return 0;
}