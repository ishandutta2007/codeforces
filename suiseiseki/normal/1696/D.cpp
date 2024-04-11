#include <cstdio>
#include <algorithm>
const int Maxn=250000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int st[Maxn+5],st_top;
int pos[Maxn+5];
std::pair<int,int> val[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[i]=0;
	}
	st_top=0;
	val[0]=std::make_pair(Inf,n+1);
	for(int i=n;i>0;i--){
		while(st_top>0&&a[i]>a[st[st_top]]){
			val[st_top-1]=std::min(val[st_top-1],val[st_top]);
			st_top--;
		}
		pos[i]=std::max(pos[i],val[st_top].second);
		st[++st_top]=i,val[st_top]=std::make_pair(a[i],i);
	}
	st_top=0;
	val[0]=std::make_pair(0,n+1);
	for(int i=n;i>0;i--){
		while(st_top>0&&a[i]<a[st[st_top]]){
			val[st_top-1]=std::max(val[st_top-1],val[st_top]);
			st_top--;
		}
		pos[i]=std::max(pos[i],val[st_top].second);
		st[++st_top]=i,val[st_top]=std::make_pair(a[i],i);
	}
	int ans=0;
	for(int i=1;i<n;i=pos[i]){
		ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}