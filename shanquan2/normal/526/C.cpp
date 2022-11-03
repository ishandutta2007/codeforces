#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int c,hr,hb,wr,wb;
	scanf("%d%d%d%d%d",&c,&hr,&hb,&wr,&wb);
	if((long long)hr*wb<(long long)hb*wr){
		swap(hr,hb);swap(wr,wb);
	}
	int m=c/wr;
	long long ans=0;
	if(wb<=10000){
		for(int i=m;i>=m-wb && i>=0;i--){
			long long j=(c-i*wr)/wb;
			ans=max(ans,i*(long long)hr+j*(long long)hb);
		}
	}else{
		for(int i=0;i<=c/wb;i++){
			long long j=(c-i*wb)/wr;
			ans=max(ans,i*(long long)hb+j*(long long)hr);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}