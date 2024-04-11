#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		vector<vector<int>>a(n+2,vector<int>(m+2));
		set<int>s;
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=m;++j){
				scanf("%d",&a[i][j]);
				if(j>1&&a[i][j]<a[i][j-1])s.insert(j);
			}
		auto check=[&](){
			for(ri i=1;i<=n;++i)
				for(ri j=2;j<=m;++j)
					if(a[i][j]<a[i][j-1])
						return false;
			return true;
		};
		if(check())puts("1 1");
		else{
			auto b=a;
			set<int>s;
			for(ri i=1;i<=n;++i){
				sort(b[i].begin()+1,b[i].begin()+m+1);
				for(ri j=1;j<=m;++j)
					if(a[i][j]!=b[i][j])
						s.insert(j);
			}
			if(s.size()>2)puts("-1");
			else{
				for(ri i=1;i<=n;++i)swap(a[i][*s.begin()],a[i][*s.rbegin()]);
				if(check())printf("%d %d\n",*s.begin(),*s.rbegin());
				else puts("-1");
			}
		}
		skip:;
	}
	return 0;
}