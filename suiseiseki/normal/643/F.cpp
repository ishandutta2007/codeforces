#include <cstdio>
#include <algorithm>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
unsigned quick_power(unsigned a,int b){
	unsigned ans=1;
	while(b){
		if(b&1){
			ans*=a;
		}
		b>>=1;
		a*=a;
	}
	return ans;
}
const int Maxp=130;
unsigned C(int n,int m){
	static int lis_a[Maxp+5],lis_b[Maxp+5];
	int lis_a_len=0,lis_b_len=0;
	for(int i=n-m+1;i<=n;i++){
		lis_a[++lis_a_len]=i;
	}
	for(int i=1;i<=m;i++){
		lis_b[++lis_b_len]=i;
	}
	for(int i=1;i<=lis_a_len;i++){
		for(int j=1;j<=lis_b_len;j++){
			int t=gcd(lis_a[i],lis_b[j]);
			lis_a[i]/=t,lis_b[j]/=t;
		}
	}
	unsigned ans=1;
	for(int i=1;i<=lis_a_len;i++){
		ans*=lis_a[i];
	}
	return ans;
}
unsigned C_num[Maxp+5];
int main(){
	int n,p,q;
	scanf("%d%d%d",&n,&p,&q);
	int t=std::min(n-1,p);
	unsigned ans=0;
	for(int i=0;i<=t;i++){
		C_num[i]=C(n,i);
	}
	for(int i=1;i<=q;i++){
		unsigned tmp=1;
		unsigned sum=0;
		for(int j=0;j<=t;j++){
			sum+=C_num[j]*tmp;
			tmp*=i;
		}
		ans^=i*sum;
	}
	printf("%u\n",ans);
	return 0;
}