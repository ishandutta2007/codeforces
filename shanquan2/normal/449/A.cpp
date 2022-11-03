#include<cstdio>
#include<cmath>
using namespace std;

int max(int x,int y){
	return (x>y)?x:y;
}
int min(int x,int y){
	return (x<y)?x:y;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(k>n-1+m-1){
		printf("-1\n");
		return 0;
	}
	if(n>m){
		int t=n;n=m;m=t;
	}
	long long ans=0;
	for(int i=0;i<sqrt(n);i++){
		if(i>k)break;
		long long tmp=(long long)(n/(i+1))*(m/(k-i+1));
		if(tmp>ans)ans=tmp;
		if(n/(i+2)<=k){
			int x=min(n/(i+1)-1,k);
			tmp=(long long)(i+1)*(m/(k-x+1));
			if(tmp>ans)ans=tmp;
		}
	}
	if(ans==0)printf("-1\n");else printf("%I64d\n",ans);
	return 0;
}