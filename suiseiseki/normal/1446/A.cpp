#include <cstdio>
typedef long long ll;
const int Maxn=200000;
int n;
int w[Maxn+5],id[Maxn+5];
ll W;
int m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&W);
		int pos=-1;
		ll sum=0;
		m=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x<=W){
				w[++m]=x;
				id[m]=i;
				if(w[m]>=((W+1)>>1)){
					pos=i;
				}
				sum+=x;
			}
		}
		if(pos!=-1){
			printf("1\n%d\n",pos);
			continue;
		}
		if(sum<((W+1)>>1)){
			puts("-1");
			continue;
		}
		pos=m;
		while(pos>0&&sum>W){
			sum-=w[pos];
			pos--;
		}
		if(pos==0){
			puts("-1");
			continue;
		}
		printf("%d\n",pos);
		for(int i=1;i<=pos;i++){
			printf("%d ",id[i]);
		}
		puts("");
	}
	return 0;
}