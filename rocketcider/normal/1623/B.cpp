#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],id[maxn],m,n,t_case,st[maxn],tp,x[maxn],y[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
set<pii>s;
inline bool check(int l,int r){
	if(l>r)return true;
	return s.count({l,r});
}
void dfs(int l,int r){
	if(l==r){
		printf("%d %d %d\n",l,l,l);
		return;
	}
	if(l>r)return;
	for(ri i=l;i<=r;++i)
		if(check(l,i-1)&&check(i+1,r)){
			printf("%d %d %d\n",l,r,i);
			dfs(l,i-1),dfs(i+1,r);
			return;
		}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		s.clear();
		for(ri i=1;i<=n;++i){
			scanf("%d%d",x+i,y+i);
			s.insert({x[i],y[i]});
		}
		dfs(1,n);
	}
	return 0;
}