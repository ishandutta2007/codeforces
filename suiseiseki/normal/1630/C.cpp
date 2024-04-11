#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n;
int a[Maxn+5];
int pos[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	int cur=-1,nxt=-1;
	int ans=n;
	for(int i=1;i<=n;i++){
		if(i>nxt){
			cur=nxt=i;
			ans--;
		}
		if(i>cur){
			cur=nxt;
			ans--;
		}
		nxt=std::max(nxt,pos[a[i]]);
	}
	printf("%d\n",ans);
	return 0;
}