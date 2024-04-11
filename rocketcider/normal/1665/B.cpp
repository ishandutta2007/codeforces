#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
inline int calc(int x,int y){
	int ret=0;
	while(y<x)y<<=1,++ret;
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		map<int,int>cnt;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),++cnt[a[i]];
		int ans=INT_MAX;
		for(const auto &i:cnt)ckmin(ans,n-i.second+calc(n,i.second));
		printf("%d\n",ans);
	}
	return 0;
}