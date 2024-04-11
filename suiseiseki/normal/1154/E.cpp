#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
int a[Maxn+5];
int ans[Maxn+5];
set<pair<int,int> > st;
int nxt[Maxn+5],pre[Maxn+5];
int find_nxt(int x){
	if(x==nxt[x]){
		return x;
	}
	return nxt[x]=find_nxt(nxt[x]);
}
int find_pre(int x){
	if(x==pre[x]){
		return x;
	}
	return pre[x]=find_pre(pre[x]);
}
void merge_nxt(int x,int y){
	int fa_x=find_nxt(x),fa_y=find_nxt(y);
	if(fa_x==fa_y){
		return;
	}
	nxt[fa_x]=fa_y;
}
void merge_pre(int x,int y){
	int fa_x=find_pre(x),fa_y=find_pre(y);
	if(fa_x==fa_y){
		return;
	}
	pre[fa_x]=fa_y;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		st.insert(make_pair(a[i],i));
	}
	for(int i=1;i<=n;i++){
		nxt[i]=pre[i]=i;
	}
	nxt[n+1]=pre[n+1]=n+1;
	int tag=0,now;
	for(int i=1;tag<n;i++){
		now=(--st.end())->second;
		merge_pre(now,now-1);
		merge_nxt(now,now+1);
		tag++;
		ans[now]=(i&1);
		st.erase(make_pair(a[now],now));
		for(int j=find_pre(now),l=1;l<=k&&j!=0;j=find_pre(j),l++){
			merge_pre(j,j-1);
			merge_nxt(j,j+1);
			tag++;
			ans[j]=(i&1);
			st.erase(make_pair(a[j],j));
		}
		for(int j=find_nxt(now),l=1;l<=k&&j<=n;j=find_nxt(j),l++){
			merge_pre(j,j-1);
			merge_nxt(j,j+1);
			tag++;
			ans[j]=(i&1);
			st.erase(make_pair(a[j],j));
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==0){
			putchar('2');
		}
		else{
			putchar('1');
		}
	}
	puts("");
	return 0;
}